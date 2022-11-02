/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=300100;
const LL ooo=1000000000;
const LL oo=ooo*ooo;
struct Node
{
	int pos,va;
}q[V];
bool cmp(Node x,Node y)
{
	if(x.va!=y.va)return x.va<y.va;
	else return x.pos<y.pos;
}
LL s[V];
int n;
int vis[V];
int main()
{
	while(~scanf("%d",&n))
	{
		s[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&q[i].va);
			q[i].pos=i;
			s[i]=s[i-1]+max(0,q[i].va);
		}
		sort(q+1,q+n+1,cmp);
		int st=q[1].pos,S=-1,t=-1;
		LL ans=-oo;
		for(int i=1;i<=n;i++)
		{
			if(i==n||q[i].va!=q[i+1].va)
			{
				if(st==i)
				{
				    st=i+1;
				    continue;
				}
				LL tmp=s[q[i].pos-1]-s[q[st].pos];
				tmp+=q[i].va*2;
				if(tmp>ans)
				{
					ans=tmp;
					S=q[st].pos;
					t=q[i].pos;
				}
				st=i+1;
			}
			else continue;
		}
		memset(vis,0,sizeof(vis));
		int K=0;
		for(int i=1;i<=n;i++)
		{
			if(q[i].pos<S||q[i].pos>t)
			{
				vis[q[i].pos]=1;
				K++;
			}
			else if(q[i].pos>S&&q[i].pos<t&&q[i].va<0)
			{
				vis[q[i].pos]=1;
				K++;
			}
		}
		cout<<ans<<" "<<K<<endl;
		for(int i=1;i<=n;i++)
		if(vis[i])printf("%d ",i);
		puts("");
	}
	return 0;
}