#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int inf=1e9+7;
struct Area{
	set<pair<int,int>> all;
	ll sum;
	void init(){sum=0;all.clear();all.insert({0,inf});}
	Area(){init();}
	void Cng(set<pair<int,int>>::iterator it,int f){
		sum+=(ll)(it->first-prev(it)->first)*it->second*f;
	}
	void Add(int x,int y){
		auto it=all.lower_bound({x,y});
		if(it!=all.end()&&it->second>=y)return;
		if(it!=all.end())Cng(it,-1);
		while(prev(it)->second<=y)Cng(prev(it),-1),all.erase(prev(it));
		all.insert({x,y}),Cng(all.find({x,y}),1);
		if(it!=all.end())Cng(it,1);
	}
}A;
const int N=500050;
int x[N],y[N],z[N];
ll sum;
vector<int> Us[N];
int main(){
	int n,p,q,r;
	scanf("%i %i %i %i",&n,&p,&q,&r);
	A.init();
	for(int i=1;i<=n;i++)scanf("%i %i %i",&x[i],&y[i],&z[i]),Us[x[i]].pb(i),A.Add(y[i],z[i]);
	for(int i=p;i>=1;i--){
		for(int j:Us[i])A.Add(y[j],r),A.Add(q,z[j]);
		sum+=A.sum;
	}
	ll ans=(ll)p*q*r-sum;
	printf("%lld\n",ans);
	return 0;
}