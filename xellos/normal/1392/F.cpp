// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat search(cat a, cat b) {
	// max d : d(d+1)/2+b*d <= a
	cat d_l = 0, d_r = 2000000;
	while(d_r-d_l > 1) {
		cat d_m = (d_l+d_r)/2;
		if(d_m*b+d_m*(d_m+1)/2 <= a) d_l = d_m;
		else d_r = d_m;
	}
	return d_l;
}

struct BinSeqCompr {
	vector< pair<int, int> > seq;
	bool err = false;

	void add(int b, int cnt) {
		if(cnt < 0) err = true;
		if(cnt == 0) return;
		if(seq.empty() || seq.back().ff != b) seq.push_back({b, cnt});
		else seq.back().ss += cnt;
	}

	void remove(int b, int cnt) {
		if(cnt == 0) return;
		if(seq.empty() || b != seq.back().ff || cnt < 0 || cnt > seq.back().ss) err = true;
		seq.back().ss -= cnt;
		if(seq.back().ss == 0) seq.pop_back();
	}

	int get_last_bit() { return seq.back().ff; }

	int get_val(int index_from_end) { return seq[seq.size()-1-index_from_end].ss; }

	bool empty() { return seq.empty(); }

	int size() { return seq.size(); }

	vector<int> to_list() {
		vector<int> ret;
		for(int i = 0; i < (int)seq.size(); i++)
			for(int j = 0; j < seq[i].ss; j++) ret.push_back(seq[i].ff);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat h, h_cur;
	cin >> N >> h;
	BinSeqCompr seq;
	for(int i = 0; i < N-1; i++) {
		cin >> h_cur;
		while(!seq.empty()) {
			// post. a-krat 0 predtym 1
			// presuniem 1+2+...+a = a(a+1)/2 z h_cur do kopy
			cat a = seq.get_val(0);
			if(seq.get_last_bit() == 0 && a+a*(a+1LL)/2LL <= h_cur-h-1) {
				h += a;
				h_cur -= a*(a+1)/2;
				seq.remove(0, a);
				seq.add(1, a);
				continue;
			}
			// post. a-krat 1 predtym b-krat 0
			// h0, h0, h0+1, ..., h0+a, h_cur
			// presuniem 1 na kazde
			// h0, h0+1, h0+2, ..., h0+a+1, h_cur-1
			// h++, h_cur -= a+1, potom a++, b--
			// zopakujem b-krat
			// h += b
			// h_cur -= a+1 + a+2 + ... + a+b == a*b+b(b+1)/2
			if(seq.size() < 2) break;
			cat b = seq.get_val(1);
			if(seq.get_last_bit() == 1 && a*b+b*(b+1)/2+b <= h_cur-h-1) {
				h += b;
				h_cur -= a*b+b*(b+1)/2;
				seq.remove(1, a);
				seq.remove(0, b);
				seq.add(1, a+b);
				continue;
			}
			break;
		}
		while(!seq.empty()) {
			cat a = seq.get_val(0);
			if(seq.get_last_bit() == 0) {
				// h_cur -= 1: zmenim poslednu 0 na 1
				// h_cur -= 2: zmenim predposlednu 0 na 1
				// atd ak h += d, h_cur -= d(d+1)/2 tak z poslednych d 0 spravim 1
				cat d = search(h_cur-h-1, 1);
				h_cur -= d*(d+1)/2;
				h += d;
				seq.remove(0, d);
				seq.add(1, d);
				// potom h_cur--, zmenim 01111 na 10111, nezmenim tym h
				// az kym h_cur-h <= 1
				// h_cur-h-1 jednotiek zo zaciatku prave pridaneho presuniem
				if(d == 0) break;
				cat d2 = h_cur-h-1;
				if(d2) {
					h_cur -= d2;
					seq.remove(1, d);
					seq.remove(0, 1);
					seq.add(1, d2);
					seq.add(0, 1);
					seq.add(1, d-d2);
				}
				continue;
			}
			if(seq.get_last_bit() == 1 && seq.size() == 1) {
				// h++, h_cur -= a+1 spravim (h_cur-h-1)/(a+2) krat
				cat d = (h_cur-h-1)/(a+2);
				h += d;
				h_cur -= d*(a+1);
				cat d2 = h_cur-h-1;
				if(d2) {
					// 11111 -> 01111 -> 10111 -> 11011 ...
					d2 = min(d2, a);
					seq.remove(1, a);
					seq.add(1, d2-1);
					seq.add(0, 1);
					seq.add(1, a-d2);
					h_cur -= d2;
				}
				if(d == 0 && d2 == 0) break;
				continue;
			}
			if(seq.get_last_bit() == 1 && seq.size() > 1) {
				// b-krat 0, potom a-krat 1
				// 000011111 -> 000111111
				// h++, h_cur -= a+1
				// d: h += d, h_cur -= a*d+d(d+1)/2
				cat d = search(h_cur-h-1, a+1);
				h += d;
				h_cur -= a*d+d*(d+1)/2;
				seq.remove(1, a);
				seq.remove(0, d);
				seq.add(1, a+d);
				a += d;
				if(d) continue;
				// 000011111 -> 000101111 -> 000110111 -> ...
				cat d2 = min(a, h_cur-h-1);
				if(d2) {
					seq.remove(1, a);
					seq.remove(0, 1);
					seq.add(1, d2);
					seq.add(0, 1);
					seq.add(1, a-d2);
					h_cur -= d2;
					continue;
				}
				break;
			}
			break;
		}
		while(h_cur-h > 1) {
			if(seq.empty()) {
				cat d = (h_cur-h)/2;
				h += d;
				h_cur -= d;
				break;
			}
			h_cur--;
			if(seq.get_last_bit() == 0) {
				seq.remove(0, 1);
				seq.add(1, 1);
				h++;
			}
			else {
				cat a = seq.get_val(0);
				seq.remove(1, a);
				if(seq.empty()) {
					seq.add(0, 1);
					seq.add(1, a-1);
				}
				else {
					seq.remove(0, 1);
					seq.add(1, 1);
					seq.add(0, 1);
					seq.add(1, a-1);
				}
			}
		}
		seq.add(h_cur-h, 1);
		h = h_cur;
		if(seq.err) return 1;
	}
	vector<int> difs = seq.to_list();
	vector<cat> ans(N);
	ans[N-1] = h;
	for(int i = N-2; i >= 0; i--) ans[i] = ans[i+1]-difs[i];
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing