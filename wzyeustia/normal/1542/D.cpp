#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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

const ll MX = 511;
vl dp;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n;
		vl val(MX+2); FOR(i, 1, n) {
			string type; cin >> type;
			if (type[0] == '-') val[i] = 0;
			else cin >> val[i];
		}
		dbg(val);

		ll ans = 0;
		FOR(i, 1, n) if (val[i] > 0) {
			dp = vl(n+1, 0); dp[0] = 1;
			FOR(pos, 1, n) {
				if (val[pos] == 0) {
					dp[0] = (dp[0]<<1)%MOD;
					REP(i, n) dp[i] = (dp[i]+dp[i+1])%MOD;
				} else {
					bool help = false;
					if (val[pos] < val[i]) help = true;
					if (val[pos] == val[i] && pos<=i) help = true;

					dbg(help);
					if (pos==i){
						if (help) ROF(i, n, 1) dp[i] = dp[i-1];
					} else {
						if (help) ROF(i, n, 1) dp[i] = (dp[i]+dp[i-1])%MOD;
						else ROF(i, n-1, 0) dp[i] = (dp[i]<<1)%MOD;
					}
				}
				if (pos>=i) dp[0] = 0;
				// dbg(dp);
			}
			ll tot = 0;
			FOR(cnt, 1, n) tot = (tot+dp[cnt])%MOD;
			// dbg(tot);
			ans = (ans + tot*val[i])%MOD;
		}

		cout << ans << endl;

		// dp[0][MX-1] = 1; // ?
		// ll ans = 0;
		// ROF(i, n, 1) {
		// 	ans = (ans << 1)%MOD;
		// 	if (val[i] == 0) {
		// 		ROF(cnt, MX-2, 0) FOR(idx, 0, MX-1) {
		// 			dp[cnt+1][idx] = (dp[cnt+1][idx] + dp[cnt][idx])%MOD;
		// 		}
		// 	} else {
		// 		FOR(idx, 0, MX-1) {
		// 			if (val[idx] > val[i] || idx == MX-1) {
		// 				FOR(cnt, 1, MX-1) {
		// 					dp[cnt-1][i] = (dp[cnt-1][i] + dp[cnt][idx])%MOD;
		// 					ans = (ans + dp[cnt][idx] * val[idx])%MOD;
		// 				} 
		// 				ans = (ans + dp[0][idx] * val[idx])%MOD;
		// 				if (idx == MX-1) ans = (ans + dp[0][idx] * val[i])%MOD;
		// 				dp[0][i] += dp[0][idx];
		// 			}
		// 			else {
		// 				ans = (ans + dp[0][idx] * val[i])%MOD;
		// 				dp[0][idx] = (dp[0][idx] << 1ll)%MOD;
		// 				FOR(cnt, 1, MX-1)
		// 					dp[cnt-1][idx] = (dp[cnt-1][idx] + dp[cnt][idx])%MOD;
		// 			}
		// 		}
		// 	}
		// 	dbg("dp:");
		// 	FOR(i, 0, n) dbg(dp[i]);
		// 	dbg(ans);
		// }

		dbg(ans);
	}
    return 0;
}