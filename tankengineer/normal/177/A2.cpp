//177A
#include<cstdio>
#include<algorithm>
using namespace std;

int sum, n, t1;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &t1);
      if (i == j || i + j == 1 + n || i == (1 + n) / 2 || j == (1 + n) / 2) sum += t1;
    }
  }
  printf("%d\n", sum);  
  return 0;
}