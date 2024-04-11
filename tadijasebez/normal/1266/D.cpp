#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mt make_tuple
const int N=100050;
ll bal[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)scanf("%i %i %i",&u,&v,&w),bal[u]+=w,bal[v]-=w;
	vector<int> lo,hi;
	for(int i=1;i<=n;i++){
		if(bal[i]>0)hi.pb(i);
		if(bal[i]<0)lo.pb(i);
	}
	vector<tuple<int,int,ll>> ans;
	while(lo.size() && hi.size()){
		int a=lo.back();
		int b=hi.back();
		ll del=min(bal[b],-bal[a]);
		bal[b]-=del;
		bal[a]+=del;
		ans.pb(mt(b,a,del));
		if(bal[a]==0)lo.pop_back();
		if(bal[b]==0)hi.pop_back();
	}
	printf("%i\n",ans.size());
	for(auto t:ans)printf("%i %i %lld\n",get<0>(t),get<1>(t),get<2>(t));
	return 0;
}