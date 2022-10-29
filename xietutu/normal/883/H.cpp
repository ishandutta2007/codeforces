#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;
char S[maxn], ans[maxn];
int a[maxn], A[maxn];
vector<int> F;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", S + 1);
	for (int i = 1; i <= n; ++i) {
		++A[S[i]];
	}
	int k = 0;
	for (int i = 1; i <= 150; ++i) {
		if (A[i] & 1) {
			++k;
			F.push_back(i);
			--A[i]; 
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			int len = n / i;
			int s = 0;
			if (len & 1) s = i;
			if (s >= k) {
				for (int i = 1; i <= 150; ++i) a[i] = A[i];
				printf("%d\n", i);
				int y = 150, x = 0, now = 0;
				for (int j = 1; j <= i; ++j) {
					for (int k = 1; k <= len / 2; ++k) {
						while (!a[y]) --y;
						a[y] -= 2;
						ans[k] = y;
						ans[len - k + 1] = y;
					}
					if (len & 1) {
						if (now >= k) {
							while (!a[x]) ++x;
							--a[x];
							ans[len / 2 + 1] = x;
						}
						else {
							ans[len / 2 + 1] = F[now];
							++now;	
						}
					}
					ans[len + 1] = 0;
					printf("%s", ans + 1);
					if (j == i) puts("");
					else printf(" ");
				}
				break;
			}
		}
	}
	return 0;
}