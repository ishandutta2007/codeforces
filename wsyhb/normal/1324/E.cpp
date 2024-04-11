#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=2e3+5;
int f[N][N],a[N],s[N];
int main()
{
	int n,h,l,r;
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]+a[i])%h;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			int x=((s[i]-j)%h+h)%h;
			if(j<i) f[i][j]=max(f[i][j],f[i-1][j]+(x>=l&&x<=r));
			if(j>0) f[i][j]=max(f[i][j],f[i-1][j-1]+(x>=l&&x<=r));
		}
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}