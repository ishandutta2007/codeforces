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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

vl cnt;
vector<char> chr;

ll one(ll p) {
    while (p < 26 && !cnt[p]) p++;
    if (p < 26) {
        cout << chr[p]; cnt[p]--;
    }
    return p;
}

void rest(ll p) {
    while (p < 26) p = one(p);
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        string s; cin >> s;
        ll n = s.size();
        
        cnt = vl(26, 0);
        chr = vector<char>(26, 0); REP(i, 26) chr[i] = 'a'+i;
        
        set<ll> se;
        REP(i, n) cnt[s[i]-'a']++, se.em(s[i]-'a');

        ll fst = *se.begin();
        if (se.size() == 1) {
            cout << s << endl;
            continue;
        }

        bool found = false;
        REP(i, 26) if (cnt[i] == 1) {
            cout << chr[i]; cnt[i]--;
            rest(0);
            cout << endl;
            found = true; break;
        }
        if (found) continue;

        ll snd = *(++se.begin());
        dbg(fst, snd);
        if (cnt[fst] <= n/2 + 1) {
            cout << chr[fst]; cnt[fst]--;

            ll crt = fst+1;
            REP(i, cnt[fst]) {
                cout << chr[fst];
                crt = one(crt);
            }
            rest(crt);

        } else if (se.size() >= 3) {
            auto it = se.begin();
            ++it; ++it;
            ll thd = *it;

            cout << chr[fst] << chr[snd];
            cnt[fst]--; cnt[snd]--;
            REP(i, cnt[fst]) cout << chr[fst];
            cout << chr[thd]; cnt[thd]--;
            rest(snd);
        } else {
            cout << chr[fst]; cnt[fst]--;
            REP(i, cnt[snd]) cout << chr[snd];
            REP(i, cnt[fst]) cout << chr[fst];
        }

        cout << endl;
    }


    return 0;
}