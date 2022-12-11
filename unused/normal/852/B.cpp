#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

typedef vector<vector<ll>> mat;

mat mult(const mat& A, const mat& B){
  const int N = A.size(), M = B.size(), K = B.back().size();

  mat ret(N, vector<ll>(K));
  for(int i=0;i<N;i++) for(int j=0;j<M;j++) for(int k=0;k<K;k++){
    ret[i][k] = (ret[i][k] + A[i][j] * B[j][k]) % MOD;
  }

  return ret;
}

mat mpow(const mat& A, int y){
  const int N = A.size();
  if(y==0){
    mat ret(N, vector<ll>(N));
    for(int i=0;i<N;i++) ret[i][i] = 1;
    return ret;
  }

  if(y%2){
    return mult(A, mpow(A, y-1));
  }
  else{
    auto AA = mpow(A, y/2);
    return mult(AA,AA);
  }
}

int N, L, M;
const int NMAX = 1000000;
int fi[NMAX], layer[NMAX], ed[NMAX];
int D[100];
ll v[100], u[100];

int main(){
  scanf("%d%d%d",&N,&L,&M);
  for(int i=0;i<N;i++) scanf("%d",fi+i);
  for(int i=0;i<N;i++) scanf("%d",layer+i);
  for(int i=0;i<N;i++) scanf("%d",ed+i);

  for(int i=0;i<N;i++) D[layer[i]%M]++;

  mat A(M, vector<ll>(M));
  for(int i=0;i<M;i++) for(int j=0;j<M;j++){
    int cur = (i-j+M)%M;
    A[i][j] = D[cur];
  }

  for(int i=0;i<N;i++) v[fi[i]%M]++;

  auto B = mpow(A, L-2);

  for(int i=0;i<M;i++) for(int j=0;j<M;j++){
    u[i] = (u[i] + B[i][j]*v[j]%MOD)%MOD;
  }

  ll ans = 0;
  for(int i=0;i<N;i++){
    int cost = (layer[i] + ed[i])%M;
    cost = (M - cost)%M;
    ans = (ans + u[cost])%MOD;
  }

  printf("%lld", ans);
}