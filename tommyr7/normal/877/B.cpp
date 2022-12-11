#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
char s[Maxn];
int s1[Maxn],s2[Maxn];
int main()
{
	scanf("%s",s);
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	int n=strlen(s);
	for (int i=0;i<n;i++)
	{
		s1[i+1]=s1[i],s2[i+1]=s2[i];
		if (s[i]=='a') ++s1[i+1]; else ++s2[i+1];
	}
	int ans=s1[n];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			ans=max(s1[i]+s2[j]-s2[i-1]+s1[n]-s1[j],ans);
	printf("%d\n",ans);
	return 0;
}