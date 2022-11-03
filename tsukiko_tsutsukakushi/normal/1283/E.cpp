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
    vector<int> x(n);
    vector<int> cnt(n + 2, 0);
    rep(i, n) {
        cin >> x[i];
        cnt[x[i]] ++;
    }
    sort(all(x));
    //min
    vector<int> cntmi(n + 2, 0);
    vector<int> mi(n);
    rep(i, n) {
        if(cntmi[x[i] - 1] > 0) {
            cntmi[x[i] - 1] ++;
            mi[i] = x[i] - 1;
        } else if(cntmi[x[i]] > 0) {
            cntmi[x[i]] ++;
            mi[i] = x[i];
        } else {
            cntmi[x[i] + 1] ++;
            mi[i] = x[i] + 1;
        }
    }
    set<int> se;
    rep(i, n) {
        se.insert(mi[i]);
    }
    cout << se.size() << " ";
    //max
    vector<int> cntma(n + 2, 0);
    vector<int> ma(n);
    rep(i, n) {
        if(cntma[x[i] - 1] == 0) {
            cntma[x[i] - 1] ++;
            ma[i] = x[i] - 1;
        }else if(cntma[x[i]] == 0) {
            cntma[x[i]] ++;
            ma[i] = x[i];
        }else {
            cntma[x[i] + 1] ++;
            ma[i] = x[i] + 1;
        }
    }
    se.clear();
    rep(i, n) {
        se.insert(ma[i]);
    }
    cout << se.size() << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}