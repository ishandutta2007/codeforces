#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double r,dis[100005],ans;
int m;
int main()
{
	scanf("%d%lf",&m,&r);
	dis[0]=2*r;
	dis[1]=2*r+sqrt(2)*r;
	dis[2]=2*r+2*sqrt(2)*r;
	for(int i=3;i<=m;i++)
	  dis[i]=dis[i-1]+2*r;
	ans=dis[0]*m;
	for(int i=1;i<=m;i++)
	  ans+=dis[i]*(m-i)*2;
	printf("%lf\n",ans/m/m);
	return 0;
}