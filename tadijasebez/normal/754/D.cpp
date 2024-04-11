#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300050;
#define ll long long
vector< pair<int,int> > events;
ll L[N],R[N];
int n,k;
pair<int,int> Solve(ll mid)
{
	int pos=0,len=0,i;
	events.clear();
	for(i=1;i<=n;i++)
	{
		if(R[i]-mid+1>=L[i])
		{
			events.push_back(make_pair(L[i],-1));
			events.push_back(make_pair(R[i]-mid+1,1));
		}
	}
	sort(events.begin(),events.end());
	int CurTime,PrevTime,NewTime,open=0;
	for(i=0;i<events.size();i++)
	{
		CurTime=events[i].first;
		NewTime=CurTime-PrevTime+1;
		if(open>=k)
		{
			len=open;
			pos=CurTime;
		}
		open-=events[i].second;
		PrevTime=CurTime;
	}
	return make_pair(pos,len);
}
int main()
{
	int i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld %lld",&L[i],&R[i]);
	ll top=2e9+69,bot=0;
	ll mid;
	int ans=0;
	pair<int,int> sol,tmp;
	while(top>=bot)
	{
		mid=(top+bot)/2;
		//printf("%i %i\n",top,bot);
		tmp=Solve(mid);
		if(tmp.second<k) top=mid-1;
		else sol=tmp,bot=mid+1,ans=mid;
	}
	ll l=sol.first;
	ll r=sol.first+ans-1;
	printf("%i\n",ans);
	if(r-l+1==0) for(i=1;i<=k;i++) printf("%i ",i);
	else
	{
		int j=0;
		for(i=1;i<=n;i++)
		{
			if(L[i]<=l && R[i]>=r) printf("%i ",i),j++; 
			if(j==k) break;
		}
	}
	return 0;
}