#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=50050;
int t[N],s[N],p[N];
ll T,ans[N];
int done[N],n;
void Check()
{
	for(int i=1;i<=n;i++) done[i]=0;
	set<pair<ll,pair<int,int> > > events;
	set<pair<int,int> > q;
	ll LastTime=0,CurTime,Duration;
	for(int i=1;i<=n;i++) events.insert(mp(t[i],mp(0,i)));
	bool Free=1;
	int works;
	for(auto it=events.begin();it!=events.end();it++)
	{
		CurTime=it->first;
		Duration=CurTime-LastTime;
		int t=it->second.first;
		int id=it->second.second;
		if(Free==0)
		{
			done[works]+=Duration;
			if(done[works]==s[works])
			{
				ans[works]=CurTime;
			}
			else
			{
				events.erase(mp(CurTime+s[works]-done[works],mp(1,works)));
				q.insert(mp(p[works],works));
			}
			Free=1;
		}
		if(t==0) q.insert(mp(p[id],id));
		if(q.size())
		{
			works=q.rbegin()->second;
			q.erase(mp(p[works],works));
			Free=0;
			events.insert(mp(CurTime+s[works]-done[works],mp(1,works)));
		}
		LastTime=CurTime;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<int> work;
	set<int> has;
	int i,f;
	scanf("%i",&n);
	int mx=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&t[i],&s[i],&p[i]);
		if(p[i]==-1) f=i;
		else has.insert(p[i]),mx=max(mx,p[i]);
	}
	scanf("%lld",&T);
	for(i=1;i<=n;i++) if(i!=f && p[i]!=1 && !has.count(p[i]-1)) work.pb(p[i]-1);
	work.pb(mx+1);
	sort(work.begin(),work.end());
	int top=work.size()-1,bot=0,mid,sol=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		p[f]=work[mid];
		Check();
		if(ans[f]==T){ sol=work[mid];break;}
		if(ans[f]<T) top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}