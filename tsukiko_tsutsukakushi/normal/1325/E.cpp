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

// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> mebius;
    vector<int> min_factor;

    Eratos(int MAX) : primes(),
                      isprime(MAX+1, true),
                      mebius(MAX+1, 1),
                      min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        primes.push_back(1);
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            mebius[i] = -1;
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if ((j / i) % i == 0) mebius[j] = 0;
                else mebius[j] = -mebius[j];
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    // prime factorization
    vector<pair<int,int>> prime_factors(int n) {
        vector<pair<int,int> > res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }

    // enumerate divisors
    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = prime_factors(n);
        for (auto p : pf) {
            int n = (int)res.size();
            for (int i = 0; i < n; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

int n;
vector<int> a;
vector<vector<int>> g;

void solve() {
	cin >> n;
    a.resize(n);
    Eratos er(1000000);
    //auto pr = er.primes;
    //int sz = (int)pr.size();
    vector<int> ps;
    set<int> se;
    int j = 1;
    map<int, int> mp;
    map<int, int> mp2;
    vector<int> y(0);
    g.push_back(y);
    rep(i, n) {
        //cin >> a[i];
        scanf("%d", &a[i]);
        if(a[i] == 1) {
            cout << 1 << endl;
            return;
        }
        auto pf = er.prime_factors(a[i]);
        if(pf.size() == 1) {
            if(pf[0].sc % 2 == 0) {
                cout << 1 << endl;
                return;
            } else {
                int p = pf[0].fr, k;
                if(se.find(p) == se.end()) {
                    se.insert(p);
                    mp[p] = j;
                    mp2[j] = p;
                    k = j;
                    vector<int> x(0);
                    g.push_back(x);
                    ++ j;
                } else {
                    k = mp[p];
                }
                g[k].pb(0);
                g[0].pb(k);
            }
        } else {
            vector<int> ps;
            for(auto e: pf) {
                if(e.sc % 2 == 0) {
                    continue;
                } else {
                    int k, p = e.fr;
                    if(se.find(p) == se.end()) {
                        se.insert(p);
                        mp[p] = j;
                        mp2[j] = p;
                        k = j;
                        vector<int> x(0);
                        g.push_back(x);
                        ++ j;
                    } else {
                        k = mp[p];
                    }
                    ps.pb(k);
                }
            }
            if(ps.size() == 0) {
                cout << 1 << endl;
                return;
            } else if(ps.size() == 1) {
                int k = ps[0];
                g[k].pb(0);
                g[0].pb(k);
            } else {
                int k = ps[0], l = ps[1];
                //cerr << k << " " << l << endl;
                g[k].pb(l);
                g[l].pb(k); 
            }
        }
    }
    int ans = inf;
    int sz = g.size();
    //cerr << sz << endl;
    //assert(sz * sz <= 1000000);
    rep(s, sz) {
        if(mp2[s] > 1000) continue;
        vector<int> dist(sz, inf);
        vector<bool> used(sz, false);
        queue<P> que;
        que.push({s, -1});
        used[s] = 1;
        dist[s] = 0;
        while(!que.empty()) {
            P p = que.front(); que.pop();
            int v = p.fr, pa = p.sc;
            bool flag = 0;
            for(auto nv: g[v]) {
                if(nv == pa && !flag) {
                    flag = 1;
                    continue;
                }
                if(!used[nv]) {
                    //chmin(dist[nv], dist[v] + 1);
                    if(dist[nv] > dist[v] + 1) {
                        dist[nv] = dist[v] + 1;
                        que.push({nv, v});
                        used[nv] = 1;
                    }
                } else {
                    if(ans > dist[nv] + dist[v] + 1) {
                        ans = dist[nv] + dist[v] + 1;
                    }
                }
            }
        }
    }
    if(ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}