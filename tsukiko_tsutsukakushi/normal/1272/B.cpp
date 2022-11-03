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
	string s; cin >> s;
    int n = (int)s.size();
    int cntl = 0, cntd = 0, cntr = 0, cntu = 0;
    rep(i, n) {
        if(s[i] == 'L') {
            cntl ++;
        } else if(s[i] == 'D') {
            cntd ++;
        } else if(s[i] == 'R') {
            cntr ++;
        } else {
            cntu ++;
        }
    }
    int cntlr = min(cntl, cntr), cntud = min(cntd, cntu);
    //cout << (cntlr + cntud) * 2 << endl;
    //cntlr == 0 || cntud == 0
    if(cntlr != 0 && cntud != 0) {
        cout << (cntlr + cntud) * 2 << endl;
        rep(i, cntlr) cout << "L";
        rep(i, cntud) cout << "D";
        rep(i, cntlr) cout << "R";
        rep(i, cntud) cout << "U";
        cout << endl;
    } else if(cntlr == 0) {
        if(cntud == 0) {
            cout << 0 << endl << endl;
        } else {
            cout << 2 << endl;
            cout << "UD" << endl;
        }
    } else {
        cout << 2 << endl;
        cout << "LR" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	//cout << "finish" << endl;
    return 0;
}