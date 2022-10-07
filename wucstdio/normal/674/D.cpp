#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
int n,q,pa[100005],d[100005];
priority_queue<ll>q1[100005],d1[100005],tot_q1,tot_d1;
priority_queue<ll,vector<ll>,greater<ll> >q2[100005],d2[100005],tot_q2,tot_d2;
ll t[100005],val[100005];
void setv(int x,ll v)
{
	int y=pa[x];
	while(!q1[y].empty()&&!d1[y].empty()&&q1[y].top()==d1[y].top())q1[y].pop(),d1[y].pop();
	while(!q2[y].empty()&&!d2[y].empty()&&q2[y].top()==d2[y].top())q2[y].pop(),d2[y].pop();
	tot_d1.push(q1[y].top()+t[y]/(d[y]+1));
	tot_d2.push(q2[y].top()+t[y]/(d[y]+1));
	if(val[x]==q1[y].top())q1[y].pop();
	else d1[y].push(val[x]);
	if(val[x]==q2[y].top())q2[y].pop();
	else d2[y].push(val[x]);
	val[x]=v;
	q1[y].push(val[x]);
	q2[y].push(val[x]);
	while(!q1[y].empty()&&!d1[y].empty()&&q1[y].top()==d1[y].top())q1[y].pop(),d1[y].pop();
	while(!q2[y].empty()&&!d2[y].empty()&&q2[y].top()==d2[y].top())q2[y].pop(),d2[y].pop();
	tot_q1.push(q1[y].top()+t[y]/(d[y]+1));
	tot_q2.push(q2[y].top()+t[y]/(d[y]+1));
}
void del(int x)
{
	int y=pa[x];
	while(!q1[y].empty()&&!d1[y].empty()&&q1[y].top()==d1[y].top())q1[y].pop(),d1[y].pop();
	while(!q2[y].empty()&&!d2[y].empty()&&q2[y].top()==d2[y].top())q2[y].pop(),d2[y].pop();
	tot_d1.push(q1[y].top()+t[y]/(d[y]+1));
	tot_d2.push(q2[y].top()+t[y]/(d[y]+1));
	if(val[x]==q1[y].top())q1[y].pop();
	else d1[y].push(val[x]);
	if(val[x]==q2[y].top())q2[y].pop();
	else d2[y].push(val[x]);
	d[y]--;
	while(!q1[y].empty()&&!d1[y].empty()&&q1[y].top()==d1[y].top())q1[y].pop(),d1[y].pop();
	while(!q2[y].empty()&&!d2[y].empty()&&q2[y].top()==d2[y].top())q2[y].pop(),d2[y].pop();
	if(!q1[y].empty())tot_q1.push(q1[y].top()+t[y]/(d[y]+1));
	if(!q2[y].empty())tot_q2.push(q2[y].top()+t[y]/(d[y]+1));
}
void ins(int x)
{
	int y=pa[x];
	while(!q1[y].empty()&&!d1[y].empty()&&q1[y].top()==d1[y].top())q1[y].pop(),d1[y].pop();
	while(!q2[y].empty()&&!d2[y].empty()&&q2[y].top()==d2[y].top())q2[y].pop(),d2[y].pop();
	if(!q1[y].empty())tot_d1.push(q1[y].top()+t[y]/(d[y]+1));
	if(!q2[y].empty())tot_d2.push(q2[y].top()+t[y]/(d[y]+1));
	d[y]++;
	q1[y].push(val[x]);
	q2[y].push(val[x]);
	tot_q1.push(q1[y].top()+t[y]/(d[y]+1));
	tot_q2.push(q2[y].top()+t[y]/(d[y]+1));
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pa[i]);
		d[pa[i]]++;
		d[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		val[i]+=t[i]-d[i]*(t[i]/(d[i]+1));
		val[pa[i]]+=t[i]/(d[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		q1[pa[i]].push(val[i]);
		q2[pa[i]].push(val[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!q1[i].empty())tot_q1.push(q1[i].top()+t[i]/(d[i]+1));
		if(!q2[i].empty())tot_q2.push(q2[i].top()+t[i]/(d[i]+1));
	}
	while(q--)
	{
		int type,x,y;
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&x);
			while(!q1[pa[x]].empty()&&!d1[pa[x]].empty()&&q1[pa[x]].top()==d1[pa[x]].top())
			  q1[pa[x]].pop(),d1[pa[x]].pop();
			while(!q2[pa[x]].empty()&&!d2[pa[x]].empty()&&q2[pa[x]].top()==d2[pa[x]].top())
			  q2[pa[x]].pop(),d2[pa[x]].pop();
			y=pa[x];
			setv(y,val[y]+d[y]*(t[y]/(d[y]+1))-(d[y]-1)*(t[y]/d[y])-t[x]/(d[x]+1));
			setv(pa[y],val[pa[y]]-t[y]/(d[y]+1)+t[y]/d[y]);
			del(x);
			scanf("%d",&y);
			pa[x]=y;
			ins(x);
			setv(y,val[y]-d[y]*(t[y]/(d[y]+1))+(d[y]-1)*(t[y]/d[y])+t[x]/(d[x]+1));
			setv(pa[y],val[pa[y]]+t[y]/(d[y]+1)-t[y]/d[y]);
		}
		if(type==2)
		{
			scanf("%d",&x);
			printf("%lld\n",val[x]+t[pa[x]]/(d[pa[x]]+1));
		}
		if(type==3)
		{
			while(!tot_q1.empty()&&!tot_d1.empty()&&tot_q1.top()==tot_d1.top())
				tot_q1.pop(),tot_d1.pop();
			while(!tot_q2.empty()&&!tot_d2.empty()&&tot_q2.top()==tot_d2.top())
				tot_q2.pop(),tot_d2.pop();
			printf("%lld %lld\n",tot_q2.top(),tot_q1.top());
		}
	}
	return 0;
}