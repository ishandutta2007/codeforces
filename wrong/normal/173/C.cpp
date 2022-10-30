#include<cstdio>
#include<cstring>

int A[512][512], S[512][512], P[512][512];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      scanf("%d", &A[i][j]), S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+A[i][j];

  for(int i=1; i+2<=n; ++i)
    for(int j=1; j+2<=m; ++j)
      P[i][j] = A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+2]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];

  int sol = -1000000000;
  for(int k=3; k<=n && k<=m; k+=2) {
    for(int i=1; i+k-1<=n; ++i)
      for(int j=1; j+k-1<=m; ++j)
	if(sol < P[i][j]) sol = P[i][j];
    for(int i=1; i+k+1<=n; ++i)
      for(int j=1; j+k+1<=m; ++j)
	P[i][j] = S[i+k+1][j+k+1] - S[i+k+1][j-1] - S[i-1][j+k+1] + S[i-1][j-1] - A[i+1][j] - P[i+1][j+1];
  }

  printf("%d\n", sol);
  return 0;
}