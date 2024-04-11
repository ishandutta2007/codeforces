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

ll tot = 0;

ll query(ll left, vl& right) {
    tot++;
    cout << "? " << 1 << " " << right.size() << endl;
    cout << left << endl;
    for (auto num : right) {
        if (num == 0) continue;
        cout << num << " ";
    }ln;
    cout.flush();

    ll ret; cin >> ret;
    return ret;
}

void answer(vl& ans) {
    cout << "! " << ans.size() << " ";
    for (auto num : ans) {cout << num << " ";}
    cout.flush();
}

ll highBit(ll n) {
    ll ret = 1;
    while (2 * ret < n) ret <<= 1;
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        tot = 0;

        ll n; cin >> n;
        vl Right;
        FOR(i, 1, n) Right.eb(i);

        ll comp = -1, sum = 0, i;
        vl maybe, sure;
        for(i = 1; i<=n-1; i++) {
            Right.erase(Right.begin());
            if (sum = query(i, Right)) {
                comp = i; break;
            } else {
                maybe.eb(i);
            }
        }

        i++;
        vl one2(1);
        for (; i<=n-1; i++) {
            one2[0] = i;
            ll result = query(comp, one2);
            sum -= result;
            if (result == 0) {
                sure.eb(i);
            }
        }

        if (sum == 0) {
            sure.eb(n);
        }

        bool exist = false;

        while (maybe.size() > 1) {
            ll len = highBit(maybe.size());
            vl test1, test2;
            REP(i, len) {
                test1.eb(maybe[i]);
            }
            FOR(i, len, maybe.size()-1) {
                test2.eb(maybe[i]);
            }

            if (query(comp, test1)) {
                exist = true;
                for (auto num : test2) {sure.eb(num);}
                maybe.swap(test1);
            } else {
                for (auto num : test1) {sure.eb(num);}
                maybe.swap(test2);
            }
        }

        if (!maybe.empty()) {
            if (!exist && !query(comp, maybe)) {
                sure.eb(maybe[0]);
            }
        }

        answer(sure);
        dbg(tot);
    }
    return 0;
}