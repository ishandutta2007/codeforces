#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=100007;

ll n,m,k;
ll a[maxn];

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;++i){
		scanf("%lld",&a[i]);
	}
	int i=1,ans=0;
	while (i<=m){
		ans++;
		ll page=(a[i]-i)/k,to=(page+1)*k+i;
		i=lower_bound(a+1,a+m+1,to)-a;
	}
	cout<<ans<<endl;
	return 0;
}