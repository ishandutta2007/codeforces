#include<cstdio>
#include<algorithm>
using namespace std;
int n,pre[2005],p[2005],ans,cnt=0;
void opt1()
{
	for(int i=1;i<=2*n;i+=2)swap(p[i],p[i+1]);
	cnt++;
	for(int i=1;i<2*n;i++)
	{
		if(p[i]>p[i+1])return;
	}
	ans=min(ans,cnt);
}
void opt2()
{
	for(int i=1;i<=n;i++)swap(p[i],p[i+n]);
	cnt++;
	for(int i=1;i<2*n;i++)
	{
		if(p[i]>p[i+1])return;
	}
	ans=min(ans,cnt);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",&pre[i]);
	ans=100000;
	for(int i=1;i<=2*n;i++)p[i]=pre[i];
	cnt=0;
	for(int i=1;i<2*n;i++)
	{
		if(p[i]>p[i+1])goto tag;
	}
	ans=min(ans,cnt);
	tag:;
	for(int i=1;i<=2*n;i++)
	{
		if(i&1)opt1();
		else opt2();
	}
	for(int i=1;i<=2*n;i++)p[i]=pre[i];
	cnt=0;
	for(int i=1;i<=2*n;i++)
	{
		if(i&1)opt2();
		else opt1();
	}
	if(ans==100000)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}