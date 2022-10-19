#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[2005];
int fa[2005];
bool cz[35];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
bool check(int n)
{
	for(int j=0;j<30;j++)fa[j]=j,cz[j]=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<30;j++)
		{
			if(a[i]&(1<<j))cz[j]=true;
		}
		int pre=-1;
		for(int j=0;j<30;j++)
		{
			if((a[i]&(1<<j))==0)continue;
			if(pre==-1)
			{
				pre=j;
				continue;
			}
			int x=findf(pre),y=findf(j);
			if(x!=y)fa[x]=y;
		}
	}
	int pre=-1;
	for(int i=0;i<30;i++)
	{
		if(cz[i]==false)continue;
		if(pre==-1)pre=findf(i);
		if(findf(i)!=pre)
		{
			return false;
		}
	}
	return true;
}
vector<int>v[105];
int main()
{
	int t,n,pre,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]==0)a[i]++,ans++;
		}
		if(check(n)==true)
		{
			printf("%d\n",ans);
			for(int i=1;i<=n;i++)
			{
				printf("%d ",a[i]);
			}
			printf("\n");
			continue;
		}
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			a[i]--;
			if(a[i]!=0&&check(n)==true)
			{
				printf("%d\n",ans+1);
				for(int i=1;i<=n;i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
				flag=true;
				break;
			}
			a[i]+=2;
			if(check(n)==true)
			{
				printf("%d\n",ans+1);
				for(int i=1;i<=n;i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
				flag=true;
				break;
			}
			a[i]--;
		}
		if(flag==true)continue;
		int maxn=0; 
		for(int i=0;i<=30;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int sth=a[i],tsl=0;
			while(sth%2==0)
			{
				sth/=2;
				tsl++;
			}
			maxn=max(maxn,tsl);
			v[tsl].push_back(i);
		}
		a[v[maxn][0]]--;
		a[v[maxn][1]]++;
		printf("%d\n",ans+2);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}