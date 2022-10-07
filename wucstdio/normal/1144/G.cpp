#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,_a[200010],*a=_a+5,ans[200005],now1,last1,now2,last2,_pre[200010],*pre=_pre+5;
int main()
{
	scanf("%d",&n);
	a[-3]=-2;
	a[-2]=-1;
	a[-1]=1000000000;
	a[0]=999999999;
	pre[-2]=-3,pre[0]=-1;
	now1=-2,last1=-3,now2=0,last2=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[now1]>a[now2]&&a[now1]<a[last2]&&a[now2]>a[last1]&&now1>last2&&now2>last1)
		{
			swap(ans[now1],ans[now2]);
			swap(now1,now2);
			swap(pre[now1],pre[now2]);
		}
		while(now1>last2&&now1<now2&&a[now1]<a[last2]&&a[now1]>a[now2])
		{
			pre[now1]=last2;
			pre[now2]=now1;
			ans[now1]^=1;
			last2=now1;
			now1=last1;
			last1=pre[last1];
		}
		while(now2>last1&&now2<now1&&a[now2]>a[last1]&&a[now2]<a[now1])
		{
			pre[now2]=last1;
			pre[now1]=now2;
			ans[now2]^=1;
			last1=now2;
			now2=last2;
			last2=pre[last2];
		}
		if(a[i]>a[now1])
		{
			ans[i]=0;
			pre[i]=now1;
			last1=now1,now1=i;
		}
		else if(a[i]<a[now2])
		{
			ans[i]=1;
			pre[i]=now2;
			last2=now2,now2=i;
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}