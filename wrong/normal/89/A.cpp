#include<cstdio>
#include<algorithm>

using namespace std;

int a[10000];
int main()
{
  int n, m, k, b = 100000;
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<n; ++i) {
    scanf("%d", &a[i]);
    if(i%2 == 0 && b > a[i]) b = a[i];
  }
  if(n == 1) {
    printf("%d\n", (int)min(1ll*a[0], 1ll*m*k));
    return 0;
  }
  if(n % 2 == 0) {
    puts("0");
    return 0;
  }
  m /= (n / 2 + 1);
  printf("%d\n", (int)min(1ll*b, 1ll*m*k));
  return 0;
}