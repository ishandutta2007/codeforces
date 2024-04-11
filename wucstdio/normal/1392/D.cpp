#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[200005];
int f[200005][2][2];
void DP()
{
	for(int i=3;i<=n;i++)
	{
		f[i][0][0]=f[i-1][1][0]+(s[i]=='R');
		f[i][0][1]=min(f[i-1][1][0],f[i-1][0][0])+(s[i]=='L');
		f[i][1][0]=min(f[i-1][1][1],f[i-1][0][1])+(s[i]=='R');
		f[i][1][1]=f[i-1][0][1]+(s[i]=='L');
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=1000000000;
		for(int i=1;i<=n;i++)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1000000000;
		f[2][0][0]=(s[1]=='R')+(s[2]=='R');
		DP();
		ans=min(ans,min(f[n][0][1],f[n][1][1]));
//		printf("%d\n",ans);
		for(int i=1;i<=n;i++)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1000000000;
		f[2][0][1]=(s[1]=='R')+(s[2]=='L');
		DP();
		ans=min(ans,min(f[n][1][0],min(f[n][0][1],f[n][1][1])));
//		printf("%d\n",ans);
		for(int i=1;i<=n;i++)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1000000000;
		f[2][1][0]=(s[1]=='L')+(s[2]=='R');
		DP();
		ans=min(ans,min(min(f[n][0][0],f[n][1][0]),f[n][0][1]));
//		printf("%d\n",ans);
		for(int i=1;i<=n;i++)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1000000000;
		f[2][1][1]=(s[1]=='L')+(s[2]=='L');
		DP();
		ans=min(ans,min(f[n][0][0],f[n][1][0]));
		printf("%d\n",ans);
	}
	return 0;
}