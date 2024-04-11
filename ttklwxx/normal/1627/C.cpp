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
vector<int>v[200005];
int rd[200005];
int tu[200005],tv[200005];
int dep[200005];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]==f)continue;
		dfs(v[x][i],x);
	}
}
int main()
{
	int n,t,x,y;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			rd[i]=0;
			v[i].clear();
		}
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			tu[i]=x;
			tv[i]=y;
			v[x].push_back(y);
			v[y].push_back(x);
			rd[x]++;
			rd[y]++;
		}
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(rd[i]>=3)
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(rd[i]==1)
			{
				dep[0]=0;
				dfs(i,0);
				break;
			}
		}
		//for(int i=1;i<=n;i++)printf("%d\n",dep[i]);
		for(int i=1;i<=n-1;i++)
		{
			if(min(dep[tu[i]],dep[tv[i]])%2==0)printf("2 ");
			else printf("3 ");
		}
		printf("\n");
	}
	return 0;
}