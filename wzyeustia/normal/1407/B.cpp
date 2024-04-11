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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<int> arr;
        REP(i, n) {
            int temp; cin >> temp;
            arr.eb(temp);
        }
        sort(all(arr), greater<int>());

        vector<int> ans;

        ans.eb(arr[0]);
        ll current = arr[0];
        arr[0] = -1;

        REP(i, n-1) {
            ll maxi = 0, next;
            REP(j, n) {
                if (arr[j] != -1) {
                    if (gcd(arr[j], current) > maxi) {
                        maxi = gcd(arr[j], current);
                        next = j;
                    }
                }
            }

            current = maxi;
            ans.eb(arr[next]);
            arr[next] = -1;
        }

        REP(i, n) {
            cout << ans[i] << " ";
        }ln;
    }
    return 0;
}