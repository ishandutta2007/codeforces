#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,ans,cnt;
char s[maxn];
int f(int i) {
	if (i%n==0) return n;
	return i%n;
}
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n*2;i++) {
		if (s[f(i)]!=s[f(i-1)]||i==1) cnt++; else cnt=1;
		ans=max(ans,cnt);
	}
	ans=min(ans,n);
	printf("%d\n",ans);
	return 0;
}