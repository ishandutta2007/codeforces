//
//  main.cpp
//  Round 476
//
//  Created by  on 2018/4/26.
//  Copyright  2018 . Aint rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,k,m,d,ans = 0;

ll calc(ll x){
	if(x <= 0)return -1;
	if(x>m || ((((n+x-1)/x)+k-1)/k)>d)return -1;
	return ((n/x)/k)*x+min((ll)1,(ll)((n-((n/x)/k)*x*k)/x))*x;
}
int main() {
	cin>>n>>k>>m>>d;
	ll st = (n/m)/k;
	for(ll i=m;i>=max(m-100000,(ll)0);i--)ans = max(ans,calc(i));
	for(ll turns = max(st,(ll)1);turns<st+10000;turns++){
		ll dist = n/(turns*k+1);
		if(dist == 0)break;
		//cout<<dist<<endl;
		ans = max(ans,calc(dist+2));
		ans = max(ans,calc(dist+1));
		ans = max(ans,calc(dist));
		ans = max(ans,calc(dist-1));
		ans = max(ans,calc(dist-2));
	}
	cout<<ans<<endl;
	return 0;
}