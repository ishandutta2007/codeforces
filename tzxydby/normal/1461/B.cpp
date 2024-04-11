#include<bits/stdc++.h>
using namespace std;
const int N=505;
int t,n,m,a[N][N],p[N][N],ans;
char s[N][N];
int ok(int i,int l,int r){return p[i][r]-p[i][l-1]==r-l+1;}
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=(s[i][j]=='*');
			p[i][j]=p[i][j-1]+a[i][j];
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j])
				continue;
			int x=i,l=j,r=j;
			while(1)
			{
				ans++;
				x++,l--,r++;
				if(x>n||l<1||r>m)
					break;
				if(!ok(x,l,r))
					break;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}