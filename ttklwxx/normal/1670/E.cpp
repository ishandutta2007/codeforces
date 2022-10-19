#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define int long long
#define mod 1000000007
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
vector<int>v[1000005],tid[1000005];
int qz[1000005],qans[1000005];
int dep[1000005];
int cnt,p;
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]==f)continue;
		if(dep[x]%2==1)
		{
			qans[tid[x][i]]=cnt+(1<<p);
			qz[v[x][i]]=cnt;
		}
		else
		{
			qans[tid[x][i]]=cnt;
			qz[v[x][i]]=cnt+(1<<p);
		}
		cnt++;
		dfs(v[x][i],x);
	}
}
signed main()
{
	int t,n,x,y,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		p=read();
		n=(1<<p);
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			tid[i].clear();
		}
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			v[x].push_back(y);
			tid[x].push_back(i);
			v[y].push_back(x);
			tid[y].push_back(i);
		}
		if(p==1)
		{
			printf("1\n1 2\n3\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(v[i].size()==1)
			{
				sth=i;
				break;
			}
		}
		printf("%lld\n",sth);
		qz[sth]=(1<<p);
		cnt=1;
		dfs(sth,0);
		for(int i=1;i<=n;i++)printf("%lld ",qz[i]);
		printf("\n");
		for(int i=1;i<=n-1;i++)printf("%lld ",qans[i]);
		printf("\n"); 
	}
	return 0;
}