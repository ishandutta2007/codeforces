#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MX = 5e6;
ll cnt[MX+2], tot[MX+2], dp[MX+2]; 

bool comp[MX+2];
int mu[MX+2];
vi prime, noZero, one;

void getMu(int n) {
    mu[1] = 1;// noZero.eb(1);
    FOR(i, 2, n) {
        if (!comp[i]) prime.eb(i), mu[i] = -1;
        for (auto pr : prime) {
            int crt = i * pr;
            if (crt > n) break;
            comp[crt] = 1;
            if (i % pr == 0) {
                mu[crt] = 0;
                break;
            }
            mu[crt] = -mu[i];
        }
        if (mu[i]) noZero.eb(i);
        // if (mu[i] == 1) one.eb(i);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    getMu(MX);


    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n; cin >> n;
        vi a(n); REP(i, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        // ROF(i, MX, 1) {
        //     FOR(k, 1, MX/i) {
        //         tot[i] += cnt[i*k];
        //     }
        // }

        ROF(i, MX, 1) {
            for (auto k : noZero) {
                if (i*k > MX) break;
                cnt[i] -= mu[k] * cnt[k*i];
            }
        }

        // FOR(i, 1, MX) {
        //     if (tot[i] != cnt[i]) {
        //         dbg(i, tot[i], cnt[i]);
        //     }
        // } 

        ROF(i, MX, 1) {
            dp[i] = i * cnt[i];
            // FOR(k, 1, MX/i) {
            for (auto k : prime) {
                if (i*k > MX) break;
                chkmax(dp[i], dp[i*k] + i * (cnt[i] - cnt[i*k]));
            }
        }

        cout << dp[1] << endl;
    }
    return 0;
}