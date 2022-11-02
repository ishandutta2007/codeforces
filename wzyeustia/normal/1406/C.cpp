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

#define get(x) int x; cin >> x
#define getArr(arr, n) REP(i, n) {cin >> arr[i];}

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

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


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return (((half * half)) * num);
        }
        else {
            return (half * half);
        }
    }
}
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

ll find(ll k, vector<ll> &F) {
    return F[k] == k? k : F[k] = find(F[k], F);
}

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
 
vector<vector<int>> edges;
vector<int> sizes, largest;
int n;
int dfs(ll node, ll parent) {
    int size = 1;
    for (auto adj : edges[node]) {
        if (adj != parent) {
            int subsize = dfs(adj, node);
            chkmax(largest[node], subsize);
            size += subsize;
        }
    }

    sizes[node] = size;
    chkmax(largest[node], n-size);

    return size;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 1e9+7;

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n;
        edges = vector<vector<int>>(n+2, vector<int>());
        sizes = vector<int>(n+2);
        largest = vector<int>(n+2, 0);

        REP(i, n-1) {
            int x, y; cin >> x >> y;
            edges[x].eb(y);
            edges[y].eb(x);
        }

        dfs(1, -1);
        
        vector<int> temp(largest);
        dbg(largest);
        sort(all(temp));
        if (temp[2] != temp[3]) {
            // cout << "OK" << endl;
            cout << 1 << " " << edges[1][0] << endl;
            cout << 1 << " " << edges[1][0] << endl;
        }
        else {
            // cout << "OH" << endl;
            int first = 0;
            while (largest[first] != temp[2]) first++;
            int second = first+1;
            while (largest[second] != temp[2]) second++;
            dbg(first, second);
            for (auto child : edges[first]) {
                if (child != second) {
                    cout << first << " " << child << endl;
                    cout << second << " " << child << endl;
                    break;
                }
            }
        }
    }
    return 0;
}