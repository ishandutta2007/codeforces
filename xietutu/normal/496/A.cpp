#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
int n,a[105],b[105],ans,max;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%d",a + i);
	ans = 1005;;
	for (int i = 2; i < n; ++i) {
		int s = 0;
		for (int j = 1,l = 1; j <= n; ++j) 
			if (i != j) b[l++] = a[j];
		for (int i = 2; i <= n; ++i)
			s = std::max(s,b[i] - b[i - 1]);
		ans = std::min(ans,s);
	}
	printf("%d\n",ans);
}