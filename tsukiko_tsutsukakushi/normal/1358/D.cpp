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

#define int long long
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
	int n, x; cin >> n >> x;
    vector<int> d(4 * n);
    rep(i, n) {
        cin >> d[i];
    }
    rep(i, n) {
        d[i + n] = d[i];
    }
    rep(i, n) {
        d[i + 2 * n] = d[i];
    }
    rep(i, n) {
        d[i + 3 * n] = d[i];
    }
    vector<int> d_ = d;
    int ans = 0;
    int res = 0;
    int nokori = x, cur = 3 * n - 1;
    while(nokori > 0) {
        if(nokori >= d[cur]) {
            res += d[cur] * (d[cur] + 1) / 2;
            nokori -= d[cur];
            cur --;
        } else {
            res += (d[cur] + d[cur] - nokori + 1) * nokori / 2;
            d_[cur] -= nokori;
            nokori = 0;
        }
    }
    chmax(ans, res);
    for(int i = 3 * n - 1; i >= n; -- i) {
        if(d[i] <= x) {
            res -= d[i] * (d[i] + 1) / 2;
                //
            if(i < cur) cur --;
            int nokori0 = min(x, d[i]);
            while(nokori0 > 0) {
                if(nokori0 >= d_[cur]) {
                    res += d_[cur] * (d_[cur] + 1) / 2;
                    nokori0 -= d_[cur];
                    cur --;
                } else {
                    res += (d_[cur] + d_[cur] - nokori0 + 1) * nokori0 / 2;
                    d_[cur] -= nokori0;
                    nokori0 = 0;
                }
            }
            chmax(ans, res);
        } else {
            res = 0;
            int nokori0 = x; if(i < cur) cur --;
                while(nokori0 > 0) {
                    if(nokori0 >= d_[cur]) {
                        res += d_[cur] * (d_[cur] + 1) / 2;
                        nokori0 -= d_[cur];
                        cur --;
                    } else {
                        res += (d_[cur] + d_[cur] - nokori0 + 1) * nokori0 / 2;
                        d_[cur] -= nokori0;
                        nokori0 = 0;
                    }
                }
                chmax(ans, res);
        }
        // //
        // if(i < cur) cur --;
        // int nokori0 = min(x, d[i]);
        // while(nokori0 > 0) {
        //     if(nokori0 >= d_[cur]) {
        //         res += d_[cur] * (d_[cur] + 1) / 2;
        //         nokori0 -= d_[cur];
        //         cur --;
        //     } else {
        //         res += (d_[cur] + d_[cur] - nokori0 + 1) * nokori0 / 2;
        //         d_[cur] -= nokori0;
        //         nokori0 = 0;
        //     }
        // }
        chmax(ans, res);
    }
    /////
    nokori = x - 1, cur = 0;
    ++ cur;
    int bf = 0;
    res = 0;
    while(nokori > 0) {
        if(nokori >= d[cur]) {
            res += d[cur] * (d[cur] + 1) / 2;
            nokori -= d[cur];
            cur ++;
        } else {
            res += (nokori + 1) * nokori / 2;
            bf = nokori;
            nokori = 0;
        }
    }
    chmax(ans, d[0] + res);
    for(int i = 1; i <= 2 * n; ++ i) {
        if(d[i] <= x - 1) {
            res -= d[i] * (d[i] + 1) / 2;
            int nokori1 = min(d[i], x - 1);
            if(i > cur) cur ++;
            while(nokori1 > 0) {
                if(bf > 0) {
                    if(d[cur] - bf <= nokori1) {
                        res += (d[cur] + bf + 1) * (d[cur] - bf) / 2;
                        nokori1 -= (d[cur] - bf);
                        bf = 0;
                        ++ cur;
                    } else {
                        res += (bf + 1 + bf + nokori1) * nokori1 / 2;
                        bf = bf + nokori1;
                        nokori1 = 0;
                    }
                } else if(nokori1 >= d[cur]) {
                    res += d[cur] * (d[cur] + 1) / 2;
                    nokori1 -= d[cur];
                    cur ++;
                } else {
                    res += (nokori1 + 1) * nokori1 / 2;
                    bf = nokori1;
                    nokori1 = 0;
                }
            }
        } else {
            res -= (x - 1) * x / 2;
            int nokori1 = min(d[i], x - 1);
            if(i > cur) cur ++;

            while(nokori1 > 0) {
                if(nokori1 >= d[cur]) {
                    res += d[cur] * (d[cur] + 1) / 2;
                    nokori1 -= d[cur];
                    cur ++;
                } else {
                    res += (nokori1 + 1) * nokori1 / 2;
                    bf = nokori1;
                    nokori1 = 0;
                }
            }
        }
        // int nokori1 = min(d[i], x - 1);
        // if(i > cur) cur ++;
        // while(nokori1 > 0) {
        //     if(bf > 0) {
        //         if(d[cur] - bf <= nokori1) {
        //             res += (d[cur] + bf + 1) * (d[cur] - bf) / 2;
        //             nokori1 -= (d[cur] - bf);
        //             bf = 0;
        //             ++ cur;
        //         } else {
        //             res += (bf + 1 + bf + nokori1) * nokori1 / 2;
        //             bf = bf + nokori1;
        //             nokori1 = 0;
        //         }
        //     } else if(nokori1 >= d[cur]) {
        //         res += d[cur] * (d[cur] + 1) / 2;
        //         nokori1 -= d[cur];
        //         cur ++;
        //     } else {
        //         res += (nokori1 + 1) * nokori1 / 2;
        //         bf = nokori1;
        //         nokori1 = 0;
        //     }
        // }
        chmax(ans, d[i] + res);
        //cerr << i << " " << d[i] + res << endl;
    }
    ///
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}