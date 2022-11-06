//This is getting accepted!
// I HATE BUG
// God Of The Bugs
// 12/11/2016
#include<bits/stdc++.h>

using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll
#define ld long double

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
template<class T> T sqr(T x) { return x * x; }

inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

int fen[MAXN + 5], a[MAXN], has[MAXN], n, k;

void updateBIT(int u, int val) {
	while (u < MAXN) {
		fen[u] += val;
		u += (u & -u);
	}
}

int getBIT(int u) {
	int res = 0;
	if (u <= 0) return 0;
	while (u) {
		res += fen[u];
		u -= (u & -u);
	}
	return res;
}

int check(int u) {
//	cout << u << endl;
	int cur = 0;
	ms(fen, 0);
	for (int i=k-1; i<n; i++) {
		while (cur < i && a[i] - a[cur] > u) {
			cur++;
		}
//		if (u == 65) cout << i << " "  << cur << endl;
		if (i - cur + 1 < k) {
			has[i] = 0;
			continue;
		}
		else {
			int find = getBIT(i - k + 1) - getBIT(cur - 1);
			has[i] = (find > 0 || cur == 0);
		}
		updateBIT(i + 1, has[i]);
	}
	
	return has[n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

	cin >> n >> k;

	for (int i=0; i<n; i++) scanf("%d", a + i);

	int l = 0, r = 1e9, find = -1;
	
	sort(a, a + n);
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		int cur = 0;
		if (check(mid)) {
			find = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	assert(find != -1);
	cout << find << '\n';

	return 0;
}