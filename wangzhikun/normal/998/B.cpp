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

ll n,bu,a[200020],ans = 0,sum = 0,dp[110][1010] = {0},b[1000],bn = 0;
int main() {
	cin>>n>>bu;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int hcod = 0,hcev = 0;
	for(int i=1;i<n;i+=1){
		if(a[i-1]%2){
			hcod+=1;
		}else{
			hcev+=1;
		}
		if(hcod!=hcev)continue;
		b[bn] = abs(a[i]-a[i-1]);
		bn+=1;
	}
	sort(b,b+bn);
	for(int i=0;i<bn;i++){
		sum+=b[i];
		if(sum>bu){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<bn<<endl;
	return 0;
}