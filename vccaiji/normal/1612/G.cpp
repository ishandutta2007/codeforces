#include<bits/stdc++.h>
using namespace std;
int c[510000];
int cnt[2200000];
const int p=1000000007;
int fac[1100000];
int main(){
	int m;cin>>m;
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=m;i++){
		cnt[1100000-(c[i]-1)]+=1;
		cnt[1100000+c[i]+1]-=1;
	}
	for(int i=2;i<2200000;i++)cnt[i]+=cnt[i-2];
	int ans=0,cntt=0;
	for(int i=0;i<2200000;i++){
		ans=(ans+1ll*(p-1100000+i)*((p+1)/2)%p*((2ll*cntt+cnt[i]+1)%p)%p*cnt[i])%p;
		cntt=(cntt+cnt[i])%p;
	}fac[0]=1;
	for(int i=1;i<=1000000;i++)fac[i]=1ll*fac[i-1]*i%p;
	cout<<ans<<' ';
	ans=1;
	for(int i=0;i<2200000;i++)ans=1ll*ans*fac[cnt[i]]%p;
	cout<<ans<<endl;
	return 0;
}