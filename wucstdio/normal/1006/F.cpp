#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
int n,m;
ll k,a[25][25],ans;
map<ll,ll>mp[25][25];
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    scanf("%lld",&a[i][j]);
	n--,m--;
	ans=0;
	for(int s=0;s<(1<<(n+m)/2);s++)
	{
		int x=0,y=0;
		ll xors=a[0][0];
		for(int i=0;i<(n+m)/2;i++)
		{
			if((1<<i)&s)x++;
			else y++;
			xors^=a[x][y];
		}
		if(x<=n&&y<=m)mp[x][y][xors]++;
	}
	for(int s=0;s<(1<<(n+m-(n+m)/2));s++)
	{
		int x=n,y=m;
		ll xors=0;
		for(int i=0;i<(n+m-(n+m)/2);i++)
		{
			xors^=a[x][y];
			if((1<<i)&s)x--;
			else y--;
			if(x<0||y<0)break;
		}
		if(x>=0&&y>=0)ans+=mp[x][y][xors^k];
	}
	printf("%lld\n",ans);
	return 0;
}