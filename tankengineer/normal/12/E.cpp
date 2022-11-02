//12E
#include<cstdio>
#include<algorithm>

using namespace std;

int n, ma[1005][1005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ma[i][j] = (i == j) ? 0 : 1 + (i == n - 1 || j == n - 1 ? 2 * i + 2 * j : i + j) % (n - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      printf("%d ", ma[i][j]);
    }
    printf("%d\n", ma[i][n - 1]);
  }
  return 0;
}