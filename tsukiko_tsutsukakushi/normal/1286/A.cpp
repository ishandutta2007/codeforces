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
//#define int long long

void solve() {
	int n; cin >> n;
    vector<int> p(n);
    vector<int> cnt0, cnt1, cnt11, cnt00;
    int ev = 0, od = 0;
    rep(i, n) {
        cin >> p[i];
        if(p[i] != 0) {
            if(p[i] % 2 == 0) {
                ++ev;
            } else {
                ++od;
            }
        }
    }
    ev = n / 2 - ev;
    od = (n + 1) / 2 - od;
    int now = -1;
    int cnt = 0;
    int ans = 0;
    rep(i, n) {
        if(p[i] == 0) {
            ++cnt;
        }
        if(p[i] != 0) {
            if(now == -1) {
                if(cnt == 0) {
                    if(p[i] % 2 == 0) {
                        cnt = 0; now = 0;
                    } else {
                        cnt = 0; now = 1;
                    }
                    continue;
                }
                ans += 1;
                if(p[i] % 2 == 0) {
                    cnt0.pb(cnt);
                    cnt = 0; now = 0;
                } else {
                    cnt1.pb(cnt);
                    cnt = 0; now = 1;
                }
            } else {
                if(cnt == 0) {
                    if(p[i] % 2 == 0) {
                        if(now == 1) ++ans;
                        now = 0;
                    } else {
                        if(now == 0) ++ans;
                        now = 1;
                    }
                    continue;
                }
                ans += 1;
                if(p[i] % 2 == 0) {
                    if(now == 0) cnt00.pb(cnt), ans += 1;
                    cnt = 0; now = 0;
                } else {
                    if(now == 1) cnt11.pb(cnt), ans += 1;
                    cnt = 0; now = 1;
                }
            }
        }
        if(p[i] == 0 && i == n - 1) {
            ans += 1;
            if(now == 0) {
                cnt0.pb(cnt);
            } else {
                cnt1.pb(cnt);
            }
        }
    }
    sort(all(cnt0));
    sort(all(cnt1));
    sort(all(cnt00));
    sort(all(cnt11));
    int i = 0;
    while(ev > 0) {
        if((int)cnt00.size() > i) {
            if(ev >= cnt00[i]) {
                ev -= cnt00[i];
                ans -= 2;
                ++i;
            } else break;
        } else break;
    }
    i = 0;
    while(ev > 0) {
        if((int)cnt0.size() > i) {
            cerr << cnt0[i] << endl;
            if(ev >= cnt0[i]) {
                ev -= cnt0[i];
                ans -= 1;
                ++i;
            } else break;
        } else break;
    }
    i = 0;
    while(od > 0) {
        if((int)cnt11.size() > i) {
            if(od >= cnt11[i]) {
                od -= cnt11[i];
                ans -= 2;
                ++i;
            } else break;
        }
        else break;
    }
    i = 0;
    while(od > 0) {
        if((int)cnt1.size() > i) {
            if(od >= cnt1[i]) {
                od -= cnt1[i];
                ans -= 1;
                ++i;
            } else break;
        } else {
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}