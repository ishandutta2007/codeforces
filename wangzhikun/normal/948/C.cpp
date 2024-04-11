//
//  main.cpp
//  CF470
//
//  Created by  on 2018/4/21.
//  Copyright  2018 . All rights reserved.
//

#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll cng[100010] = {0},an[100010] = {0},e[100010] = {0},toa[100010] = {0};
ll n,m[100010],c[100010],q[100010] = {0},ans[100010];
int main() {
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>m[i];
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		q[i] = q[i-1]+c[i];
	}
	for(ll i=1;i<=n;i++){
		ll melt_day = lower_bound(q+1, q+n+1, m[i]+q[i-1]) - q;
		//cout<<i<<' '<<melt_day<<endl;
		cng[i]+=1;
		cng[melt_day]-=1;
		e[melt_day]+=m[i]-(q[melt_day-1]-q[i-1]);
	}
	for(ll i=1;i<=n;i++){
		an[i] = an[i-1]+cng[i];
		toa[i]+=an[i]*c[i];
		toa[i]+=e[i];
		cout<<toa[i]<<' ';
	}
	cout<<endl;
	return 0;
}