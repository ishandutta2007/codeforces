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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

// BIT
int lowbit(int num) {return num & (-num);}

void init(vector<int> &arr, int n, vector<int> &BIT) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

int query(int k, vector<int> &BIT) {
    int sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, int delta, vector<int> &BIT) {
    if (r<l) return;
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl a(n+m+2); FOR(i, 1, m) cin >> a[n+i];
        FOR(i, 1, n) a[i] = n+1-i;

        dbg(a);

        vi BIT(n+m+2), last(n+2);
        vi high(n+2, 0), low(n+2, n); FOR(i, 1, n) low[i] = high[i] = i;

        FOR(i, 1, n+m) {
            ll val = a[i];
            update(last[val]+1, i-1, 1, BIT);
            
            if (last[val]) chkmax(high[val], query(last[val], BIT)+1);
            if (i>n) chkmin(low[val], 1);
            last[val] = i;

            // cout << "BIT: " << endl;
            // FOR(i, 1, n+m) {
            //     cout << query(i, BIT) << " ";
            // }cout << endl;
        }

        FOR(val, 1, n) if (last[val]) chkmax(high[val], query(last[val], BIT)+1);

        dbg(high); dbg(low);

        FOR(i, 1, n) {
            cout << low[i] << " " << high[i] << endl;
        }
    }
    return 0;
}