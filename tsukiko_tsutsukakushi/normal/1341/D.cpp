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
	int n, k; cin >> n >> k;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    vector<string> a = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<vector<int>> cnt(n, vector<int>(10, 0));
    int sum = 0;
    rep(i, n) {
        rep(l, 10) {
            if(s[i][l] == '1') {
                ++ sum;
            }
        }
    }
    rep(i, n) {
        rep(j, 10) {
            rep(l, 7) {
                if(s[i][l] == '0' && a[j][l] == '1' && cnt[i][j] != -1) {
                    ++ cnt[i][j];
                } 
                if(s[i][l] == '1' && a[j][l] == '0') {
                    cnt[i][j] = -1;
                }
            }
            //cerr << i << " " << j << " " << cnt[i][j] << endl;
        }
    }
    static bool dp[2020][2020];
    rep(i, 2020) {
        rep(j, 2020) {
            dp[i][j] = 0;
        }
    }
    dp[n][k] = 1;
    for(int i = n; i > 0; -- i) {
        for(int j = k; j >= 0; -- j) {
            if(dp[i][j]) {
                rep(l, 10) {
                    if(cnt[i - 1][l] == -1) continue;
                    if(j - cnt[i - 1][l] >= 0) {
                        dp[i - 1][j - cnt[i - 1][l]] = 1;
                        //cerr << i - 1 << " " << j <<  " " << l << " " << j - cnt[i - 1][l] << endl;
                    }
                }
            }
        }
    }
    string ans = "";
    int j = 0;
    rep(i, n) {
        bool ok = 0;
        int mi = -1;
        for(int l = 9; l >= 0; -- l) {
            int co = cnt[i][l];
            if(co == -1) continue;
            bool ok1 = 0;
                if(dp[i][j] && j + co <= k && dp[i + 1][j + co]) {
                    ok1 = 1;
                    ans += ('0' + l);
                    j += co;
                }
            if(ok1) {
                ok = 1;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;

    // if(n * 7 - sum < k) {
    //     cout << -1 << endl;
    //     return;
    // }
    // string ans = "";
    // int sum1 = 0;
    // rep(i, n) {
    //     int mi = inf, tmp = -1;
    //     for(int l = 9; l >= 0; -- l) {
    //         if(cnt[i][l] == -1) continue;
    //         if(chmin(mi, cnt[i][l])) {
    //             tmp = l;
    //         }
    //     }
    //     if(mi == inf) {
    //         cout << -1 << endl;
    //         return;
    //     }
    //     sum1 += mi;
    //     ans += ('0' + tmp);
    // }
    // if(sum1 > k) {
    //     cout << -1 << endl;
    //     return;
    // }
    // int nokori = k - sum1;
    // rep(i, n) {
    //     int now = ans[i] - '0';
    //     for(int l = 9; l > now; -- l) {
    //         int nex = cnt[i][l] - cnt[i][now];
    //         if(nokori >= nex) {
    //             ans[i] = ('0' + l);
    //             nokori -= nex;
    //             break;
    //         }
    //     }
    // }
    // cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}