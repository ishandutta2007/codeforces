#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
int l[N],r[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	set<pair<int,int>> sgs;
	vector<pair<int,int>>evs;
	for(int i=1;i<=n;i++){
		scanf("%i %i",&l[i],&r[i]);
		evs.pb({l[i],i});
		evs.pb({r[i]+1,-i});
	}
	sort(evs.begin(),evs.end());
	vector<int> ans;
	for(auto e:evs){
		int id=abs(e.second);
		if(e.second<0){
			if(sgs.count({r[id],id}))
				sgs.erase({r[id],id});
		}else{
			sgs.insert({r[id],id});
		}
		if(sgs.size()>k)
			ans.pb(sgs.rbegin()->second),
			sgs.erase(--sgs.end());
	}
	printf("%i\n",ans.size());
	for(int i:ans)printf("%i ",i);
	return 0;
}