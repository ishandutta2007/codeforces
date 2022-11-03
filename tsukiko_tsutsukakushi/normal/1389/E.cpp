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

int m, d, w;

void solve() {
	cin >> m >> d >> w;
    map<int, int> mp;
    int w_ = w;
    for(int i = 2; i * i <= w_; ++ i) {
        while(w_ % i == 0) {
            mp[i] ++;
            w_ /= i;
        }
    }
    if(w_ != 1) mp[w_] ++;
    int e = d - 1;
    if(e == 0) {
        cout << (min(m, d) * min(m, d) - min(m, d)) / 2 << endl;
        return;
    }
    for(int i = 2; i * i <= e; ++ i) {
        while(e % i == 0) {
            if(mp[i] > 0) mp[i] --;
            e /= i;
        }
    }
    if(e != 1) {
        if(mp[e] > 0) mp[e] --;
    }
    int q = 1;
    for(P p: mp) {
        rep(j, p.sc) {
            q *= p.fr;
        }
    }
    //cerr << "q = " << q << endl;
    if(q == 1) {
        cout << (min(m, d) * min(m, d) - min(m, d)) / 2 << endl;
    } else {
        int ans = 0;
        int cnt1 = (min(m, d) + q - 1) / q, cnt2 = cnt1 - 1;
        int amari = (min(m, d) % q == 0 ? q : min(m, d) % q);
        cout << cnt1 * (cnt1 - 1) / 2 * amari + cnt2 * (cnt2 - 1) / 2 * (q - amari) << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}