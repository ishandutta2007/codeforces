#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
struct cmpr{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
}CPR;
struct BIT{
	ll sum[N];
	BIT(){}
	void Set(int i,ll f){for(;i<N;i+=i&-i)sum[i]+=f;}
	ll Get(int i){ll ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
}BT1,BT2;
pair<int,int> pts[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&pts[i].first);
	for(int i=1;i<=n;i++)scanf("%i",&pts[i].second);
	for(int i=1;i<=n;i++)CPR.Add(pts[i].second);
	sort(pts+1,pts+1+n);
	CPR.Build();
	ll ans=0;
	for(int i=1;i<=n;i++){
		pts[i].second=CPR.Find(pts[i].second);
		ans+=(ll)pts[i].first*BT1.Get(pts[i].second)-BT2.Get(pts[i].second);
		BT1.Set(pts[i].second,1);
		BT2.Set(pts[i].second,pts[i].first);
	}
	printf("%lld\n",ans);
	return 0;
}