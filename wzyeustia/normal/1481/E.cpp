#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
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
 
// number theory
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

// convex hull
struct Point {
    ld x, y;
    bool operator < (Point p) {
        return x < p.x || (x == p.x && y < p.y);
    }
};

ld crossP(Point O, Point A, Point B) {
    return (A.x-O.x)*(B.y-O.y) - (B.x-O.x)*(A.y-O.y);
}

vector<Point> monotoneChain(vector<Point> vec) {
    ll n = vec.size(), idx = 0;
    if (n <= 3) return vec;
    vector<Point> ans(2*n);

    sort(all(vec));
    
    REP(i, n) {
        while (idx >= 2 && crossP(ans[idx-2], ans[idx-1], vec[i]) <= 0)
            idx--;
        ans[idx++] = vec[i];
    }

    ll lower = idx+1;
    ROF(i, n-1, 0) {
        while (idx >= lower && crossP(ans[idx-2], ans[idx-1], vec[i]) <= 0)
            idx--;
        ans[idx++] = vec[i];
    }

    ans.resize(idx-1);
    return ans;
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<ll> arr(n+5);
        FOR(i, 1, n) {cin >> arr[i];}

        vector<ll> start(n+5, -1), end(n+5, -1), cnt(n+5, 0);
        FOR(i, 1, n) {
            if (start[arr[i]] == -1) start[arr[i]] = i;
            end[arr[i]] = i;
            cnt[arr[i]]++;
        }

        // const ll START = 0, END = 1;
        vector<ll> check(n+5, -1);
        FOR(i, 1, n) {
            if (start[i] != -1) check[start[i]] = i;
        }

        vector<ll> dp(n+5, LLONG_MIN);
        vector<ll> rightCnt(n+5, 0);

        ll ans = 0; dp[n+1] = 0;
        ROF(i, n, 1) {
            ll color = arr[i];
            rightCnt[color]++;

            chkmax(dp[i], dp[i+1]);
            if (check[i] != -1) {
                chkmax(dp[i], dp[end[color]+1] + cnt[color]);
            }
            else {
                chkmax(dp[i], rightCnt[color]);
            }
        }

        cout << n - dp[1] << endl;
    }
    return 0;
}