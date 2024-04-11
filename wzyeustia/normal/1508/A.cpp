#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

#define ln printf("\n");

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
const ll MOD = 1e9+7;
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
        string s[3]; REP(i, 3) cin >> s[i];

        vl c(3, 0);
        REP(i, 3) {
            REP(j, 2*n) if (s[i][j] == '1') c[i]++;
        }
        dbg(c);

        ll idx1, idx2;
        char ch1, ch2;
        REP(i, 3) {
            if (c[i] >= n && c[(i+1)%3] >= n) {
                idx1 = i, idx2 = (i+1)%3, ch1 = '1', ch2 = '0';
                break;
            }

            if (c[i] <= n && c[(i+1)%3] <= n) {
                idx1 = i, idx2 = (i+1)%3, ch1 = '0', ch2 = '1';
                break;
            }
        } 

        dbg(idx1, idx2, ch1, ch2);

        vl ans(3*n); ll pos = 0; 
        REP(i, 2*n) {
            if (s[idx1][i] == ch1) pos++;
            else ans[pos]++;
        }

        pos = 0;
        REP(i, 2*n) {
            if (s[idx2][i] == ch1) pos++;
            else ans[pos]++;
        }

        ll mx;
        if (ch1 == '1') mx = max(c[idx1], c[idx2]);
        else mx = 2*n - min(c[idx1], c[idx2]);

        FOR(i, 0, mx) {
            while (ans[i]) {cout << ch2; ans[i]--;}
            if (i<mx) cout << ch1;
        }cout << endl;
    }
    return 0;
}