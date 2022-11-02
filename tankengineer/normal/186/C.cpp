//1182C
#include<cstdio>
#include<algorithm>
using namespace std;

const long long modu = 1000000007;
const long long ma2[2][2] = {3, 1, 1, 3};

long long n, l, s[105], t1, t2, t3, t4, ma[2][2], ans;

int main() {
  scanf("%I64d", &n);
  if (n == 0) {
    puts("1");
    return 0;
  }
  ma[0][0] = 1; ma[0][1] = 0; ma[1][0] = 0; ma[1][1] = 1;
  l = 0;
  while (n) {
    s[++l] = n % 2;
    n /= 2;
  }
  for (int i = l; i > 0; i--) {
    t1 = (ma[0][0] * ma[0][0] + ma[0][1] * ma[1][0]) % modu;
    t2 = (ma[0][0] * ma[0][1] + ma[0][1] * ma[1][1]) % modu;
    t3 = (ma[0][0] * ma[1][0] + ma[1][1] * ma[1][0]) % modu;
    t4 = (ma[1][1] * ma[1][1] + ma[0][1] * ma[1][0]) % modu;
    ma[0][0] = t1;
    ma[0][1] = t2;
    ma[1][0] = t3;
    ma[1][1] = t4;
    if (s[i]) {
      t1 = (ma[0][0] * ma2[0][0] + ma[0][1] * ma2[1][0]) % modu;
      t2 = (ma[0][0] * ma2[0][1] + ma[0][1] * ma2[1][1]) % modu;
      t3 = (ma2[0][0] * ma[1][0] + ma[1][1] * ma2[1][0]) % modu;
      t4 = (ma[1][1] * ma2[1][1] + ma2[0][1] * ma[1][0]) % modu;
      ma[0][0] = t1;
      ma[0][1] = t2;
      ma[1][0] = t3;
      ma[1][1] = t4;      
    }
  }
  ans = ma[0][0];
  printf("%I64d\n", ans);
  return 0;
}