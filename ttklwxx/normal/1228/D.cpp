#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm> 
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
vector<int>e[100001];
map<vector<int>,int>ma;
int main()
{
    int n,m,x,y,cnt=0;
    n=read();
    m=read();
    for(int i=1;i<=m;i++)
    {
    	x=read();
    	y=read();
    	e[x].push_back(y);
    	e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].size()==0)
		{
			printf("-1\n");
			return 0;
		}
		sort(e[i].begin(),e[i].end());
		if(ma[e[i]]==0)
		{
			ma[e[i]]=++cnt;
		}
	}
	if(cnt!=3)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)printf("%d ",ma[e[i]]);
    return 0;
}