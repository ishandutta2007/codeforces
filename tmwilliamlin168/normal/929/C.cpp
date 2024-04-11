/// In The Name Of God

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n[4];
vector <int> a[4];

ll cnk(ll x, ll y) {
	if (x < y) return 0;
	ll res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i;
	}
	for (int i = 2; i <= y; i++) {
		res /= i;
	}
	return res;
}
int get(int id, int l, int r) {
	return upper_bound(all(a[id]), r) - lower_bound(all(a[id]), l);
}
int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	for (int i = 1; i <= 3; i++) {
		cin >> n[i];
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n[i]; j++) {
			int x;
			cin >> x;
			a[i].pb(x);
		}
		sort(all(a[i]));
	}
	ll res = 0;
	for (auto it : a[1]) {
		ll l = it + 1, r = it * 2;
		res += cnk(get(2, l, r), 2) * cnk(get(3, l, r), 3);
	}
	for (auto it : a[2]) {
		ll l = it + 1, r = it * 2;
		res += get(1, l, r) * get(2, l, r) * cnk(get(3, l, r), 3);
	}
	for (auto it : a[3]) {
		ll l = it + 1, r = it * 2;
		res += cnk(get(2, l, r), 2) * cnk(get(3, l, r), 2) * get(1, l, r);
	}
	cout << res;
	ioi
}