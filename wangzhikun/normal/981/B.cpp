//
//  main.cpp
//  Avito Code Challenge 2018
//
//  Created by  on 2018/5/27.
//  Copyright  2018 . All rights reserved.
//

#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,a[100010];

ll mod = 998244353;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;y=0;return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b, a%b);
}
ll inv(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll pow(ll a,ll b){
	ll c = 1,d = 1;
	for(int i=0;i<60;i++){
		if(c&b)d = (d*a)%mod;
		a = (a*a)%mod;
		c*=2;
	}
	return d;
}


map<int,int> mp;

int main() {
	
	int a,v;
	ll ans = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>v;
		if(mp[a] < v){
			ans-=mp[a];
			mp[a] = v;
			ans+=v;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>v;
		if(mp[a] < v){
			ans-=mp[a];
			mp[a] = v;
			ans+=v;
		}
	}
	cout<<ans<<endl;
	return 0;
}