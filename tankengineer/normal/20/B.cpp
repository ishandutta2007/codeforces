//20B
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

long long a, b, c, d;
double ans, ans1, ans2;

int main() {
  scanf("%I64d %I64d %I64d", &a, &b, &c);
  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        puts("-1");
      } else {
        puts("0");
      }
    } else {
      puts("1");
      ans = (double)(-c) / (double)(b);
      printf("%.12lf\n", ans);
    }
  } else {
    d = b * b - 4 * a * c;
    if (d < 0) {
      puts("0");
    } else if (d == 0) {
      puts("1");
      ans = (double)(-b) / (double)(2 * a);
      printf("%.12lf\n", ans);
    } else {
      puts("2");
      ans1 = ((double)(-b) + sqrt((double)(d))) / (double)(2 * a);
      ans2 = ((double)(-b) - sqrt((double)(d))) / (double)(2 * a);
      if (ans2 < ans1) {
        swap(ans1, ans2);
      } 
      printf("%.12lf\n%.12lf\n", ans1, ans2);
    }
  }
  return 0;
}