#include<cstdio>
#include<algorithm>

#define LL "%I64d"

using namespace std;

typedef long long ll;

int n, m;
ll C[1024][1024];
ll X[1024], Y[1024], S[1024];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      scanf(LL, &C[i][j]);
  
  for(int i=0; i<n; ++i) {
    S[i] = 0;
    for(int j=0; j<m; ++j)
      S[i] += C[i][j];
  }
  for(int i=0; i<=n; ++i) {
    Y[i] = 0;
    for(int j=0; j<n; ++j)
      Y[i] += S[j] * (ll)((4*j+2)-4*i)*((4*j+2)-4*i);
  }
  
  for(int i=0; i<m; ++i) {
    S[i] = 0;
    for(int j=0; j<n; ++j)
      S[i] += C[j][i];
  }
  for(int i=0; i<=m; ++i) {
    X[i] = 0;
    for(int j=0; j<m; ++j)
      X[i] += S[j] * (ll)((4*j+2)-4*i)*((4*j+2)-4*i);
  }
  
  int sX = 0, sY = 0;
  for(int i=0; i<=n; ++i)
    if(Y[sY] > Y[i]) sY = i;
  for(int j=0; j<=m; ++j)
    if(X[sX] > X[j]) sX = j;
  
  printf(LL "\n%d %d\n", X[sX]+Y[sY], sY, sX);
  return 0;
}