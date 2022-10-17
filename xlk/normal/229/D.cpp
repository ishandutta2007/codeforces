#include<stdio.h>
int s[5020],f[5020],g[5020];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),s[i]+=s[i-1];
	for(int i=1;i<=n;i++)
	{
		int j=i-1;
		for(;s[i]-s[j]<g[j];j--)
			;
		f[i]=f[j]+i-j-1;
		g[i]=s[i]-s[j];
	}
	printf("%d\n",f[n]);
	return 0;
}