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

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

struct Plan {
    ll p[3] = {0};
};

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll k, n; cin >> k >> n;
        map<ll, ll, greater<ll>> ma;
        REP(i, n) {
            ll u; string s;
            cin >> u >> s;
            ll type = 2;
            if (s[0] == 'w' || s[0]== 'y') type = 3;
            if (s[0] == 'g' || s[0] == 'b') type = 4;
            ma[u] = type;
            while (u > 1) {
                u /= 2;
                chkmax(ma[u], 1ll);
            }
        }

        vl val(k); val[0] = 2;
        FOR(i, 1, k-1) {
            ll child = 2 * val[i-1] %MOD;
            val[i] = child * child * 2 %MOD;
        }
        dbg(val);


        ll tot = 1ll << k;

        map<ll, Plan> mPlan;
        for (auto [u, type] : ma) {
            ll lv = 0, tmp = u;
            while (2*tmp < tot) {
                lv++, tmp<<=1;
            }

            Plan plan;
            if (2*u >= tot) {
                plan.p[type-2] = 1;
            } else {
                Plan p1, p2;
                if (mPlan.count(u*2)) p1 = mPlan[u*2];
                else p1.p[0] = p1.p[1] = p1.p[2] = val[lv-1];

                if (mPlan.count(u*2+1)) p2 = mPlan[u*2+1];
                else p2.p[0] = p2.p[1] = p2.p[2] = val[lv-1];

                REP(r, 3) {
                    plan.p[r] = (p1.p[(r+1)%3] + p1.p[(r+2)%3]) *
                                 (p2.p[(r+1)%3] + p2.p[(r+2)%3]) %MOD;
                    plan.p[r] = plan.p[r] * 2 %MOD;
                }

                if (type != 1) REP(r, 3) {
                    if (r != type - 2) plan.p[r] = 0;
                    else plan.p[r] = plan.p[r] * getInv(2, MOD) %MOD;
                }
                
            }

            dbg(u);
            dbg(plan.p[0], plan.p[1], plan.p[2]);

            mPlan[u] = plan;
        }

        ll ans = 0;
        REP(r, 3) ans = (ans + mPlan[1].p[r])%MOD;
        dbg(ans);
        cout << ans << endl;
    }
    return 0;
}