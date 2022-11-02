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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        string str; cin >> str;
        ll tot = 0, cnt = 0;
        
        REP(i, n) {
            if (str[i] == 'W') {
                if (i>0 && str[i] == str[i-1]) tot +=2;
                else tot++;
            }
            else cnt++;
        }
        chkmin(k, cnt);
        dbg(tot);

        MinHeap<int> pq;
        ll start = 0, last = n-1;
        while (start < str.length() && str[start] == 'L') start++;
        while (last >= 0 && str[last] == 'L') last--;

        ll finalPart = start + n-1-last;
        if (start > last) {
            cout << max(0ll, 2*k-1) << endl;
            continue;
        }

        ll len = 0;
        while (start <= last) {
            if (str[start] == 'L') len++;
            else if (len != 0) {
                pq.emplace(len);
                len = 0;
            }
            start++;
        }

        while (!pq.empty() && k >= pq.top()) {
            // dbg(pq.top());
            tot += pq.top() * 2 + 1;
            k -= pq.top();
            pq.pop();
        }  

        tot += 2*k;

        cout << tot << endl;
    }
    return 0;
}