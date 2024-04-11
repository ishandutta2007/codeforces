#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N], top;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  top = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) ++top;
  }
  if (top <= 2) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}