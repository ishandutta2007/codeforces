#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void point(int x, int y) {
  printf("%d %d\n", x, y);
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%d\n", 3*(N+1) + 1);
  for(int i = 0; i <= N; i++) {
    point(i, i);
    point(i, i+1);
    point(i+1, i);
  }
  point(N+1, N+1);
  return 0;
}