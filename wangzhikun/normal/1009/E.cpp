//
//  main.cpp
//  Edu Round 47
//
//  Created by  on 2018/7/15.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll mod = 998244353;
ll n,a[1000010],b[1000010] = {0},ans = 0,tans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=(b[i-1]*2+a[i-1])%mod;
	}
	for(int i=0;i<n;i++){
		tans=tans*2+b[i]+a[i];
		if(tans>1e15)tans%=mod;
	}
	cout<<tans%mod<<endl;
	return 0;
}