#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,a[200005],ans,num[1005],pw1[1005][1005],pw2[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0;i<m;i++)
	{
		pw1[i][0]=1;
		for(int j=1;j<=1000;j++)pw1[i][j]=pw1[i][j-1]*i%m;
		pw2[i][0]=1;
		for(int j=1;j<=1000;j++)pw2[i][j]=pw2[i][j-1]*pw1[i][1000]%m;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		a[i]%=m;
		for(int j=0;j<m;j++)
		{
			int v=(a[i]-j+m)%m;
			ans=(ans*pw1[v][num[j]%1000]%m*pw2[v][num[j]/1000])%m;
		}
		num[a[i]]++;
	}
	printf("%d\n",ans);
	return 0;
}