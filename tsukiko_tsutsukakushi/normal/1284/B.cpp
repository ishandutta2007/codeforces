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
	int n; cin >> n;
    vector<tuple<int, int, int>> vec;
    int cnt = 0;
    rep(i, n) {
        int l; cin >> l;
        int bf = INF;
        bool check = 1;
        vector<int> s(l);
        rep(j, l) {
            int x; cin >> x;
            s[j] = x;
            if(bf < x) check = 0;
            bf = x;
        }
        if(check) {
            vec.push_back(make_tuple(s[0], 0, cnt));
            vec.push_back(make_tuple(s[l - 1], 1, cnt));
            ++cnt;
        }
    }
    sort(all(vec));
    reverse(all(vec));
    int sz = vec.size();
    sz /= 2;
    int res = 0;
    cerr << sz << endl;
    for(auto& t: vec) {
        int i = get<2>(t), num = get<1>(t);
        if(num == 0) sz --;
        if(num == 1) res += sz;
    }
    cout << n * n - res << endl;
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