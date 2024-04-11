#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,x1,x2,y1,y2,Q;	const ll mod=1e9+7;
ll work(ll x,ll y,ll p){
	if (!x||!y||p>=k)	return 0;	if (x<y)	swap(x,y);
	ll t=x;for(;t!=(t&-t);t-=(t&-t));ll w=min(k,p+t);
	return t>=y?((w-p)*(p+w+1)/2%mod*y%mod+work(x-t,y,p+t))%mod:(((w-p)*(p+w+1)/2%mod*t%mod+work(x-t,min(y,t),p+t)+work(min(t,x),y-t,p+t)+work(x-t,y-t,p))%mod);
}
int main(){	cin>>Q;	while(Q--){	cin>>x1>>y1>>x2>>y2>>k;	cout<<(work(x2,y2,0)+work(x1-1,y1-1,0)-work(x1-1,y2,0)-work(x2,y1-1,0)+2*mod)%mod<<endl;	}	}