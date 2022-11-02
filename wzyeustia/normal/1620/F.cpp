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
const ld EPS = 1e-8;
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll n;
ll idx(ll x, ll y) {return x * 2 * (n+1) + y; }
pll rev(ll idx) {
    ll x = idx / (2*n+2);
    ll y = idx % (2*n+2);
    return {x, y};
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n;
        vl p(n); REP(i, n) cin >> p[i];
        stack<pll> st;
        st.em(0, 0);

        map<ll, ll> last;
        bool found = true;
        REP(i, n) {
            vector<t3l> vec; 
            while (!st.empty()) {
                auto [x, y] = st.top(); st.pop();
                ll pre = idx(x, y);
                if (x < -p[i] + n+1) vec.eb(-p[i] + n+1, y, pre);
                else if (x < p[i] + n+1) vec.eb(p[i] + n+1, y, pre);
                if (y < -p[i] + n+1) vec.eb(x, -p[i] + n+1, pre);
                else if (y < p[i] + n+1) vec.eb(x, p[i] + n+1, pre);
            }
            sort(all(vec));


            for (auto [x, y, pre] : vec) {
                bool can = true;
                if (!st.empty()) {
                    auto [x0, y0] = st.top();
                    if (y >= y0) can = false;
                }
                if (can) st.em(x, y), last[idx(x, y)] = pre;
            }

            if (st.empty()) {
                found = false;
                break;
            }
            dbg(st.size());
        }
        
        if (found) {
            cout << "YES" << endl;

            vl sign(n, 1);
            auto [x, y] = st.top();

            ll a = x, b = y;
            ll crt = n-1;
            while (1) {
                if (a == 0 && b == 0) break;
                dbg(a, b);
                if (a - (n+1) + p[crt] == 0) sign[crt] = -1;
                if (b - (n+1) + p[crt] == 0) sign[crt] = -1;
                ll pre = last[idx(a, b)];
                auto [x, y] = rev(pre);
                a = x, b = y, crt--;
            }

            REP(i, n) cout << p[i] * sign[i] << " ";
            cout << endl;

        } else cout << "NO" << endl;


    }
}