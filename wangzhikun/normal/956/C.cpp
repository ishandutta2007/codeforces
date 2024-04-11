//
//  main.cpp
//  Round 472
//
//  Created by  on 2018/4/24.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,m,r;
ll a[1000010];
ll b[1000010] = {0};
ll lowbit(ll x){
	return x&(-x);
}
void change(ll x,ll v){
	while(x<n+1){
		b[x] = max(b[x],v);
		x+=lowbit(x);
	}
}
ll query(ll x){
	ll an = 0;
	while(x>=1){
		an = max(an,b[x]);
		x-=lowbit(x);
	}
	return an;
}
int main() {
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		change(i,a[i]+1);
	}
	ll wt = query(n),ans = 0;
	for(ll p=n;p>=1;p--){
		ans+=wt-a[p]-1;
		if(wt>query(p-1))wt-=1;
	}
	cout<<ans<<endl;
	return 0;
}