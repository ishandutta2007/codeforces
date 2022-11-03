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

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
    vector<bool> isprime;
    vector<int> min_factor;

    Eratos(int MAX) :
                      isprime(MAX+1, true),
                      min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    // prime factorization
    vector<int> prime_factors(int n) {
        vector<int > res;
        while (n != 1) {
            int prime = min_factor[n];
            while (min_factor[n] == prime) {
                n /= prime;
            }
            res.push_back(prime);
        }
        return res;
    }
};

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    int d = 0;
    rep(i, n) {
        cin >> a[i];
        d = gcd(d, a[i]);
    }
    int ma = 0;
    rep(i, n) {
        a[i] /= d;
        chmax(ma, a[i]);
    }
    Eratos er(ma);
    map<int, int> mp;
    rep(i, n) {
        auto pf = er.prime_factors(a[i]);
        for(int p: pf) {
            mp[p] ++;
        }
    }
    int res = 0;
    for(auto p: mp) {
        chmax(res, p.sc);
    }
    if(res == 0) cout << -1 << endl;
    else cout << n - res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}