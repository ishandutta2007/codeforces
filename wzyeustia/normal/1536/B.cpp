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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        string s; cin >> s;

        ll f1[26] = {0}, f2[26][26] = {0}, f3[26][26][26] = {0};
        REP(i, n) {
            ll v1, v2, v3;
            v1 = s[i]-'a'; f1[v1] = 1;
            if (i) {
                f2[s[i-1]-'a'][s[i]-'a'] = 1;
            }
            if (i>1) {
                f3[s[i-2]-'a'][s[i-1]-'a'][s[i]-'a'] = 1;
            }
        }

        ll find = 0, val = -1;
        REP(i, 26) if (!f1[i]) {
            find = 1;
            char c1 = i+'a';
                cout << c1 << endl;
            break;
        }
        if (find) continue;

        REP(i, 26) {
            REP(j, 26) if (!f2[i][j]) {
                find = true;
                char c1 = i+'a', c2 = j+'a';
                cout << c1 << c2 << endl;
                break;
            }
            if (find) break; 
        }
        if (find) continue;


        REP(i, 26) {
            REP(j, 26) {
                REP(k, 26) {
            if (!f3[i][j][k]) {
                find = true;
                char c1 = i+'a', c2 = j+'a', c3 = k+'a';
                cout << c1 << c2 << c3 << endl;
                break;
            }
            } if (find) break;
            } if (find) break;
        }
    }
    return 0;
}