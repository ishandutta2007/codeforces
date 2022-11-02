#include <bits/stdc++.h>
using namespace std;
int n,m,q,ans[1010];
char s[1010],t[1010];
int main() {
	scanf("%d %d %d %s %s",&n,&m,&q,s+1,t+1);
	for (int i=1;i<=n;i++) {
		ans[i]=1;
		for (int j=i;j<=i+m-1;j++)
			if (s[j]!=t[j-i+1]) {
				ans[i]=0; break;
			}
		ans[i]+=ans[i-1];
	}
	while (q--) {
		int l,r; scanf("%d %d",&l,&r);
		printf("%d\n",ans[max(l-1,r-m+1)]-ans[l-1]);
	}
	return 0;
}