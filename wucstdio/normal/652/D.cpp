#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
struct Point
{
	int x,y;
	int id;
}p[200005];
int n,ans[200005],c[200005];
set<int>s;
void add(int p)
{
	while(p<=n)
	{
		c[p]++;
		p+=p^(p&(p-1));
	}
}
int sum(int p)
{
	int ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
bool cmp2(Point a,Point b)
{
	return a.y<b.y;
}
bool cmp(Point a,Point b)
{
	return a.x>b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp2);
	int now=0,last=-1e9-1;
	for(int i=1;i<=n;i++)
	{
		if(p[i].y!=last)now++;
		last=p[i].y,p[i].y=now;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans[p[i].id]=sum(p[i].y);
		add(p[i].y);
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}