//
//  main.cpp
//  Round 493
//
//  Created by  on 2018/7/1.
//  Copyright  2018 . All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,x,y,z,lo[100010] = {0},cnt;

int main() {
	cin>>n;
	if(n>210){
		cnt+=(n-210)*49;
		n = 210;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			for(int k=0;i+j+k<=n;k++){
				lo[i*49+j*4+k*9] = 1;
			}
		}
	}
	for(int i=0;i<100010;i++){
		if(lo[i])cnt+=1;
	}
	cout<<cnt<<endl;
	return 0;
}