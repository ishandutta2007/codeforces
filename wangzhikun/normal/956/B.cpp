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

int n,m,r;
double a[100010];
double ans = -1;
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int l=0;l<n;l++){
		while(r<n-1 && a[r+1]-a[l]<=m){
			r+=1;
		}
		if(r-l>=2)ans = max(ans,(a[r]-a[l+1])/(a[r]-a[l]));
	}
	printf("%.12f\n",ans);
	return 0;
}