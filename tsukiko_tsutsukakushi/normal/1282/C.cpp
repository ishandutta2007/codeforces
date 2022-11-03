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
#define int long long

void solve() {
	int n, t, a, b;
    cin >> n >> t >> a >> b;
    vector<P> p(n);
    int cnt0 = 0, cnt1 = 0;
    rep(i, n) {
        cin >> p[i].sc;
        if(p[i].sc == 0) {
            cnt0 ++;
        } else {
            cnt1 ++;
        }
    }
    rep(i, n) {
        cin >> p[i].fr;
    }
    sort(all(p));
    int acnt = 0, bcnt = 0;
    int ans = 0;
    rep(i, n) {
        if(acnt * a + bcnt * b <= p[i].fr - 1) {
            int cnt = acnt + bcnt, t_ = p[i].fr - 1 - a * acnt - b * bcnt;
            cnt += min(cnt0 - acnt, t_ / a); t_ -= min(cnt0 - acnt, t_ / a) * a;
            cnt += min(cnt1 - bcnt, t_ / b); t_ -= min(cnt1 - bcnt, t_ / b) * b;
            chmax(ans, cnt);
        }
        while(i + 1 < n && p[i].fr == p[i + 1].fr) {
            if(p[i].sc == 0) ++acnt;
            else ++bcnt;
            ++i;
        }
        if(p[i].sc == 0) ++acnt;
        else ++bcnt;
        //cerr << "    " <<  acnt * a + bcnt * b << "  " << p[i].fr << endl;
        if(acnt * a + bcnt * b <= p[i].fr) {
            int cnt = acnt + bcnt, t_ = p[i].fr - a * acnt - b * bcnt;
            cnt += min(cnt0 - acnt, t_ / a); t_ -= min(cnt0 - acnt, t_ / a) * a;
            cnt += min(cnt1 - bcnt, t_ / b); t_ -= min(cnt1 - bcnt, t_ / b) * b;
            chmax(ans, cnt);
        }
    }
    if(acnt * a + bcnt * b <= t) {
        int cnt = acnt + bcnt, t_ = t - a * acnt - b * bcnt;
        cnt += min(cnt0 - acnt, t_ / a); t_ -= min(cnt0 - acnt, t_ / a) * a;
        cnt += min(cnt1 - bcnt, t_ / b); t_ -= min(cnt1 - bcnt, t_ / b) * b;
        chmax(ans, cnt);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	int m; cin >> m; rep(i, m)solve();
	//solve();
	//cout << "finish" << endl;
    return 0;
}