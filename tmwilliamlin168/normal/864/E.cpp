#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int f[110][2010];
int g[110][2010];
struct p
{
	int t,d,p,id;
};
p a[110];
int cmp(p a,p b)
{
	return a.d<b.d;
}
void solve(int x,int y,int s)
{
	if(x<0)
		printf("%d\n",s);
	else
	{
		if(!g[x][y])
			solve(x-1,y,s);
		else
		{
			solve(x-1,y-a[x].t,s+1);
			printf("%d ",a[x].id);
		}
	}
}
int main()
{
	memset(f,0x80,sizeof f);
	f[0][0]=0;
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		for(j=0;j<=2000;j++)
		{
			f[i][j]=f[i-1][j];
			g[i][j]=0;
			if(j>=a[i].t&&j<a[i].d)
				if(f[i-1][j-a[i].t]+a[i].p>f[i][j])
				{
					f[i][j]=f[i-1][j-a[i].t]+a[i].p;
					g[i][j]=1;
				}
		}
	int ans1=-1,ans2=-1;
	for(i=0;i<=2000;i++)
		if(f[n][i]>ans1)
		{
			ans1=f[n][i];
			ans2=i;
		}
	printf("%d\n",ans1);
	solve(n,ans2,0);
	return 0;
}