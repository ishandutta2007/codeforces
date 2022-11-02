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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        string str; cin >> str;
        
        ll last = -1, delta = 0;
        char change = '\0';
        vl cnt(256, 0);

        if (n%k) {cout << -1 << endl; continue;}

        for (auto ch : str) cnt[ch]++;
        bool flag = true;
        FOR(i, 'a', 'z') if (cnt[i]%k) {flag = false; break;}
        if (flag) {
            cout << str << endl;
            continue;
        }
        cnt = vl(256, 0);

        REP(i, n) {
            for (char ch = str[i]+1; ch <= 'z'; ch++) {
                cnt[ch]++;

                ll need = 0;
                for (char p = 'a'; p <= 'z'; p++) {
                    if (cnt[p]%k) need += (k - cnt[p]%k); 
                }
                if (need <= n-1 - i) {
                    cnt[ch]--;
                    last = i, change = ch, delta = (n-1 - i) - need;
                    break;
                }
                cnt[ch]--;
            }

            cnt[str[i]]++;
        }

        dbg(last);
        if (last == -1) {
            cout << -1 << endl;
            continue;
        }
        
        cnt = vl(256, 0);
        ll len = 0;
        REP(i, last) {cout << str[i]; cnt[str[i]]++;}
        cout << change; cnt[change]++;

        REP(i, delta) cout << 'a';
        for (char p = 'a'; p <= 'z'; p++) {
            if (cnt[p]%k) {
                REP(pp, k - cnt[p]%k) {
                    cout << p;
                }
            }
        }ln;

    }
    return 0;
}