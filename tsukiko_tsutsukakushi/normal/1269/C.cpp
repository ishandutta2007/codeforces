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

string next(string s) {
    int n = (int)s.size();
    string res;
    int nxt = 0;
    per(i, n) {
        int c = s[i] - '0';
        if(i == n - 1) {
            if(c == 9) {
                res.pb('0');
                nxt = 1;
            } else {
                res.pb('0' + c + 1);
            }
        } else {
            c += nxt;
            if(c == 10) {
                res.pb('0');
                nxt = 1;
            } else {
                res.pb('0' + c);
                nxt = 0;
            }
        }
    }
    if(nxt == 1) {
        res.pb('1');
    }
    reverse(all(res));
    return res;
}

void solve() {
	int n, k; cin >> n >> k;
    string a; cin >> a;
    string s1 = a.substr(0, k);
    string s2 = next(s1);
    //99...9s1s1ok
    string b = "";
    rep(i, (n + k - 1) / k) {
        b += s1;
    }
    b = b.substr(0, n);
    if(b >= a) {
        cout << n << endl;
        cout << b << endl;
        return;
    }
    string c = "";
    rep(i, (n + k - 1) / k) {
        c += s2;
    }
    c = c.substr(0, n);
    if(c >= a) {
        cout << n << endl;
        cout << c << endl;
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