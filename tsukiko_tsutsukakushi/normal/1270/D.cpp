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

int n, k;

int m = 3;

int a[4] = {2, 0, 1, 9};

int debug_query(set<int> x) {
    cout << "? ";
    vector<int> vec;
    for(auto& y: x) {
        cout << y + 1 << " ";
        vec.pb(a[y]);
    }
    cout << endl;
    sort(all(vec));
    return vec[m - 1];
}

int query(set<int> x) {
    //return debug_query(x);
    cout << "? ";
    for(auto& y: x) {
        cout << y + 1 << " ";
    }
    cout << endl;
    fflush(stdout);
    int pos, a;
    cin >> pos;
    if(pos == -1) exit(0);
    cin >> a;
    --pos;
    return a;
}

void solve() {
	cin >> n >> k;
    set<int> se;
    for(int i = 1; i <= k; ++i) {
        se.insert(i);
    }
    map<int, int> cnt;
    //debug_query(se);
    int x = query(se);
    cnt[x] ++;
    cerr << x << endl;
    for(int i = 1; i <= k; ++i) {
        se.insert(i - 1);
        se.erase(i);
        int y = query(se);
        //debug_query(se);
        cerr << y << endl;
        cnt[y] ++;
    }
    auto ite = cnt.begin();
    ++ite;
    cout << "! " << (*ite).sc << endl;
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