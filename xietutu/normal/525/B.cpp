#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 100005;
int r,ans,now,n,len,a[maxn];
char s[200005];
int main() {
	scanf("%s",s + 1);
	int len = strlen(s + 1);
	
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%d",a + i);
	std::sort(a + 1,a + n + 1);
	
	r = 0;
	for (int i = 1; i <= len / 2; ++i) {
		while (r + 1 <= n && a[r + 1] <= i) ++r,++now;
		if (now % 2 == 1) std::swap(s[i],s[len - i + 1]);
	}
	printf("%s\n",s + 1);
}