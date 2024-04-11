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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

// bool overlap(auto & p1, auto & p2, auto & p3, auto & p4) {
// 	// do [p1,p2] and [p3,p4] overlap?
// 	if(max(min(p1.ff, p2.ff), min(p3.ff, p4.ff)) > min(max(p1.ff, p2.ff), max(p3.ff, p4.ff))) return false;
// 	if(max(min(p1.ss, p2.ss), min(p3.ss, p4.ss)) > min(max(p1.ss, p2.ss), max(p3.ss, p4.ss))) return false;
// 	return true;
// }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int P;
	cin >> P;
	vector< pair<int, pair<int, int> > > I_v, I_h;
	bool has_r = 0;
	for(int i = 0; i < P; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1+y1 > x2+y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		while(x2+y2 > x1+y1) {
			int b = 0;
			while(!((x2>>b)&1) && !((y2>>b)&1)) b++;
			int d = min(x2+y2-x1-y1, 1<<b);
			if((x2>>b)&1) {
				I_h.push_back({y2, {x2-d+1, x2}});
				x2 -= d;
			}
			else {
				I_v.push_back({x2, {y2-d+1, y2}});
				y2 -= d;
			}
		}
		while(x1 != x2 || y1 != y2) {
			int bx1 = 0, bx2 = 0, by1 = 0, by2 = 0;
			while(bx1 < 30 && !((x1>>bx1)&1)) bx1++;
			while(bx2 < 30 && !((x2>>bx2)&1)) bx2++;
			while(by1 < 30 && !((y1>>by1)&1)) by1++;
			while(by2 < 30 && !((y2>>by2)&1)) by2++;
			int b1 = max(bx1, by1);
			int b2 = max(bx2, by2);
			int l1 = (x1|y1) & ((1<<b1)-1);
			int l2 = (x2|y2) & ((1<<b2)-1);
			int l = min(l1, l2);
			if((x1-1)&y1) {
				I_v.push_back({x1, {y1-l+1, y1}});
				y1 -= l;
			}
			else {
				I_h.push_back({y1, {x1-l+1, x1}});
				x1 -= l;
			}
			if((x2-1)&y2) {
				I_v.push_back({x2, {y2-l+1, y2}});
				y2 -= l;
			}
			else {
				I_h.push_back({y2, {x2-l+1, x2}});
				x2 -= l;
			}
		}
		if(x1+y1 == 0) has_r = 1;
		else if((x1-1)&y1) I_v.push_back({x2, {y2, y2}});
		else I_h.push_back({y2, {x2, x2}});
	}
	vector<int> sw;
	sort(begin(I_v), end(I_v));
	for(int i = 0; i < (int)I_v.size(); i++) if(i == 0 || I_v[i-1].ff != I_v[i].ff) {
		int l = I_v[i].ss.ff, r = I_v[i].ss.ss;
		for(int j = i+1; j < (int)I_v.size(); j++) {
			if(I_v[j].ff != I_v[i].ff) break;
			if(I_v[j].ss.ff <= r+1) {
				r = max(r, I_v[j].ss.ss);
				continue;
			}
			sw.push_back(I_v[i].ff+l);
			sw.push_back(I_v[i].ff+r+1);
			l = I_v[j].ss.ff;
			r = I_v[j].ss.ss;
		}
		sw.push_back(I_v[i].ff+l);
		sw.push_back(I_v[i].ff+r+1);
	}
	sort(begin(I_h), end(I_h));
	for(int i = 0; i < (int)I_h.size(); i++) if(i == 0 || I_h[i-1].ff != I_h[i].ff) {
		int l = I_h[i].ss.ff, r = I_h[i].ss.ss;
		for(int j = i+1; j < (int)I_h.size(); j++) {
			if(I_h[j].ff != I_h[i].ff) break;
			if(I_h[j].ss.ff <= r+1) {
				r = max(r, I_h[j].ss.ss);
				continue;
			}
			sw.push_back(I_h[i].ff+l);
			sw.push_back(I_h[i].ff+r+1);
			l = I_h[j].ss.ff;
			r = I_h[j].ss.ss;
		}
		sw.push_back(I_h[i].ff+l);
		sw.push_back(I_h[i].ff+r+1);
	}
	if(has_r) sw.push_back(1);
	sort(begin(sw), end(sw));
	int ans = 0;
	for(int i = 0; i < (int)sw.size(); i++) if(i == 0 || sw[i] != sw[i-1]) {
		int cnt = 0;
		for(int j = i; j < (int)sw.size(); j++) {
			if(sw[j] != sw[i]) break;
			cnt++;
		}
		ans += cnt&1;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing