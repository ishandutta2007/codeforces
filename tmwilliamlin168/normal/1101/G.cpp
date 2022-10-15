#define DEBUG
// #define FASTIO

#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define F first
#define S second 
#define pb push_back
#define endl "\n"

#ifdef FASTIO

#define pr(x) printf("%d", x)
#define ps    printf(" ")
#define endc  printf("\n")
#define pl(x) printf("%lld", x)
#define pf(x) printf("%lf", x)
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define IOS 

#endif

#ifndef FASTIO
    #define IOS { ios :: sync_with_stdio(false); cin.tie(0); }
#endif

#ifdef DEBUG
    #define dbg(s) {s;}
#endif

#ifndef DEBUG
    #define dbg(s)
#endif

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) {
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef vector < int > vi;

const int maxn = 2e5 + 6;

const ll inf = 1e9 + 7;

const ll mod = 1e9 + 7;


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const int bits = 32;
ll A[maxn];

ll swapbits(ll x, int p, int q) {
    ll pb = (x & (1l << p)) > 0;
    ll qb = (x & (1l << q)) > 0;

    x ^= pb << p;
    x ^= qb << q;
    x ^= pb << q;
    x ^= qb << p;

    return x;
}

int main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    IOS;
    
    int n; cin >> n;
    ll last = 0l;
    for (int j = 0; j < n; j++) {
        ll x;
        cin >> x;
        A[j] = last ^ x;
        last = A[j];
    }

    reverse(A, A + n);

    // for (int j = 0; j < n; j++) {
    //     cout << (bitset<6>(A[j])) << endl;
    // }

    // cout << endl;

    if (A[0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    int sb = -1;

    for (int j = bits - 1; j >= 0; j--) {
        if (A[0] & (1ll << j)) {
            sb = j;
            break;
        }
    }

    // cout << sb << endl;

    for (int j = 0; j < n; j++) {
        A[j] = swapbits(A[j], sb, bits);
    }

    // for (int j = 0; j < n; j++) {
    //     cout << (bitset<34>(A[j])) << endl;
    // }

    int pos = 0;

    for (int j = bits; j >= 0; j--) {

        // for (int i = 0; i < n; i++) {
        //     cout << (bitset<6>(A[i])) << endl;
        // }

        // cout << "--x--" << endl;

        bool ok = false;

        for (int k = pos; k < n; k++) {
            if (A[k] & (1l << j)) {
                swap(A[k], A[pos]); 
                ok = true; 
                break;
            }
        }

        if (ok) {
            for (int k = pos + 1; k < n; k++) {
                if (A[k] & (1l << j)) {
                    A[k] ^= A[pos];
                }
            }
            pos++;
        }
    }

    int ans = 0;

    for (int j = 0; j < n; j++) {
        ans += A[j] > 0;
    }

    cout << ans << endl;
}