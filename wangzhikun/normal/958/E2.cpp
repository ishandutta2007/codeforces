//
//  main.cpp
//  Guard Duty
//
//  Created by  on 2018/4/20.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,k,sz;

struct cho{
	ll l,id;
} a[500050];
bool cmp1(cho a,cho b){return a.l<b.l;}
bool cmp2(cho a,cho b){return a.id<b.id;}
ll dp[3][5050],b[500050];
int main() {
	cin>>k>>n;
	sz = min(3*k+1,n-1);
	for(ll i=0;i<n;i++)cin>>b[i];
	sort(b,b+n);
	for(ll i=0;i<n-1;i++){
		a[i].l = b[i+1]-b[i];
		a[i].id = i;
	}
	sort(a,a+n-1,cmp1);
	sort(a,a+sz,cmp2);
	memset(dp,7,sizeof(dp));
	dp[0][0] = 0;
	dp[0][1] = a[0].l;
	for(ll i=1;i<sz;i++){
		//cout<<a[i].l<<endl;
		for(ll j=0;j<=k;j++){
			dp[i%3][j] = dp[(i-1)%3][j];
			if(a[i].id-a[i-1].id>1&&j>0){
				dp[i%3][j] = min(dp[i%3][j],dp[(i-1)%3][j-1]+a[i].l);
			}else if(i>=2&&j>0){
				dp[i%3][j] = min(dp[i%3][j],dp[(i-2)%3][j-1]+a[i].l);
			}
		}
	}
	cout<<dp[(sz-1)%3][k]<<endl;
	return 0;
}