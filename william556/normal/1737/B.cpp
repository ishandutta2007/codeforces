#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
ll l,r;
ll calc(ll x){
	ll l=0,r=1e9,mid;
	while(l<=r){
		mid=l+r>>1;
		if(mid*(mid+2)<=x)l=mid+1;
		else r=mid-1;
	}
	ll ans=l-1;
	l=0,r=1e9,mid;
	while(l<=r){
		mid=l+r>>1;
		if(mid*(mid+1)<=x)l=mid+1;
		else r=mid-1;
	}
	ans+=l-1;
	l=0,r=1e9,mid;
	while(l<=r){
		mid=l+r>>1;
		if(mid*mid<=x)l=mid+1;
		else r=mid-1;
	}
	return ans+l-1;
}
void solve(){
	cin>>l>>r;
	cout<<calc(r)-calc(l-1)<<endl;		
}
int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int t=in();
	while(t--)solve(); 
	return 0;
}