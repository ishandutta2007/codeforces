#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define _1 first
#define _2 second

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n, k; cin >> n >> k;
		vl stat((1 << n)+2, 0);
		REP(i, k) {
			ll p; cin >> p;
			stat[p] = 1;
		}

		ll init = 0;
		FOR(i, 1, (1<<n-1)) if (stat[2*i]|stat[2*i-1]) init++;

		ll tot = (1<<n);
		vvl dp(tot << 2, vl(4, -1e9));
		dbg(tot);

		REP(i, tot>>2) {
			ll cnt = 0;
			FOR(j, i*4+1, i*4+4) cnt += stat[j];

			ll pos = i+(tot>>2);
			if (cnt == 0) dp[pos][0] = 0; 
			if (cnt == 1) dp[pos][2] = 1, dp[pos][1] = 2;
			if (cnt >= 2) dp[pos][3] = 3;

			dbg(cnt, pos);
		}

		ROF(i, (tot>>2)-1, 1) {
			REP(j1, 4) REP(j2, 4) {
				ll s2 = (j1&1)+(j2&1),
					s1 = j1/2+j2/2;
				ll offset = dp[i*2][j1]+dp[i*2+1][j2];
				// dbg(j1, j2, s1, s2);

				if (s1 == 0) {
					chkmax(dp[i][0], offset);
					if (s2) chkmax(dp[i][1], offset+2);
				}
				if (s1 == 1) {
					if (s2 == 0) chkmax(dp[i][2], offset+1), chkmax(dp[i][1], offset+2);
					else chkmax(dp[i][3], offset+3);
				}
				if (s1 == 2) {
					chkmax(dp[i][3], offset+2);
					if (s2) chkmax(dp[i][3], offset+3);
				}
			}
		}

		// REP(i, tot>>1) {
		// 	dbg(dp[i]);
		// }

		ll ans = 0;
		REP(i, 4) chkmax(ans, dp[1][i]);
		dbg(ans, init);
		if (k == 0) ans--;
		cout << ans+1 + init << endl;
	}
    return 0;
}