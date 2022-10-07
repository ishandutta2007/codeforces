#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
int n;
ll p,minv[400005],ans[100005],t[100005];
priority_queue<ll,vector<ll>,greater<ll> >q;
priority_queue<int,vector<int>,greater<int> >s,del;
queue<pair<ll,int> >qu;
void pushup(int o)
{
	minv[o]=min(minv[lson],minv[rson]);
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		minv[o]=t[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
int ask(int o,int l,int r,int to,ll t)
{
	if(to==0)return 1;
	if(l==r)return l;
	if(to<=mid)return ask(lson,l,mid,to,t);
	if(minv[lson]<=t)return ask(lson,l,mid,to,t);
	else return ask(rson,mid+1,r,to,t);
}
void update(int o,int l,int r,int p)
{
	if(l==r)
	{
		minv[o]=1000000000000000000;
		return;
	}
	if(p<=mid)update(lson,l,mid,p);
	else update(rson,mid+1,r,p);
	pushup(o);
}
int main()
{
	scanf("%d%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i]);
		q.push(t[i]);
	}
	build(1,1,n);
	while(!q.empty())
	{
		ll ti=q.top();
		q.pop();
		if(!qu.empty()&&qu.front().first<=ti)
		{
			ans[qu.front().second]=qu.front().first;
			del.push(qu.front().second);
			qu.pop();
		}
		while(!s.empty()&&!del.empty()&&s.top()==del.top())
		{
			s.pop();
			del.pop();
		}
		int pos=s.empty()?n:s.top()-1;
		int x=ask(1,1,n,pos,ti);
		if(t[x]>ti)continue;
		update(1,1,n,x);
		t[x]=(ll)1e18;
		if(qu.empty())qu.push(make_pair(ti+p,x));
		else qu.push(make_pair(qu.back().first+p,x));
		s.push(x);
		q.push(qu.back().first);
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}