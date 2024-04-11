#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Dancer
{
	int g,p,t;
	int x,rank;
}a[100005];
int n,w,h,ans[100005][2];
bool cmp(Dancer a,Dancer b)
{
	return a.x<b.x||a.x==b.x&&a.g>b.g||a.x==b.x&&a.g==b.g&&(a.g==2&&a.p>b.p||a.g==1&&a.p<b.p);
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].g,&a[i].p,&a[i].t);
		a[i].x=a[i].p-a[i].t;
		a[i].rank=i;
	}
	sort(a+1,a+n+1,cmp);
	int now=1;
	while(now<=n)
	{
		int num1=0,num2=0,pre=now;
		int xx=a[now].x;
		while(a[now].x==xx&&a[now].g==2&&now<=n)now++,num1++;
		while(a[now].x==xx&&a[now].g==1&&now<=n)now++,num2++;
		for(int j=0;j<num1;j++)ans[a[pre+num2+j].rank][0]=w,ans[a[pre+num2+j].rank][1]=a[pre+j].p;
		for(int j=0;j<num2;j++)ans[a[pre+j].rank][0]=a[pre+num1+j].p,ans[a[pre+j].rank][1]=h;
	}
	for(int i=1;i<=n;i++)
	  printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}