#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

#define ln cout << endl;

// Can I use this?
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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        
        ll tot1 = (sqr(n)+1)/2, tot2 = sqr(n)/2;
        ll cnt1 = 0, cnt2 = 0;

        stack<pll> pos1, pos2;
        FOR(i, 1, n) FOR(j, 1, n) {
            if ((i+j)%2 == 0) pos1.em(i, j);
            else pos2.em(i, j);
        }

        ll x1 = 1, y1 = 1, x2 = 2, y2 = 1;
        REP(i, sqr(n)) {
            ll ban; cin >> ban;
            if (ban != 1) {
                if (cnt1 < tot1) {
                    cnt1++;
                    auto [x, y] = pos1.top(); pos1.pop();
                    cout << 1 << " " << x << " " << y << endl;
                    
                } else {
                    ll sel = 2;
                    if (ban == 2) sel = 3;

                    auto [x, y] = pos2.top(); pos2.pop();
                    cout << sel << " " << x << " " << y << endl;
                }

            } else {
                if (cnt2 < tot2) {
                    cnt2++;
                    auto [x, y] = pos2.top(); pos2.pop();
                    cout << 2 << " " << x << " " << y << endl;
                    
                } else {
                    ll sel = 1;
                    if (ban == 1) sel = 3;

                    auto [x, y] = pos1.top(); pos1.pop();
                    cout << sel << " " << x << " " << y << endl;
                    
                }
            }
        }
    }
    return 0;
}