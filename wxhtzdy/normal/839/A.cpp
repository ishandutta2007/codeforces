#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  scanf("%i%i", &N, &K);
  int A[N], C=0;
  for (int i=0;i<N;i++) scanf("%i", &A[i]);
  for (int i=0;i<N;i++) {
    C+=A[i];
    int T=min(8, C);
    C-=T; K-=T;
    if (K<=0) {
      printf("%i", i+1);
      return 0; 
    }
  }
  printf("-1");
}