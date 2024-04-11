#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n > 19) {
			printf("NO\n");
		} else {
			printf("YES\n");
			int d = 1;
			for (int i = 0; i < n; ++i) {
				printf("%d%c", d, i == n - 1 ? '\n' : ' ');
				d *= 3;
			}
		}
	}
	return 0;
}