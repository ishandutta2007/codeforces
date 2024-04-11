#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
int n,m,ans;
char s[105][105];
bool p[105];
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
		scanf("%s",s[i] + 1);
	for (int j = 1; j <= m; ++j) {
		bool bo = true;
		for (int k = 1; k < n; ++k)
			if (!p[k] && s[k][j] > s[k + 1][j]) bo = false;
		if (!bo) ++ans;
		if (bo) {
			for (int k = 1; k < n; ++k)
				if (s[k][j] < s[k + 1][j]) p[k] = true;
		}
	}
	printf("%d\n",ans);
}