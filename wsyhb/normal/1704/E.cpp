#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=1e3+5;
int a[max_n];
bool mark[max_n];
inline bool check()
{
	for(int i=1;i<=n;++i)
	{
		if(a[i])
			return false; 
	}
	return true;
}
const int max_m=1e3+5;
int End[max_m],Last[max_n],Next[max_m],deg_in[max_n],deg_out[max_n],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
	++deg_in[y];
	++deg_out[x];
}
int que[max_n],sz;
const int mod=998244353;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add_edge(x,y);
		}
		int sink=-1;
		for(int i=1;i<=n;++i)
		{
			if(!deg_out[i])
			{
				sink=i;
				break;
			}
		}
		assert(sink!=-1);
		if(check())
		{
			puts("0");
			E=0;
			for(int i=1;i<=n;++i)
				Last[i]=deg_in[i]=deg_out[i]=0;
			continue;
		}
		bool flag_over=false;
		for(int t=1;t<=5000;++t)
		{
			for(int i=1;i<=n;++i)
				mark[i]=a[i]>0;
			for(int i=1;i<=n;++i)
			{
				if(mark[i])
				{
					--a[i];
					for(int k=Last[i];k;k=Next[k])
						++a[End[k]];
				}
			}
			if(check())
			{
				printf("%d\n",t);
				flag_over=true;
				break;
			}
		}
		if(flag_over)
		{
			E=0;
			for(int i=1;i<=n;++i)
				Last[i]=deg_in[i]=deg_out[i]=0;
			continue;
		}
		sz=0;
		for(int i=1;i<=n;++i)
		{
			if(!deg_in[i])
				que[++sz]=i;
			a[i]-=a[i]>=mod?mod:0;
		}
		for(int t=1;t<=sz;++t)
		{
			int x=que[t];
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				--deg_in[y];
				if(!deg_in[y])
					que[++sz]=y;
				add(a[y],a[x]);
			}
		}
		int ans=a[sink];
		add(ans,5000);
		printf("%d\n",ans);
		E=0;
		for(int i=1;i<=n;++i)
			Last[i]=deg_in[i]=deg_out[i]=0;
	}
	return 0;
}