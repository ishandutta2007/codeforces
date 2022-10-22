// LUOGU_RID: 90774711
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int p1,p2,h,s;
ll t1,t2;
ll f[N];
int main(){
	cin>>p1>>t1>>p2>>t2>>h>>s;
	if(t1>t2)swap(t1,t2),swap(p1,p2);
	for(int i=1;i<=h;i++)f[i]=1e18;
	ll ans=1e18;
	for(int i=0;i<h;i++){
		if(f[i]==1e18)continue;
		for(int j=1;j<=h;j++){
			ll x=j,y=(j*t1)/t2;
			ll k=1ll*x*p1+1ll*y*p2;
			k-=1ll*(x+y-(y>0))*s;
			ll val=f[i]+j*t1;
			if(i+k<h)f[i+k]=min(f[i+k],val);
			else ans=min(ans,val);
		}
		swap(t1,t2),swap(p1,p2);
		for(int j=1;j<=h;j++){
			ll x=j,y=(j*t1)/t2;
			ll k=1ll*x*p1+1ll*y*p2;
			k-=1ll*(x+y-(y>0))*s;
			ll val=f[i]+j*t1;
			if(i+k<h)f[i+k]=min(f[i+k],val);
			else ans=min(ans,val);
		}
	}
	cout<<ans<<endl;
	return 0;
}