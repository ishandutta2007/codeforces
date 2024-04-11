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

int n;
vector<vector<int>> a;

void solve() {
	cin >> n;
    a.assign(2, vector<int>(n));
    vector<vector<int>> pos(n, vector<int>());
    rep(i, 2) {
        rep(j, n) {
            cin >> a[i][j];
            -- a[i][j];
            pos[a[i][j]].push_back(j);
        }
    }
    vector<int> cnt(n, 0);
    rep(i, 2) {
        rep(j, n) {
            cnt[a[i][j]] ++;
        }
    }
    rep(i, n) {
        if(cnt[i] != 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<bool> used(n, 0);
    set<int> ans;
    rep(i, n) {
        if(used[i]) continue;
        used[i] = 1;
        int st = pos[i][0], to = pos[i][1];
        if(st == to) {
            continue;
        }
        set<int> se[2];
        rep(j, 2) {
            if(a[j][st] == i) se[j].insert(st);
        }
        int cur = i;
        //cerr << st << " " << to << endl;
        while(st != to) {
            rep(j, 2) {
                if(a[j][to] != cur) {
                    se[j].insert(to);
                    cur = a[j][to];
                    used[cur] = 1;
                    break;
                }
            }
            to = (pos[cur][0] == to ? pos[cur][1] : pos[cur][0]);
            //cerr << cur << " " << to << endl;
        }
        // cerr << se[0].size() << " " << se[1].size() << endl;
        if(se[0].size() > se[1].size()) {
            for(int x: se[1]) {
                ans.insert(x);
            }
        } else {
            for(int x: se[0]) {
                ans.insert(x);
            }
        }
    }
    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x + 1 << " ";
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