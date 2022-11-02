#include<cstdio>
#include<algorithm>
using namespace std;

int n, top, t1, t2;

int main() {
  scanf("%d", &n);
  scanf("%d", &top);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &t1, &t2);
    if (!(t1 != top && t2 != top && t1 != 7 - top && t2 != 7 - top)) {
      puts("NO");
      return 0;  
    }
  }
  puts("YES");
  return 0;
}