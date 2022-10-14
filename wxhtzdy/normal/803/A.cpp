#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  scanf("%i%i", &N, &K);
  int A[N][N];
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      A[i][j]=0;
    }
  }
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      int T=1-A[i][j]+1-A[j][i];
      if (i==j) {
        T-=1-A[i][j];
      }
      if (K>=T) {
        A[i][j]=A[j][i]=1;
        K-=T;
      }
    }
  }
  if (K>0) {
    printf("-1");
    return 0;
  }
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      printf("%i ", A[i][j]);
    }
    printf("\n");
  }
}