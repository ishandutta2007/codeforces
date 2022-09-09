#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int MX=100000;
int n,l[N],t[N];
ll r;
int main(){
	scanf("%i%lld",&n,&r);
	for(int i=1;i<=n;i++)scanf("%i",&l[i]);
	for(int i=1;i<=n;i++)scanf("%i",&t[i]);
	for(int i=1;i<=n;i++)l[i]*=2;
	for(int i=1;i<=n;i++)if(l[i]>t[i]*2)return 0*printf("-1");
	int j=1;
	ll ans=0,tmp=0,curr=0;
	vector<ll> b;
	while(j<=n){
		ll diff=l[j]-t[j];
		if(diff<=0){curr+=l[j++];continue;}
		ll need=diff/r;
		if(diff%r>0)need++;
		ll ost=0LL;
		for(int i=0;i<need&&(int)b.size()<=MX;i++)b.pb(2*t[j]+curr+ost-l[j]),ost+=r;
		curr+=2*t[j]-l[j]+diff+(r-diff%r)%r;
		ll mx=t[j]-l[j]+diff+(r-diff%r)%r;
		mx*=2,j++;
		while(j<=n){
			if(l[j]>mx)break;
			mx-=l[j++];
		}
		//if(j<=n)l[j]-=mx/2,t[j]-=mx;
		if(j<=n)l[j]-=mx,t[j]-=mx/2;
		ans+=need;
	}
	printf("%lld\n",ans);
	if((int)b.size()<=MX)for(ll x:b)printf("%lld ",x);
	return 0;
}