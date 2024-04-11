#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
long long t1;
bool p[1000005];

int main() {
  for (int i = 2; i <= 1000; ++i) {
    if (!p[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        p[j] = true;
      }
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &t1);
    long long t2 = (long long)(sqrt((double)t1) + 1e-4);
    if (t1 != 1 && t2 * t2 == t1 && !p[t2]) puts("YES"); else puts("NO");
  }
  return 0;
}