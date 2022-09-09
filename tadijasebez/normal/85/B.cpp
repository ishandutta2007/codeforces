#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
#define ll long long
struct Event
{
	ll time;
	int type,i;
	Event(ll a, int b, int c){ time=a,type=b,i=c;}
	bool operator < (Event b) const
	{
		if(time==b.time && type==b.type) return i<b.i;
		return (time==b.time && type<b.type) || time<b.time;
	}
};
set<Event> events;
set<Event>::iterator it;
queue<int> wait[3];
const int N=100050;
ll start[N],finish[N];
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	int k1,k2,k3,t1,t2,t3,n,i;
	scanf("%i %i %i",&k1,&k2,&k3);
	scanf("%i %i %i",&t1,&t2,&t3);
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&start[i]),events.insert(Event(start[i],4,i));
	for(it=events.begin();it!=events.end();it++)
	{
		ll time=it->time;
		int type=it->type;
		i=it->i;
		//printf("%lld %i %i\n",time,type,i);
		if(type==4)
		{
			if(k1>0)
			{
				k1--;
				events.insert(Event(time+t1,3,i));
			}
			else wait[0].push(i);
		}
		if(type==3)
		{
			k1++;
			if(wait[0].size())
			{
				k1--;
				events.insert(Event(time+t1,3,wait[0].front()));
				wait[0].pop();
			}
			if(k2>0)
			{
				k2--;
				events.insert(Event(time+t2,2,i));
			}
			else wait[1].push(i);
		}
		if(type==2)
		{
			k2++;
			if(wait[1].size())
			{
				k2--;
				events.insert(Event(time+t2,2,wait[1].front()));
				wait[1].pop();
			}
			if(k3>0)
			{
				k3--;
				events.insert(Event(time+t3,1,i));
			}
			else wait[2].push(i);
		}
		if(type==1)
		{
			k3++;
			if(wait[2].size())
			{
				k3--;
				events.insert(Event(time+t3,1,wait[2].front()));
				wait[2].pop();
			}
			finish[i]=time;
		}
	}
	ll sol=0;
	for(i=1;i<=n;i++) sol=max(sol,finish[i]-start[i]);
	printf("%lld\n",sol);
	return 0;
}