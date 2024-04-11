#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int f[max_n];
const int max_s=1<<9|5;
typedef pair<int,int> pii;
pii best[max_s],sec[max_s];
inline void insert(int s,pii v)
{
	if(!best[s].first)
	{
		best[s]=v;
		return;
	}
	if(v<best[s])
		swap(best[s],v);
	if(!sec[s].first)
	{
		sec[s]=v;
		return;
	}
	if(v<sec[s])
		swap(sec[s],v);
}
int tot;
const int max_tot=1<<18|5;
struct Choice
{
	int id1,id2,p,s;
	inline Choice(int i=0,int j=0,int c=0,int t=0)
	{
		id1=i,id2=j,p=c,s=t;
	}
}c[max_tot];
inline bool operator < (const Choice &a,const Choice &b)
{
	return a.p<b.p;
}
bool vis[max_s];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int cnt;
		scanf("%d",&cnt);
		while(cnt--)
		{
			int x;
			scanf("%d",&x);
			f[i]|=1<<--x;
		}
	}
	for(int i=1;i<=m;++i)
	{
		int c,r;
		scanf("%d%d",&c,&r);
		int s=0;
		while(r--)
		{
			int x;
			scanf("%d",&x);
			s|=1<<--x;
		}
		insert(s,pii(c,i));
	}
	int mx=(1<<9)-1;
	for(int s=0;s<=mx;++s)
	{
		if(!best[s].first)
			continue;
		for(int t=s+1;t<=mx;++t)
		{
			if(!best[t].first)
				continue;
			c[++tot]=Choice(best[s].second,best[t].second,best[s].first+best[t].first,s|t);
		}
		if(sec[s].first)
			c[++tot]=Choice(best[s].second,sec[s].second,best[s].first+sec[s].first,s);
	}
	sort(c+1,c+tot+1);
	int ans=0,ans_id=0;
	c[0].p=(int)2e9+1;
	for(int i=1;i<=tot;++i)
	{
		if(vis[c[i].s])
			continue;
		vis[c[i].s]=true;
		int cnt=0;
		for(int j=1;j<=n;++j)
			cnt+=(f[j]&c[i].s)==f[j];
		if(cnt>ans)
		{
			ans=cnt;
			ans_id=i;
		}
		else if(cnt==ans&&c[i].p<c[ans_id].p)
			ans_id=i;
	}
	assert(ans_id>0);
	printf("%d %d\n",c[ans_id].id1,c[ans_id].id2);
	return 0;
}