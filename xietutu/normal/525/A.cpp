#include <cstdio>
int ans,n,v[26];
char s[200005];
int main() {
	//freopen("a.in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s + 1);
	for (int i = 1; i <= n - 1; ++i) {
		++v[s[i * 2 - 1] - 'a'];
		if (v[s[i * 2] - 'A']) --v[s[i * 2] - 'A'];
		else ++ans;
	}
	printf("%d\n",ans);
}