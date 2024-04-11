//Goodbye SoundCloud :(
//Hello CaramelCloud :)
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
const int Max_N=3000500;
const int Seg_N=1<<19;
long long max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}
long long SegmentTree[2*Seg_N+20];
void Set(int index, long long value)
{
	index+=Seg_N;
	while(index)
	{
		SegmentTree[index]=max(SegmentTree[index],value);
		index>>=1;
	}
}
long long Get(int ss, int se, int si, int qs, int qe)
{
	if(qs>qe) return 0;
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return SegmentTree[si];
	int mid=(ss+se)>>1;
	return max(Get(ss,mid,si*2,qs,qe),Get(mid+1,se,si*2+1,qs,qe));
}
long long only[Max_N];
map<int,long long> both[Max_N];
long long bb[Max_N];
int start[Max_N];
int ends[Max_N];
int cost[Max_N];
int index[Max_N];
vector<pair<long long ,int> > events;
const long long inf=2e9+7;
set<int> s;
pair<int,int> a[Max_N];
vector<pair<int,int> > costs;
long long sol[Max_N];
int main()
{
	int n,c,q,i;
	scanf("%i%i",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&start[i],&ends[i],&cost[i]);
		events.push_back(make_pair(start[i],i));
		events.push_back(make_pair(ends[i],-i));
		costs.push_back(make_pair(cost[i],i));
	}
	sort(costs.begin(),costs.end());
	for(i=0;i<n;i++) index[costs[i].second]=i;
	events.push_back(make_pair(inf,0));
	sort(events.begin(),events.end());
	scanf("%i",&q);
	for(i=0;i<q;i++)
	{
		scanf("%i",&a[i].first);
		a[i].second=i;
	}
	sort(a,a+q);
	vector<pair<long long,int> >::iterator it;
	set<int>::iterator sit;
	long long FreeTime=0;
	long long Last=0;
	int done=0;
	long long NewTime;
	long long Best=0;
	int x,y,tmp,top,bot,mid,taj;
	for(it=events.begin();it!=events.end();it++)
	{
		NewTime=it->first-Last;
		Last=it->first;
		if(s.size()==0)
		{
			FreeTime+=NewTime;
		}
		if(s.size()==1)
		{
			sit=s.begin();
			x=*sit;
			if(cost[x]<=c)
			{
				only[x]+=NewTime;
				Best=max(Best,only[x]+bb[x]);
				Set(index[x],only[x]);
				tmp=c-cost[x];
				top=costs.size();
				bot=0;
				taj=-1;
				while(top>=bot)
				{
					mid=(top+bot)>>1;
					if(costs[mid].first<=tmp)
					{
						taj=mid;
						bot=mid+1;
					}
					else top=mid-1;
				}
				Best=max(Best,only[x]+Get(0,Seg_N-1,1,0,min(taj,index[x]-1)));
				Best=max(Best,only[x]+Get(0,Seg_N-1,1,index[x]+1,taj));
			}
		}
		if(s.size()==2)
		{
			sit=s.begin();
			x=*sit;
			sit++;
			y=*sit;
			if(c-cost[x]>=cost[y])
			{
				both[x][y]+=NewTime;
				both[y][x]+=NewTime;
				bb[x]=max(bb[x],only[y]+both[x][y]);
				bb[y]=max(bb[y],only[x]+both[y][x]);
				Best=max(Best,only[x]+only[y]+both[x][y]);
			}
		}
		while(done<q && a[done].first<=FreeTime+Best)
		{
			sol[a[done].second]=Last-(FreeTime+Best-a[done].first);
			done++;
		}
		if(it->second>0)
			s.insert(it->second);
		else s.erase(-it->second);
	}
	for(i=0;i<q;i++) printf("%lld\n",sol[i]);
	return 0;
}