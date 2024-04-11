#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int n,a[N];ll k,ans=0;
void Try(ll d){
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=(a[i]+d-1)/d;
	if(sum*d<=k)ans=max(ans,d);
}
int main(){
	scanf("%i %lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),k+=a[i];
	for(ll i=1;i*i<=k;i++)Try(i),Try(k/i);
	printf("%lld\n",ans);
	return 0;
}