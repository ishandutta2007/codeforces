#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[100005],c[100005],s[100005],minc[1<<9],minc2[1<<9],ans[1<<9],num[1<<9];
int kind[1<<9],k2[1<<9],x[1<<9],y[1<<9];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			a[i]|=1<<(x-1);
		}
		num[a[i]]++;
	}
	memset(minc,0x3f,sizeof(minc));
	memset(minc2,0x3f,sizeof(minc2));
	memset(ans,0x7f,sizeof(ans));
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			s[i]|=1<<(x-1);
		}
		if(c[i]<minc[s[i]])
		{
			minc2[s[i]]=minc[s[i]];
			minc[s[i]]=c[i];
			k2[s[i]]=kind[s[i]];
			kind[s[i]]=i;
		}
		else if(c[i]<minc2[s[i]])
		{
			minc2[s[i]]=c[i];
			k2[s[i]]=i;
		}
	}
	for(int i=0;i<(1<<9);i++)
	{
		if(kind[i]&&k2[i])
		{
			ans[i]=minc[i]+minc2[i];
			x[i]=k2[i],y[i]=kind[i];
		}
	}
	for(int i=0;i<(1<<9);i++)
	for(int j=i+1;j<(1<<9);j++)
	{
		if(minc[i]>1000000000||minc[j]>1000000000)continue;
		ans[i|j]=min(ans[i|j],minc[i]+minc[j]);
		if(ans[i|j]==minc[i]+minc[j])
		{
			x[i|j]=kind[i];
			y[i|j]=kind[j];
		}
	}
	int res=0,maxx=-1,val=2147483647;
	for(int i=0;i<(1<<9);i++)
	{
		if(ans[i]>2000000000)continue;
		int now=0;
		for(int j=0;j<(1<<9);j++)
		{
			if((j&i)==j)
			  now+=num[j];
		}
		if(now>maxx)res=i,maxx=now,val=ans[i];
		else if(now==maxx&&ans[i]<val)res=i,val=ans[i];
	}
	printf("%d %d\n",x[res],y[res]);
	return 0;
}