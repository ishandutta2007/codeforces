#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  if (a != d && b != e && c != f) puts("NO"); else puts("YES");
	return 0;
}