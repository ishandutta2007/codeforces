#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
const int maxn=200007;
int t,n;
ll k,sum=0;
pair<int,int> sal[maxn];

inline bool ck(int ans){
	ll val=sum;
	vector<int> vec;
	vec.clear();
	for (int i=1;i<=n;++i){
		if (sal[i].second>=ans) vec.push_back(-sal[i].first);
	}
	if (vec.size()<n/2+1) return 0;
	sort(vec.begin(),vec.end());
	for (int i=0;i<n/2+1;++i){
		val+=vec[i];
		val+=max(-vec[i],ans);
	}
	if (val>k) return 0;
	return 1;
}

inline int quick_search(int l,int r){
	if (l==r) return l;
	int md=(l+r)>>1;
	if (ck(md+1)) return quick_search(md+1,r);
	else return quick_search(l,md);
}

#undef int
int main(){
	scanf("%lld",&t);
	while(t--){
		sum=0;
		scanf("%lld%lld",&n,&k);
		for (int i=1;i<=n;++i){
			scanf("%lld%lld",&sal[i].first,&sal[i].second);
			sum+=sal[i].first;
		}
		printf("%lld\n",quick_search(1,1e9));
	}
	return 0;
}