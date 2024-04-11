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
	string s; cin >> s;
    int n = (int)s.size();
    vector<string> vec;
    map<string, int> mp;
    int cnt = 0;
    rep(i, 26) {
        rep(j, 26) {
            rep(k, 26) {
                char a = 'a' + i, b = 'a' + j, c = 'a' + k;
                string t = "";
                t += a, t += b, t += c;
                vec.pb(t);
                mp[t] = cnt;
                ++cnt;
            }
        }
    }
    cout << "? ";
    rep(i, n) {
        cout << vec[i][0];
    }
    cout << endl;
    fflush(stdout);
    string x; cin >> x;
    cout << "? ";
    rep(i, n) {
        cout << vec[i][1];
    }
    cout << endl;
    fflush(stdout);
    string y; cin >> y;
    cout << "? ";
    rep(i, n) {
        cout << vec[i][2];
    }
    cout << endl;
    fflush(stdout);
    string z; cin >> z;
    vector<int> d(n);
    map<int, int> rev;
    rep(i, n) {
        string q = "";
        q += x[i], q += y[i], q += z[i];
        d[i] = mp[q];
        rev[d[i]] = i;
    }
    string ans = "";
    rep(i, n) {
        ans += s[rev[i]];
    }
    cout << "! " << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}