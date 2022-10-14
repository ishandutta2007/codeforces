#include <iostream>

using namespace std;
typedef long long ll;

ll x,y;
ll calc(ll mid){
	ll cc;
	if(mid<=y){
		if(mid>2*1e9)return 1e18+100000;
		cc = (mid+1)*mid/2;
	}else{
		if(y>2*1e9)return 1e18+100000;
		cc = (y+1)*y/2+y*(mid-y);
		ll cu = ((mid+y)/2)-y;
		if((mid+y)%2)cc+=cu;
		if(cu>1e9)return 1e18+100000;
		cc+=cu*cu;
	}
	return cc;
}
int main() {
	cin>>x>>y;
	//cout<<calc(64379858)<<endl;
	ll l = 0,r = x,mid;
	while(r-l>1){
		mid = (l+r)/2;
		if(calc(mid)>=x){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout<<r<<endl;
	return 0;
}