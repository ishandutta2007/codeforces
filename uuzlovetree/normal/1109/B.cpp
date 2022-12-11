#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
char s[maxn],s2[maxn];
bool ispalindrome()
{
	int len=strlen(s2+1);
	for(int i=1;i<=len;++i)if(s2[i]!=s2[len-i+1])return 0;
	return 1;
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=n;
	for(int i=n/2+((n&1)?1:0);i<=n;++i)
	{
		memset(s2,0,sizeof(s2));
		int j=n-i;
		int cnt=0;
		for(int k=1;k<=j;++k)s2[++cnt]=s[i+k];
		for(int k=j+1;k<=i;++k)s2[++cnt]=s[k];
		for(int k=i+1;k<=n;++k)s2[++cnt]=s[k-i];
		int t=2;
		if(i==j)t=1;
		if((strcmp(s+1,s2+1)!=0)&&(ispalindrome()))ans=min(ans,t);
	}
	for(int i=1;i<=n;++i)
	{
		memset(s2,0,sizeof(s2));
		int cnt=0;
		for(int j=i;j<=n;++j)s2[++cnt]=s[j];
		for(int j=1;j<i;++j)s2[++cnt]=s[j];
		int t=1;
		if((strcmp(s+1,s2+1)!=0)&&(ispalindrome()))ans=min(ans,t);
	}
	if(ans==n)puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}