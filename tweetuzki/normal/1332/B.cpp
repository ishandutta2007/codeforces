#include <algorithm>
#include <cstdio>
#include <cstring>
 
const int MaxN = 1000;
const int M = 11, Prs[M + 1] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
 
int Te, N;
int A[MaxN + 5], MnP[MaxN + 5];
int Have[M + 1];
 
int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    memset(Have, 0, sizeof Have);
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &A[i]);
      for (int j = 1; j <= M; ++j)
        if (A[i] % Prs[j] == 0) {
          MnP[i] = j;
          Have[j] = 1;
          break;
        }
    }
    for (int i = 1; i <= M; ++i) Have[i] += Have[i - 1];
    printf("%d\n", Have[M]);
    for (int i = 1; i <= N; ++i) printf("%d%c", Have[MnP[i]], " \n"[i == N]);
  }
  return 0;
}