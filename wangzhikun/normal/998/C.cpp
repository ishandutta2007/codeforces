//
//  main.cpp
//  Round 493
//
//  Created by  on 2018/7/1.
//  Copyright  2018 . All rights reserved.
//


#include <cmath>
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

ll n,x,y;
char c[300030];

int main() {
	cin>>n>>x>>y;
	cin>>c;
	ll cnt0 = 0;
	if(c[0] == '0')cnt0++;
	for(int i=1;i<n;i++){
		if(c[i] == '0' && c[i-1] == '1')cnt0+=1;
	}
	if(cnt0 == 0){
		cout<<0<<endl;
		return 0;
	}
	if(cnt0 == 1){
		cout<<y<<endl;
		return 0;
	}
	if(y<x){
		cout<<cnt0*y<<endl;
	}else{
		cout<<(cnt0-1)*x+y<<endl;
	}
	return 0;
}