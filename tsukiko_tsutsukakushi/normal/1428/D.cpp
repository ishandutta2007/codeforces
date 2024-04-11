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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<P> ans;
    set<P> se23;
    set<P> se3;
    per(i, n) {
        if(a[i] == 1) {
            ans.push_back({i, i});
            se23.insert({i, i});
        } else if(a[i] == 2) {
            if(se23.empty()) {
                cout << -1 << endl;
                return;
            }
            auto ite = se23.begin();
            ans.push_back({(*ite).fr, i});
            se23.erase(ite);
            se3.insert({(*ite).fr, i});
        } else if(a[i] == 3) {
            if(se3.empty() and se23.empty()) {
                cout << -1 << endl;
                return;
            }
            if(se3.size()) {
                auto ite = se3.begin();
                ans.push_back({i, i});
                ans.push_back({i, (*ite).sc});
                se3.erase(ite);
                se3.insert({i, i});
            } else {
                auto ite = se23.begin();
                ans.push_back({i, i});
                ans.push_back({i, (*ite).sc});
                se23.erase(ite);
                se3.insert({i, i});
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(auto p: ans) {
        cout << p.fr + 1 << " " << p.sc + 1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}