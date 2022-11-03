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
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

namespace NTT {
    const int MOD = 998244353;  // to be set appropriately
    const long long PR = 3;     // to be set appropriately
    
    void trans(vector<long long> &v, bool inv = false) {
        int n = (int)v.size();
        for (int i = 0, j = 1; j < n-1; j++) {
            for (int k = n>>1; k > (i ^= k); k >>= 1);
            if (i > j) swap(v[i], v[j]);
        }
        for (int t = 2; t <= n; t <<= 1) {
            long long bw = modpow(PR, (MOD-1)/t, MOD);
            if (inv) bw = modinv(bw, MOD);
            for (int i = 0; i < n; i += t) {
                long long w = 1;
                for (int j = 0; j < t/2; ++j) {
                    int j1 = i + j, j2 = i + j + t/2;
                    long long c1 = v[j1], c2 = v[j2] * w % MOD;
                    v[j1] = c1 + c2;
                    v[j2] = c1 - c2 + MOD;
                    while (v[j1] >= MOD) v[j1] -= MOD;
                    while (v[j2] >= MOD) v[j2] -= MOD;
                    w = w * bw % MOD;
                }
            }
        }
        if (inv) {
            long long inv_n = modinv(n, MOD);
            for (int i = 0; i < n; ++i) v[i] = v[i] * inv_n % MOD;
        }
    }
    
    // C is A*B
    vector<long long> mult(vector<long long> A, vector<long long> B) {
        int size_a = 1; while (size_a < A.size()) size_a <<= 1;
        int size_b = 1; while (size_b < B.size()) size_b <<= 1;
        int size_fft = max(size_a, size_b) << 1;
        
        vector<long long> cA(size_fft, 0), cB(size_fft, 0), cC(size_fft, 0);
        for (int i = 0; i < A.size(); ++i) cA[i] = A[i];
        for (int i = 0; i < B.size(); ++i) cB[i] = B[i];
        
        trans(cA); trans(cB);
        for (int i = 0; i < size_fft; ++i) cC[i] = cA[i] * cB[i] % MOD;
        trans(cC, true);
        
        vector<long long> res((int)A.size() + (int)B.size() - 1);
        for (int i = 0; i < res.size(); ++i) res[i] = cC[i];
        return res;
    }
};

void solve() {
	int n, k; cin >> n >> k;
    vector<ll> v(1<<22, 0);
    rep(i, k) {
        int d; cin >> d;
        v[d] = 1LL;
    }
    NTT::trans(v);
    // cerr << (int)v.size() << endl;
    vector<ll> each(1<<22, 1LL);
    rep(i, (1<<22)) {
        int x = n / 2;
        while(x > 0) {
            if(x & 1) each[i] = each[i] * v[i] % NTT::MOD;
            v[i] = v[i] * v[i] % NTT::MOD;
            x >>= 1;
        }
    }
    NTT::trans(each, true);
    ll res = 0;
    rep(i, (int)each.size()) {
        res += each[i] * each[i] % NTT::MOD;
        res %= NTT::MOD;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}