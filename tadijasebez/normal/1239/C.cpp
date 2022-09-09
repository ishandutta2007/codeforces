#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

set<int> seat_queue,queue_set;
queue<int> queue_boil;
bool wxh;
int who;
struct Event
{
	ll tme;
	int type;
	// 2 zeli da ide po vodu
	// 1 vraca se na mesto
	int id;
	Event(){}
	Event(ll x, int y, int z):tme(x),type(y),id(z){}
	bool operator < (Event b) const { return mt(tme,-type,id)<mt(b.tme,-b.type,b.id);}
};
set<Event> events;
const int N=100050;
int a[N];
ll ans[N];
int main()
{
	int n,p;
	scanf("%i %i",&n,&p);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),events.insert(Event(a[i],2,i));
	//printf("evsz:%i\n",events.size());
    for(auto it=events.begin();it!=events.end();it++)
	{
		ll tme;
		int type,id;
		tme=it->tme;
		type=it->type;
		id=it->id;
		//printf(":D");
		if(type==1)
		{
			wxh=0;
			queue_set.erase(who);
			//printf("del: %lld %i\n",tme,who);
		}
		if(type==2)
		{
			seat_queue.insert(id);
			//printf("add: %lld %i\n",tme,id);
		}
		if(seat_queue.size())
		{
			int x=*seat_queue.begin();
			if(queue_set.empty() || *queue_set.begin()>x)
			{
                queue_set.insert(x);
                queue_boil.push(x);
                seat_queue.erase(x);
			}
		}
		if(wxh==0)
		{
			if(queue_boil.size())
			{
				wxh=1;
				who=queue_boil.front();
				queue_boil.pop();
				ans[who]=tme+p;
				events.insert(Event(ans[who],1,who));
			}
		}
		//for(auto k:queue_set) printf("%i ",k);printf("\n");
		//for(auto k:seat_queue) printf("%i ",k);printf("\n");
	}
	//printf("%i\n",seat_queue.size());
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}