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
const ll INF=1e16 + 1;
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

const string cf = "codeforces";

void solve() {
	ll k; cin >> k;
    if(k == 1) {
        cout << "codeforces" << endl;
        return;
    }
    int now = 1;
    for(int i = 1; i <= 40; ++ i) {
        int res = 1LL;
        bool ok = 0;
        rep(j, 10) {
            res *= (ll)i;
            if(res >= k) {
                now = i;
                ok = 1;
                break;
            }
        }
        if(ok) {
            now = i;
            break;
        }
    }
    int cnt = 0;
    for(int j = 9; j >= 0; -- j) {
        int res = 1LL;
        rep(i, j) {
            res *= (ll)(now - 1);
        }
        rep(i, 10 - j) {
            res *= (ll)now;
        }
        if(res >= k) {
            cnt = j;
            break;
        }
    }
    rep(i, cnt) {
        rep(j, now - 1) {
            cout << cf[i];
        }
    }
    rep(i, 10 - cnt) {
        rep(j, now) {
            cout << cf[cnt + i];
        }
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}