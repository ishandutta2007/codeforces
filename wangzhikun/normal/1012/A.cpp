//
//  main.cpp
//  Round 500
//
//  Created by  on 2018/7/30.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long n,a[200020];
int main() {
	cin>>n;
	for(int i=0;i<n*2;i++)cin>>a[i];
	sort(a,a+2*n);
	long long ans = (a[n-1]-a[0])*(a[n*2-1]-a[n]);
	for(int i=1;i<n;i++){
		ans = min(ans,(a[n+i-1]-a[i])*(a[n*2-1]-a[0]));
	}
	cout<<ans<<endl;
	return 0;
}