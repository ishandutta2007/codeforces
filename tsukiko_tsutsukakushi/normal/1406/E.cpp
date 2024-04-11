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
// typedef pair<int, int> P;
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

const int MAX = 100000;
const int P = 100;

void solve() {
	int n; cin >> n;
    Eratos er(MAX);
    vector<int> primes;
    for(int i = 2; i <= n; ++ i) {
        if(er.isprime[i]) primes.push_back(i);
    }
    int cnt = (int)primes.size();
    vector<bool> exist(n + 1, 1);
    vector<int> pf;
    int sum = n;
    int q = 0;
    int now = 1;
    bool ok = 0;
    rep(i, (cnt + P - 1) / P) {
        int l = P * i, r = min(P * (i + 1), cnt);
        for(int j = l; j < r; ++ j) {
            if(now * primes[j] > n) break;
            assert(q <= 9999);
            cout << "B " << primes[j] << endl;
            ++ q;
            int res; cin >> res;
            int tmp = 0;
            for(int k = primes[j]; k <= n; k += primes[j]) {
                if(exist[k]) {
                    exist[k] = 0;
                    ++ tmp;
                    -- sum;
                }
            }
            if(res != tmp) {
                pf.push_back(primes[j]);
                now *= primes[j];
            }
        }
        assert(q <= 9999);
        cout << "A " << 1 << endl;
        ++ q;
        int res; cin >> res;
        if(res != sum and !ok) {
            for(int j = l; j < r; ++ j) {
                if(now * primes[j] > n) break;
                assert(q <= 9999);
                cout << "A " << primes[j] << endl;
                ++ q;
                int res;
                cin >> res;
                if(res == 1) {
                    pf.push_back(primes[j]);
                    now *= primes[j];
                    ok = 1;
                    break;
                }
            }
            sum = res;
        }
    }
    int ans = 1;
    for(int p: pf) {
        int now = p;
        while(now <= n) {
            assert(q <= 9999);
            cout << "A " << now << endl;
            ++ q;
            int res; cin >> res;
            if(res == 1) {
                ans *= p;
                now *= p;
            } else {
                break;
            }
        }
    }
    assert(q <= 9999);
    cout << "C " << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}