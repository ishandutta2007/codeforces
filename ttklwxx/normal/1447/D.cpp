#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int n,m,f[5005][5005],ans;
char s1[5005],s2[5005];
signed main() {
	n=read();
	m=read();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1])-1;
			if(f[i][j]<0)f[i][j]=0;
			if(s1[i]==s2[j])f[i][j]=max(f[i-1][j-1]+2,f[i][j]);
			ans=max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
}