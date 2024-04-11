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
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

struct seg {
	int l, r, val;

	bool operator<(const seg & S) const {
		return l < S.l;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,Q;
	string A;
	cin >> N >> Q >> A;
	// vector<char> E(N, 0);
	// for(int i = 1; i < N; i++) E[i] = (A[i] == A[i-1]);
	vector<seg> B;
	for(int i = 1, last = 0; i <= N; i++) if(i == N || A[i] == A[i-1]) {
		B.push_back({.l = last, .r = i-1, .val = A[i-1]-'0'});
		last = i;
	}
	vector<int> cnt[3];
	for(int k = 0; k < 3; k++) {
		cnt[k].resize(B.size()+1, 0);
		for(int i = 0; i < (int)B.size(); i++) {
			if((B[i].r-B[i].l)%2 != 0)
				cnt[k][i+1] = cnt[k][i] + (k == 2);
			else
				cnt[k][i+1] = cnt[k][i] + ((k != 2) ? A[B[i].l] == '0'+k : 0);
		}
	}
	for(int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int n[3] = {0, 0, 0};
		auto it_l = lower_bound(begin(B), end(B), seg{.l = l, .r = 0, .val = 0});
		if(it_l == end(B) || it_l->l > r) {
			cout << "1\n";
			continue;
		}
		if(it_l->r > r) {
			cout << ((it_l->l == l) ? "1\n" : "2\n");
			continue;
		}
		auto it_r = lower_bound(begin(B), end(B), seg{.l = r+1, .r = 0, .val = 0});
		it_r--;
		if(it_r->r > r) it_r--;
		if(it_l->l > l) {
			int len = it_l->l-l, val = A[l]-'0';
			if(len%2 == 0) n[2]++;
			else n[val]++;
		}
		for(int k = 0; k < 3; k++)
			n[k] += cnt[k][it_r-begin(B)+1] - cnt[k][it_l-begin(B)];
		if(it_r->r < r) {
			int len = r-it_r->r, val = A[r]-'0';
			if(len%2 == 0) n[2]++;
			else n[val]++;
		}
		// n[0] = n[1] = n[2] = 0;
		// for(int j = l+1, b = l&1; j <= r+1; j++) if(j == r+1 || E[j]) {
		// 	char v = b^(j&1);
		// 	if(v) {
		// 		if(A[j-1] == '1') n[1]++;
		// 		else n[0]++;
		// 	}
		// 	else n[2]++;
		// 	b = j&1;
		// }
		// cout << l << " " << r << " " << n[0] << " " << n[1] << " " << n[2] << " ";
		if(A[l] == '1' && A[r] == '1' && n[0] >= n[1]) n[2] += 2;
		if(A[l] == '0' && A[r] == '0' && n[0] <= n[1]) n[2] += 2;
		cout << max(n[0], n[1]) + (n[2]+1) / 2 << "\n";
	}
}

// look at my code
// my code is amazing