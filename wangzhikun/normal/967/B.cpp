//
//  main.cpp
//  Round 477
//
//  Created by  on 2018/4/29.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,req,pour,s = 0,a[100010],po,ans = 0;

int main() {
	cin>>n>>pour>>req;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	po = a[0];
	sort(a+1,a+n);
	for(int i=n-1;i>=1;i--){
		if(po*pour>=s*req)break;
		ans+=1;
		s-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}