#include<cstdio>
#include<algorithm>
using namespace std;

int a, b, c, x, y, z;

int sqrt(const int i) {
  if (i == 1) return 1;
	int t1 = i / 2, t2 = 2;
  while (t1 != t2) {
	  t1 = (t1 + t2) / 2;
	  t2 = i / t1;
	}
	return t1;
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	x = a * b / c;
	y = a * c / b;
	z = b * c / a;
	printf("%d\n", 4 * (sqrt(x) + sqrt(y) + sqrt(z)));
	return 0;
}