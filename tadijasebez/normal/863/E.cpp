#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
vector< pair<int,int> > events;
int only[N];
set<int> s;
int main()
{
	int n,l,r,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&l,&r);
		r++;
		events.push_back(make_pair(l,i));
		events.push_back(make_pair(r,-i));
	}
	sort(events.begin(),events.end());
	set<int>::iterator it;
	int NewTime,CurTime,PrevTime=0;
	for(i=0;i<events.size();i++)
	{
		CurTime=events[i].first;
		NewTime=CurTime-PrevTime;
		PrevTime=CurTime;
		if(s.size()==1)
		{
			it=s.begin();
			only[*it]+=NewTime;
		}
		if(events[i].second>0) s.insert(events[i].second);
		else s.erase(-events[i].second);
	}
	int sol=-1;
	for(i=1;i<=n;i++)
	{
		if(only[i]==0)
		{
			sol=i;
			break;
		}
	}
	printf("%i\n",sol);
	return 0;
}