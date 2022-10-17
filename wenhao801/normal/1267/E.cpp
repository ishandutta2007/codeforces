#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[1001][1001],Ans[1001];
struct ykl{int a,b,id;}y[1001];bool cmp(ykl a,ykl b){return a.b-a.a>b.b-b.a;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);int ans=0x3f3f3f3f;
	for(int i=1;i<n;++i)
	{
		int suma=0,sumb=0;
		for(int j=1;j<=m;++j)y[j].a=a[j][i],y[j].b=a[j][n],suma+=y[j].a,sumb+=y[j].b,y[j].id=j;
		sort(y+1,y+1+m,cmp);int cur=sumb-suma,res=0;if(cur<=0){putchar(48);putchar(10);putchar(10);return 0;}
		for(int j=1;j<=m;++j)
		{
			cur-=y[j].b-y[j].a;++res;
			if(cur<=0)break;
		}
		int tmp=ans;
		ans=min(ans,res);
		if(tmp!=ans){for(int i=1;i<=ans;++i)Ans[i]=y[i].id;}
	}
	printf("%d\n",ans);for(int i=1;i<=ans;++i)printf("%d ",Ans[i]);putchar(10);return 0;
}