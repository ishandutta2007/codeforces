#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

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

constexpr ll MOD = 1e9+7;
constexpr double EPS = 1e-8;
//Common variables

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

ll gcd(ll a, ll b) {
    if (a == 1 || b == 1) return 1;
    if (a % b == 0) return b;
    else return gcd(b, a%b);
}

ll query(ll x, ll y) {
    cout << "? " << x << " " << y << endl;
    fflush(stdout);

    ll got; cin >> got;
    return got;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        if (n == 1) {
            cout << "! " << 1 << endl;
            continue;
        }

        ll num1 = 1, num2 = 2;
        vector<int> ans(n+1), used(n+1, 0), got(n+1, 0);
        used[1] = used[2] = 1;

        while (num1 <= n && num2 <= n) {
            used[num1] = used[num2] = 1;
            ll ret1 = query(num1, num2), ret2 = query(num2, num1);
            if (ret1 > ret2) {
                ans[num1] = ret1;
                got[ret1] = 1;
                while (used[num1]) num1++;
            }
            else {
                ans[num2] = ret2;
                got[ret2] = 1;
                while (used[num2]) num2++;
            }
        }

        ll idx = 1;
        while (got[idx]) idx++;
        if (num1 <= n) ans[num1] = idx;
        else ans[num2] = idx;

        cout << "! ";
        FOR(i, 1, n) {
            cout << ans[i] << " ";
        }ln;
    }
    return 0;
}