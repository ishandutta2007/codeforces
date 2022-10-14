//
//  main.cpp
//  Round 486
//
//  Created by  on 2018/6/2.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,m,n,inr[2020] = {0},cost[2020],umb[2020] = {0},l,r;
	cin>>a>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		for(int i=l;i<r;i++)inr[i] = 1;
	}
	for(int i=0;i<m;i++){
		cin>>l>>r;
		if(!umb[l])umb[l] = r;
		else{
			umb[l] = min(umb[l],r);
		}
	}
	cost[0] = 0;
	for(int i=1;i<=a;i++){
		cost[i] = 239999999;
		if(inr[i-1]){
			for(int j=i-1;j>=0;j--){
				if(umb[j]){
					cost[i] = min(cost[i],cost[j]+umb[j]*(i-j));
				}
			}
		}else{
			cost[i] = cost[i-1];
		}
	}
	if(cost[a] == 239999999){
		cout<<-1<<endl;
	}else{
		cout<<cost[a]<<endl;
	}
	return 0;
}