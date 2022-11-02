#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s1[1000020], s2[1000026];
int l1, l2, ans, t1, t2;

int main() {
  scanf("%s %s", s1, s2);
  l1 = strlen(s1); l2 = strlen(s2);
	t1 = 0; t2 = l2;
	while (s1[t1] == s2[t1]) ++t1;
	while (s1[t2 + 1] == s2[t2] && t2 >= 0) --t2;
	printf("%d\n", t1 > t2 ? t1 - t2 : 0);
	for (int i = t2 + 1; i <= t1; ++i) printf("%d ", i + 1);
	return 0;
}