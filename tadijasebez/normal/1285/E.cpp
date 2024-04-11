#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n;
		scanf("%i",&n);
		vector<pair<int,int>> events;
		for(int i=1,l,r;i<=n;i++)
		{
			scanf("%i %i",&l,&r);
			events.pb({l,-i});
			events.pb({r,i});
		}
		vector<int> cnt(n+1);
		int gaps=0;
		sort(events.begin(),events.end());
		set<int> active;
		int las=-1e9-7;
		int le=-1;
		for(auto e:events)
		{
			int tme=e.first;
			int d=tme-las;
			las=tme;
			int id=abs(e.second);
			if(d>0 && active.size()==0) gaps++;
			if(d>0 && active.size()==1) if(*active.begin()!=le && id!=*active.begin()) cnt[*active.begin()]++;
			le=id;
			if(e.second<0) active.insert(id);
			else active.erase(id);
		}
		if(gaps==n) printf("%i\n",n-1);
		else
		{
			int ans=gaps;
			for(int i=1;i<=n;i++) ans=max(ans,gaps+cnt[i]);
			printf("%i\n",ans);
		}
	}
	return 0;
}