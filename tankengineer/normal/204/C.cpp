#include<cstdio>

int n;
char a[200005], b[200005];
double s, s1[27], s2[27];

int main() {
  scanf("%d%s%s", &n, a + 1, b + 1);
  for (int i = 1; i <= n; ++i) {
		a[i] -= 'A'; b[i] -= 'A';
		s2[b[i]] += i;
	  s += (n - i + 1) * (s2[a[i]] + s1[b[i]]);
	  s1[a[i]] += i;
	}
	printf("%.12lf\n", s * 6 / n / (n + 1) / (2 * n + 1));
	return 0;
}