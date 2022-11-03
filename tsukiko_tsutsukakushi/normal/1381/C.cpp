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
	int n, x, y; cin >> n >> x >> y;
    vector<int> b(n);
    vector<set<int>> col(n + 1, set<int>());
    rep(i, n) {
        cin >> b[i];
        -- b[i];
        col[b[i]].insert(i);
    }
    vector<int> a(n, -1);
    priority_queue<P> pque;
    int noused = -1;
    rep(i, n + 1) {
        if(col[i].empty()) noused = i;
        else pque.push(P{(int)col[i].size(), i});
    }
    rep(i, x) {
        P p = pque.top(); pque.pop();
        int c = p.sc;
        int j = *col[c].begin(); col[c].erase(j);
        a[j] = b[j];
        if(!col[c].empty()) pque.push(P{(int)col[c].size(), c});
    }
    int f = (pque.empty() ? 0 : pque.top().fr);
    if(2 * (n - x - f) < y - x) {
        cout << "NO" << endl;
        return;
    }
    priority_queue<P, vector<P>, greater<P>> pque1;
    while(!pque.empty()) {
        pque1.push(pque.top());
        pque.pop();
    }
    int l = min(2 * (n - x - f), n - x);
    vector<P> d(l);
    vector<int> cnt(n + 1, 0);
    rep(i, l) {
        P p = pque1.top(); pque1.pop();
        int c = p.sc;
        ++ cnt[c];
        int j = *col[c].begin(); col[c].erase(j);
        if(!col[c].empty()) pque1.push(P{(int)col[c].size(), c});
        d[i] = P{c, j};
        //cerr << c << " " << j << endl;
    }
    sort(all(d));
    int len = l / 2;
    rep(i, y - x) {
        a[d[(i + len) % l].sc] = d[i].fr;
    }
    rep(i, n) {
        if(a[i] == -1) {
            a[i] = noused;
        }
    }
    cout << "YES" << endl;
    rep(i, n) {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}