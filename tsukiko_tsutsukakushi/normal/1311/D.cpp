/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int a, b, c; cin >> a >> b >> c;
    int ans = inf;
    vector<int> res = {a, b, c};
    // for(int i = 1; i <= 2 * c; ++i) {
    //     for(int j = 1; j * j <= i; ++j) {
    //         if(i % j == 0) {
    //             //b = j, c = i
    //             for(int k = 1; k * k <= j; ++k) {
    //                 if(j % k == 0) {
    //                     int alt = abs(a - k) + abs(b - j) + abs(c - i);
    //                     if(ans > alt) {
    //                         ans = alt;
    //                         res = {k, j, i};
    //                     }
    //                     int l = j / k;
    //                     alt = abs(a - l) + abs(b - j) + abs(c - i);
    //                     if(ans > alt) {
    //                         ans = alt;
    //                         res = {l, j, i};
    //                     }
    //                 }
    //             }
    //             //b = i / j, c = i
    //             int m = i / j;
    //             for(int k = 1; k * k <= m; ++k) {
    //                 if(m % k == 0) {
    //                     int alt = abs(a - k) + abs(b - m) + abs(c - i);
    //                     if(ans > alt) {
    //                         ans = alt;
    //                         res = {k, m, i};
    //                     }
    //                     int l = m / k;
    //                     alt = abs(a - l) + abs(b - m) + abs(c - i);
    //                     if(ans > alt) {
    //                         ans = alt;
    //                         res = {l, m, i};
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    //b
    for(int j = 1; j <= 2 * c; ++j) {
        int k = (c / j) * j;
        if(abs(k - c) > abs(k + j - c)) {
            k += j;
        }
        int l = 1, now = abs(a - 1);
        for(int i = 1; i * i <= j; ++i) {
            if(j % i == 0) {
                if(now > abs(a - i)) {
                    l = i;
                    now = abs(a - i);
                }
                if(now > abs(a - j / i)) {
                    l = j / i;
                    now = abs(a - l);
                }
            }
        } 
        int alt = abs(a - l) + abs(b - j) + abs(c - k);
        if(ans > alt) {
            ans = alt;
            res = {l, j, k};
        }
    }
    cout << ans << endl;
    for(auto v: res) {
        cout << v << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}