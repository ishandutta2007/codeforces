//
//  main.cpp
//  Round 480
//
//  Created by  on 2018/5/11.
//  Copyright  2018 . All rights reserved.
//

#include <iomanip>
#include <vector>
#include <cstring>
#include <iostream>


using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;y=0;return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
ll inv(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll n,m,a[200020],b[200020],eqpb = 1,ans = 0;
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++){
		if(a[i] != 0 && b[i]!=0){
			if(a[i]>b[i]){
				ans+=eqpb;
				eqpb = 0;
			}
			if(a[i]<b[i]){
				eqpb = 0;
			}
		}else{
			if(a[i] == 0 && b[i]!=0){
				ans += ((eqpb*(m-b[i])%mod)*inv(m))%mod;
				eqpb = (eqpb*inv(m))%mod;
			}
			if(a[i] == 0 && b[i] == 0){
				ans += ((((eqpb - ((eqpb*inv(m))%mod))+mod)%mod)*inv(2))%mod;
				eqpb = (eqpb*inv(m))%mod;
			}
			if(a[i] != 0 && b[i]==0){
				ans += ((eqpb*(a[i]-1)%mod)*inv(m))%mod;
				eqpb = (eqpb*inv(m))%mod;
			}
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}