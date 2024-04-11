#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, t;
	char s[105];
	scanf("%d %d %s", &n, &t, s + 1);
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j != n && s[j] == 'B' && s[j + 1] == 'G') {
				swap(s[j], s[j + 1]);
				++j;
			}
		}
	}
	printf("%s\n", s + 1);
	return 0;
}