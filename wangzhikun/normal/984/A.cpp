//
//  main.cpp
//  Round 483
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

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

int n,a[1010];
int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int fst = (n)/2;
	cout<<a[n-fst-1]<<endl;
	return 0;
}