#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[500005],b[500005];
char s[500005];
int res=1e9,xx,yy;
int calc2(int x,int y)
{
	if(x==0&&y==0)return 1000000000;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(x<=a[i]&&y<=b[i])ans=max(ans,max(a[i]-x,b[i]-y));
		else if(x<=a[i]||y<=b[i])ans=max(ans,abs(a[i]-x)+abs(b[i]-y));
		else ans=max(ans,max(x-a[i],y-b[i]));
	}
	if(ans<res)
	{
		res=ans;
		xx=x,yy=y;
	}
	return ans;
}
int calc1(int x)
{
	int l=0,r=500000;
	if(x==0)l=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(calc2(x,mid)<calc2(x,mid+1))r=mid-1;
		else l=mid+1;
	}
	return min(calc2(x,l),calc2(x,r));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int x=(int)strlen(s+1);
		for(int j=1;j<=x;j++)
		{
			if(s[j]=='N')a[i]++;
			else b[i]++;
		}
	}
	int l=0,r=500000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int v1=calc1(mid),v2=calc1(mid+1);
		if(v1<v2)r=mid-1;
		else if(v1>v2)l=mid+1;
		else
		{
			int v3=calc1(mid+2);
			if(v1<v3)r=mid-1;
			else if(v1>v3)l=mid+1;
			else break;
		}
	}
	printf("%d\n",res);
	for(int i=1;i<=xx;i++)putchar('N');
	for(int i=1;i<=yy;i++)putchar('B');
	printf("\n");
	return 0;
}