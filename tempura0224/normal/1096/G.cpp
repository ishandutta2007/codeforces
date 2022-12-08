#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;


template< int mod, int primitiveroot >
struct NumberTheoreticTransform {
  vector< vector< int > > rts, rrts;
  void ensure_base(int N) {
    if(rts.size() >= N) return;
    rts.resize(N), rrts.resize(N);
    for(int i = 1; i < N; i <<= 1) {
      if(rts[i].size()) continue;
      int w = mod_pow(primitiveroot, (mod - 1) / (i * 2));
      int rw = inverse(w);
      rts[i].resize(i), rrts[i].resize(i);
      rts[i][0] = 1, rrts[i][0] = 1;
      for(int k = 1; k < i; k++) {
        rts[i][k] = mul(rts[i][k - 1], w);
        rrts[i][k] = mul(rrts[i][k - 1], rw);
      }
    }
  }

  inline int mod_pow(int x, int n) {
    int ret = 1;
    while(n > 0) {
      if(n & 1) ret = mul(ret, x);
      x = mul(x, x);
      n >>= 1;
    }
    return ret;
  }

  inline int inverse(int x) {
    return mod_pow(x, mod - 2);
  }

  inline int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
  }

  inline int mul(int a, int b) {
    return int(1LL * a * b % mod);
  }

  void DiscreteFourierTransform(vector< int > &F, bool rev) {
    const int N = (int) F.size();
    ensure_base(N);
    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          int s = F[j + k], t = mul(F[j + k + i], rev ? rrts[i][k] : rts[i][k]);
          F[j + k] = add(s, t), F[j + k + i] = add(s, mod - t);
        }
      }
    }
    if(rev) {
      int temp = inverse(N);
      for(int i = 0; i < N; i++) F[i] = mul(F[i], temp);
    }
  }

  vector< int > Multiply(const vector< int > &A, const vector< int > &B) {
    int sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< int > F(sz), G(sz);
    for(int i = 0; i < A.size(); i++) F[i] = A[i];
    for(int i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(int i = 0; i < sz; i++) F[i] = mul(F[i], G[i]);
    DiscreteFourierTransform(F, true);
    F.resize(A.size() + B.size() - 1);
    return F;
  }
};



int main(){
    int n;
    cin>>n;
    n/=2;
    int k;
    cin>>k;
    vector<int> a(10);
    rep(i,k){
        int x;cin>>x;
        ++a[x];
    }
    vector<int> ret(1);
    NumberTheoreticTransform<998244353,3> ntt;
    ret[0]=1;
    int s=n;
    while(s){
        if(s&1)ret=ntt.Multiply(ret, a);
        a=ntt.Multiply(a, a);
        s/=2;
    }
    ll ans =0;
    for(auto e: ret){
        ans+=(ll)e*e%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}