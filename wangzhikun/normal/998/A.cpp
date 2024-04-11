//
//  main.cpp
//  Round 493
//
//  Created by  on 2018/7/1.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll mod = 998244353;
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
ll pow(ll a,ll b){
	ll c = 1,d = 1;
	for(int i=0;i<20;i++){
		if(c&b)d = (d*a)%mod;
		a = (a*a)%mod;
		c*=2;
	}
	return d;
}

ll n,a[200020],ans = 1,sum = 0;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<2 || (n==2 &&a[0] == a[1])){
		cout<<-1<<endl;
	}else{
		if(a[0]*2 == sum){
			cout<<2<<endl;
			cout<<"1 2"<<endl;
		}else{
			cout<<1<<endl;
			cout<<1<<endl;
		}
	}
	/*
	if(ans == 1){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	cout<<23*inv(23)%mod<<endl;
	 */
	return 0;
}