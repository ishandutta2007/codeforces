using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 1001
#define M 300001
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define r(x) cin>>x
#define ll long long
ll dis[N];
ll ne[M],can[M],to[M],C[M],cnt=1,fir[N];
ll pre[N];
ll n,m;
ll x,y,z;
ll s,t,l;
bool inq[N];
queue<ll>q;
void add(ll x,ll y,ll z)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;if(z)can[cnt]=1;else can[cnt]=0;if(z) C[cnt]=z;else C[cnt]=1;
}
int main()
{
	r(n);r(m);r(l);r(s);r(t);
	for(int i=1;i<=m;i++)
	{
		r(x);r(y);r(z);
		add(x,y,z);
		add(y,x,z);
	}
	while(!q.empty())q.pop();
	memset(dis,127,sizeof(dis));
	q.push(s);inq[s]=1;dis[s]=0;
	while(!q.empty())
	{
		int it=q.front();q.pop();
		inq[it]=0;
		forw(i,it)
		{
			int V=to[i];
			if(!can[i]) continue;
			if(dis[V]>dis[it]+C[i])
			{
				dis[V]=dis[it]+C[i];
				pre[V]=i^1;
				if(!inq[V])
				{
					q.push(V);
					inq[V]=1;
				}
			}
		}
	}
	if(dis[t]<l){puts("NO");return 0;}
	while(1)
	{
	memset(dis,127,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	while(!q.empty())q.pop();
	q.push(s);inq[s]=1;dis[s]=0;
	while(!q.empty())
	{
		int it=q.front();q.pop();
		inq[it]=0;
		forw(i,it)
		{
			int V=to[i];
			if(dis[V]>dis[it]+C[i])
			{
				dis[V]=dis[it]+C[i];
				pre[V]=i^1;
				if(!inq[V])
				{
					q.push(V);
					inq[V]=1;
				}
			}
		}
	}
		if(dis[t]>l){puts("NO");return 0;}
		ll k=pre[t];
		ll lll=l-dis[t];
		bool flag=0;
		while(~k)
		{
			if(!can[k]){if(!flag)C[k]+=lll,C[k^1]+=lll;flag=1;break;}
			k=pre[to[k]];
		}	
		if(dis[t]==l) break;
	}
		puts("YES");
		for(ll i=2;i<=cnt;i+=2)
		{
			printf("%lld %lld %lld\n",to[i^1],to[i],C[i]);
		}
}