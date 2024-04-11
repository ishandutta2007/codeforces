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

int n,b = 0,nn;
int fnd(int nn){
	int rn = nn;
	int rb = 0;
	for(int i=2;i<=nn;i++){
		if(i*i>nn){
			if(nn!=rn)rb = nn;
			break;
		}
		if(nn%i == 0){
			while(nn%i == 0) nn/=i;
			rb = max(rb,i);
		}
	}
	return rb;
}
int main() {
	cin>>n;
	b = fnd(n);
	/*
	for(int i=n-1;i>1;i--){
		int isp = 1;
		for(int j=2;j<i;j++)if(i%j == 0)isp = 0;
		if(isp){
			b = i;
			break;
		}
	}*/
	//cout<<b<<endl;
	int ans = n;
	for(int i=n;i>n-b;i--){
		ans = min(ans,i-fnd(i)+1);
	}
	cout<<ans<<endl;
	return 0;
}