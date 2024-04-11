#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
		ll n, k; scanf("%d%d", &n, &k);
		ll dist[n+2][n+2] = {0};
		FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &dist[i][j]);
		
		ll ans = 2e9;

		const ll ROUND = 512 * 20; 
		vl col(n+2);
		ll dp[n+2][k+1];
		// vvl dp(n+2, vl(k+1));
		REP(kk, ROUND) {
			// REP(i, n+2) REP(j, k+1) dp[i][j] = 1e18;
			// FILL(dp, 0x5f);
			REP(i, n+2) REP(j, k+1) dp[i][j] = 1e9+2;
			REP(i, n+2) col[i] = uid(0, 1); dp[1][0] = 0;
			// dbg(col);
			FOR(i, 1, k) {
				FOR(u, 1, n) FOR(v, 1, n) if (col[v] != col[u]) {
					chkmin(dp[v][i], dp[u][i-1] + dist[u][v]);
				}
				// dbg(dp[1][i]);
			}

			chkmin(ans, dp[1][k]);
			// dbg(dp[1][k]);
		}

		printf("%d\n", ans);
	}
    return 0;
}