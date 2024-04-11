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
const ll SIZE = 3e2+3; 

const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, h, m, k; cin >> n >> h >> m >> k;

        vector<pll> minutes;
        unordered_map<ll, ll> uMap;
        FOR(i, 1, n) {
            ll h1, m1; cin >> h1 >> m1;
            minutes.eb(m1, i);
            minutes.eb((m1+m/2)%m, i);

            uMap[m1]++;
            uMap[(m1+m/2)%m]++;
        }

        sort(all(minutes));
        ll ans = LLONG_MAX, pos = -1;

        ll last = minutes[0].first, idxL = 0, idxR = 1, cnt = 0;
        while (last < m/2) {
            while (minutes[idxR].first == last) idxR++;
            while (minutes[idxR].first < last+k) {
                cnt++; idxR++;
            }

            if (cnt < ans) {
                ans = cnt; pos = last;
            }

            dbg(idxR, cnt, pos);

            idxL++;
            ll next = minutes[idxL].first;
            if (next != last) {
                if (next < last+k) cnt -= uMap[next];
                last = next;
            }
        }

        dbg(ans, pos+k);
        cout << ans << " " << (pos+k)%(m/2) << endl;

        auto iter = upper_bound(all(minutes), make_pair(pos, 99999999ll));
        while ((*iter).first < pos+k) {
            dbg((*iter).first, (*iter).second);
            cout << (*iter).second << " ";
            iter++;
        }ln;
    }
    return 0;
}