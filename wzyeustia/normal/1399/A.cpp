#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

vector<ll> ans, inDegree;
vector<vector<ll>> edges;
ll n, m, k;

ll decode(string& str) {
    ll ret = 0;
    for (auto ch : str) {
        ret *= 27;
        if (ch == '_') ret += 26;
        else ret += ch-'a';
    }
    return ret;
}

ll getNewD(ll bits, string str) {
    REP(i, k) {
        if (bits&1) str[i] = '_';
        bits >>= 1;
    }
    return decode(str);
}

void update(string &str, string &pat) {
    ll val = decode(pat);
    REP(i, pow(2, k)) {
        ll newVal = getNewD(i, str);

        if (newVal != val) {
            edges[val].eb(newVal);
            inDegree[newVal]++;
        }
    }
}

bool match(string& str, string& pattern) {
    REP(i, k) {
        if (pattern[i] != '_' && pattern[i] != str[i]) 
            return false;
    }
    return true;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<ll> arr(n);
        REP(i, n) {cin >> arr[i];}

        sort(all(arr));

        bool flag = false;        
        FOR(i, 1, n-1) {
            if (arr[i] - arr[i-1] > 1) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}