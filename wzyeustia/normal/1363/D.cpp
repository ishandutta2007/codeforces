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
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

ll n, k;
vector<set<ll>> subsets;
vl ans;

ll query(vl& idx, bool direct = false) {
    if (direct) {
        ll sz = idx.size();
        cout << "? " << sz << " ";
        for (auto i : idx) cout << i << " ";
        ln; cout.flush();

        ll ret; cin >> ret;
        return ret;
    }

    ll sz = 0;
    for (auto num : idx) {
        sz += subsets[num].size();
    }

    cout << "? " << sz << " ";
    for (auto num : idx) {
        for (auto pp : subsets[num]) {
            cout << pp << " ";
        }
    }ln;
    cout.flush();

    ll ret; cin >> ret;
    return ret;
}

bool answer() {
    cout << "! ";
    for (auto num : ans) {
        cout << num << " ";
    }ln;
    cout.flush();

    string ret; cin >> ret;
    if (ret[0] == 'I') return false;
    else return true;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n >> k;
        subsets = vector<set<ll>>(); 

        REP(i, k) {
            ll sz; cin >> sz;
            set<ll> sub; REP(j, sz) {ll num; cin >> num; sub.em(num);}
            subsets.eb(sub);
        }

        vl all; FOR(i, 1, n) all.eb(i);
        ll mx = query(all, true);
        ans = vl(k, mx);

        ll l = 0, r = k-1;
        while (l < r) {
            ll mid = (l+r)>>1;
            dbg(l, r);
            vl vec; FOR(i, l, mid) vec.eb(i);
            
            ll ret = query(vec);
            if (mx != ret) 
                l = mid+1;
            else r = mid;
        }

        ll pos = l; dbg(pos);
        vl vec;

        FOR(i, 1, n) {
            if (!subsets[pos].count(i)) {
                vec.eb(i);
            }
        }
        ll ret = query(vec, true);
        ans[pos] = ret;

        if (!answer()) return 0;
    }
    return 0;
}