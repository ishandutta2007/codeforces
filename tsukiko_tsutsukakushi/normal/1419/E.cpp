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
#define pb emplace_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
	cin >> n;
    vector<int> div;
    map<int, int> mp;
    for(int i = 2; i * i <= n; ++ i) {
        if(n % i == 0) {
            div.pb(i);
            if(i * i != n) div.pb(n / i);
        }
    }
    div.pb(n);
    sort(all(div));
    int n_ = n;
    vector<int> pf;
    for(int i = 2; i * i <= n_; ++ i) {
        if(n_ % i == 0) pf.pb(i);
        while(n_ % i == 0) {
            mp[i] ++;
            n_ /= i;
        }
    }
    if(n_ != 1) {
        pf.pb(n_);
        mp[n_] ++;
    }
    sort(all(pf));
    vector<int> ans;
    map<int, bool> used;
    rep(i, (int)pf.size()) {
        int p = pf[i];
        int now = 1LL;
        rep(j, mp[p]) {
            now *= p;
            ans.pb(now);
            used[now] = 1;
        }
        // if(i != (int)pf.size() - 1) {
            int nxtp = pf[(i + 1) % (int)pf.size()];
            int sp = p * nxtp;
            for(int x: div) {
                if(!used[x] and x % sp != 0 and x % p == 0 and x != n) {
                    ans.pb(x);
                    used[x] = 1;
                }
            }
            for(int x: div) {
                if(!used[x] and x % sp == 0 and x != n) {
                    ans.pb(x);
                    used[x] = 1;
                }
            }
        // } 
        if(i == (int)pf.size() - 1 and !used[n]) {
            ans.pb(n);
            // for(int x: div) {
            //     if(!used[x]) {
            //         cerr << "x = " << x << endl;
            //         ans.pb(x);
            //         used[x] = 1;
            //     }
            // }
            used[n] = 1;
        }
    }
    int cnt = 0;
    rep(i, (int)ans.size()) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        if(gcd(ans[i], ans[(i + 1 + (int)ans.size()) % (int)ans.size()]) == 1) ++ cnt;
    }
    assert((int)div.size() == (int)ans.size());
    // assert(cnt <= 1);
    cout << cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}