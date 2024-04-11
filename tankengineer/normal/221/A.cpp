#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  printf("%d", n);
  for (int i = 1; i < n; ++i) printf(" %d", i);
  printf("\n");
  return 0;
}