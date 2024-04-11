#include <stdio.h>
#include <set>
#include <queue>
using namespace std;
queue<int> q[10];
bool Free[10];
struct Event
{
	int time,type,id;
	Event(){}
	Event(int a, int b, int c){ time=a,type=b,id=c;}
	bool operator < (Event b) const
	{
		if(time==b.time && type==b.type) return id<b.id;
		if(time==b.time) return type>b.type;
		return time<b.time;
	}
};
set<Event> Set;
set<Event>::iterator it;
const int N=50050;
int Cost[N][10],sol[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&Cost[i][j]);
	for(i=2;i<=n;i++) q[1].push(i);
	for(i=1;i<=m;i++) Free[i]=1;
	Free[1]=0;
	Set.insert(Event(Cost[1][1],1,1));
	for(it=Set.begin();it!=Set.end();it++)
	{
		int time=it->time;
		int type=it->type;
		int id=it->id;
		if(type==m)
		{
			sol[id]=time;
			if(q[type].empty()) Free[type]=1;
			else
			{
				int index=q[type].front();
				q[type].pop();
				Set.insert(Event(time+Cost[index][type],type,index));
			}
		}
		else
		{
			if(!Free[type+1]) q[type+1].push(id);
			else Set.insert(Event(time+Cost[id][type+1],type+1,id)),Free[type+1]=0;
			if(q[type].empty()) Free[type]=1;
			else
			{
				int index=q[type].front();
				q[type].pop();
				Set.insert(Event(time+Cost[index][type],type,index));
			}
		}
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}