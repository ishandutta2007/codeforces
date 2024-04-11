#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
#define ll long long
struct Event
{
	ll time;
	int type,index;
	Event(){}
	Event(ll a, int b, int c){ time=a,type=b,index=c;}
	inline bool operator < (const Event &b) const
	{
		if(time==b.time && type==b.type) return index<b.index;
		if(time==b.time) return type>b.type;
		return time<b.time;
	}
};
set<Event> events;
set<Event>::iterator it;
queue<int> q;
const int N=200050;
int T[N],D[N];
bool Free=true;
ll sol[N];
int main()
{
	int n,b,i;
	scanf("%i %i",&n,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&T[i],&D[i]);
		events.insert(Event(T[i],1,i));
	}
	ll CurTime;
	for(it=events.begin();it!=events.end();it++)
	{
		CurTime=it->time;
		if(it->type==1)
		{
			if(Free)
			{
				Free=false;
				events.insert(Event(CurTime+D[it->index],2,it->index));
				sol[it->index]=CurTime+D[it->index];
			}
			else
			{
				if(q.size()<b)
				{
					q.push(it->index);
				}
				else sol[it->index]=-1;
			}
		}
		else
		{
			if(!q.empty())
			{
				i=q.front();
				q.pop();
				events.insert(Event(CurTime+D[i],2,i));
				sol[i]=CurTime+D[i];
			}
			else
			{
				Free=true;
			}
		}
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	printf("\n");
	return 0;
}