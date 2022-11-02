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

const ll MX = 53, MM = 1300;
ll ddp[MX][MX][MM] = {0};
ll dp[MX][MX][MM] = {0};
ll p1[MX][MX][MM] = {0}, p2[MX][MX][MM] = {0};
// dp : length is i, head is j, inversion is k
// 3-dim dp is OK with 2-dim suffix sum.
// complexity: O(N^4)

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		ll n; cin >> n >> MOD;

		vl gain(n+2, 0);
		ddp[1][1][0] = 1;
		FOR(i, 2, n+1) {
			FOR(head, 1, i-1) {
				ll crt = 0;
				// dp[i][i][cnt] += val(head, i-1, cnt);
				REP(cnt, (i-2)*(i-1)/2 + 1) {
					crt = (crt + ddp[i-1][head][cnt])%MOD;
					ll val = crt+dp[i-1][head][cnt]; val%=MOD;
					dp[i-1][head][cnt] = val;

					dp[i][i][cnt+i-1] = (dp[i][i][cnt+i-1] + val)%MOD;
					ddp[i][head][cnt] = (ddp[i][head][cnt]+val)%MOD;
					ddp[i][head][cnt+i-1] = (ddp[i][head][cnt+i-1]-val+MOD)%MOD;
					// dbg(i, head, cnt);
				}
			}
		}

		FOR(len, 1, n) FOR(h, 1, len) REP(cnt, MM-2) {
			// dbg(p1[len][h][cnt]);
			p1[len][h][cnt] = (p1[len][h][max(cnt-1, 0)] + dp[len][h][cnt])%MOD;
		}
		FOR(len, 1, n) REP(cnt, MM-2) ROF(h, len, 1) {
			p2[len][h][cnt] = (p2[len][h+1][cnt] + p1[len][h][cnt])%MOD;
		}

		// FOR(i, 2, n+1) {
		// 	FOR(head, 1, i-1) {
		// 		REP(cnt, (i-2)*(i-1)/2+1)
		// 			cout << dp[i-1][head][cnt] << " ";
		// 		cout << endl;
		// 	} cout << endl;
		// }


		// FOR(len, 2, n) {
		// 	FOR(head, 1, len) { 
		// 		REP(cnt, len*(len-1)/2 + 1) cout << p2[len][head][cnt] << " ";
		// 		cout << endl;
		// 	}
		// 	cout << endl;
		// }

		FOR(len, 1, n) FOR(h1, 1, len-1) FOR(cnt, 1, len*(len-1)/2) {
			gain[len] = (gain[len] + dp[len][h1][cnt]*p2[len][h1+1][cnt-1]%MOD) %MOD;
		}

		// dbg(gain);
		vl earn(n+2, 0);
		FOR(i, 4, n) {
			earn[i] = (gain[i] + i*earn[i-1]%MOD) %MOD;
		}
		// dbg(earn);
		cout << earn[n] << endl;
	}
    return 0;
}