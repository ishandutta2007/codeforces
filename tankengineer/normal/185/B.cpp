#include<cstdio>
#include<algorithm>
using namespace std;

double s, a, b, c;

int main() {
  scanf("%lf %lf %lf %lf", &s, &a, &b, &c);
  if (a + b + c < 1e-5) {
    puts("0.0 0.0 0.0");
    return 0;
  }
  printf("%.12lf %.12lf %.12lf\n", s * a / (a + b + c), s * b / (a + b + c), s * c / (a + b + c));
  return 0;
}