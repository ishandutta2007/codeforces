#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
char s[max_n];
int Right[max_n];
vector<int> pos[max_n];
int fa[max_n],sz[max_n],mx[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		if(sz[x]>sz[y])
			swap(x,y);
		fa[x]=y;
		sz[y]+=sz[x];
		mx[y]=max(mx[y],mx[x]);
	}
}
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	int lst[2]={n+1,n+1};
	for(int i=n;i>=1;--i)
	{
		if(s[i]=='?')
			Right[i]=max(lst[0],lst[1])-1;
		else
		{
			int v=s[i]^'0';
			Right[i]=lst[v^1]-1;
			lst[v]=i;
		}
		pos[Right[i]-i+1].push_back(i);
	}
	for(int i=1;i<=n+1;++i)
		fa[i]=i,sz[i]=1,mx[i]=i;
	for(int l=1;l<=n;++l)
	{
		int now=mx[get_fa(1)],ans=0;
		while(now<=n)
		{
			assert(Right[now]>=now+l-1);
			++ans;
			now=mx[get_fa(now+l)];
		}
		printf("%d%c",ans,l<n?' ':'\n');
		for(int i=0;i<int(pos[l].size());++i)
		{
			int p=pos[l][i];
			assert(mx[get_fa(p)]==p);
			merge(p,p+1);
		}
	}
	return 0;
}