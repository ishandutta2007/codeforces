#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

ll MOD;

ll MOD_p;

const int NMAX = 1000123;
ll comb[NMAX+1]; // MC0, ..., MCN-1 % MOD_p
ll MOD_pinv[NMAX+1];
ll psum[NMAX+1];
ll Bpow[NMAX+1];

int main(){
  int N, M, B, Q; scanf("%d%d%d%d",&N,&M,&B,&Q);
  MOD = Q; // mod.
  MOD_p = 1;
  ll tmp = B;
  while(1){
    tmp = tmp * B % Q;
    MOD_p++;
    if(tmp==1) break;
  }

  MOD_pinv[1] = 1;
  for(int i=2;i<N;i++) MOD_pinv[i] = (MOD_p - MOD_p/i) * MOD_pinv[MOD_p%i] % MOD_p;

  comb[0] = 1;
  for(int i=1;i<N;i++){ // MCi = 
    if(i>M) continue;
    comb[i] = comb[i-1] * (M-i+1) % MOD_p;
    comb[i] = comb[i] * MOD_pinv[i] % MOD_p;
  }

  psum[0] = comb[0];
  for(int i=1;i<N;i++) psum[i] = (psum[i-1] + comb[i])%MOD_p;

  Bpow[0] = 1;
  for(int i=1;i<=NMAX;i++) Bpow[i] = Bpow[i-1]*B%MOD;

  for(int i=0;i<N;i++){
    ll p = psum[N-i-1];
    // B^p = ?
    printf("%lld ", Bpow[p]%MOD);
  }
}