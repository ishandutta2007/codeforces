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

ll query(vector<char>& seq, ll len) {
    REP(i, len) cout << seq[i];
    cout << endl; cout.flush();
    ll ret; cin >> ret;
    return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        vector<char> seq(305, 'a');
        ll dis1 = query(seq, 300); if (!dis1) continue;
        REP(i, 305) seq[i] = 'b';
        ll dis2 = query(seq, 300); if (!dis2) continue;

        ll len = 600 - (dis1+dis2);
        ll aCnt = dis2-300+len, bCnt = dis1-300+len;

        dbg(aCnt, bCnt, len);

        if (aCnt == 0) {
            query(seq, len);
            continue;
        }
        if (bCnt == 0) {
            REP(i, len) seq[i] = 'a';
            query(seq, len);
            continue;
        }

        REP(i, len) seq[i] = 'a';
        ll crt = 0, dis = bCnt;
        while (true) {
            seq[crt] = 'b';
            ll ret = query(seq, len);
            if (ret < dis) {
                dis = ret;
            } else {
                seq[crt] = 'a';
            }
            crt++;
            if (ret == 0) break;
        }
    }
    return 0;
}