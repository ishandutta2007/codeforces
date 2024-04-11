#include <cstdio>
 
int N, M, K;
int A[3][3];
 
int main() {
  scanf("%d", &K);
  N = 3, M = 3;
  A[0][1] = 131072;
  A[0][0] = A[0][2] = A[1][1] = A[1][2] = A[2][0] = A[2][1] = 262143;
  A[1][0] = A[2][2] = K;
  printf("%d %d\n", N, M);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      printf("%d%c", A[i][j], " \n"[j == M - 1]);
  return 0;
}