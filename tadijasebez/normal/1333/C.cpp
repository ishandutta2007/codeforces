#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6;
ll a[N];
int main(){
	map<ll,int> las;
	int n;
	scanf("%i",&n);
	ll ans=0;
	las[0]=1;
	int idx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
		idx=max(idx,las[a[i]]);
		ans+=i-idx;
		las[a[i]]=i+1;
	}
	printf("%lld\n",ans);
	return 0;
}