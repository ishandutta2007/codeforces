#pragma GCC optimize("O3")
//
//  main.cpp
//  Death Stars
//
//  Created by  on 2018/4/14.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int r,b,xr[20],yr[20],xb[20],yb[20],st[20],us[20],ans;


bool check(int de){
	/*
	for(int i=0;i<r;i++){
		cout<<st[i]<<' ';
	}
	cout<<endl;*/
	int cans = 1;
	for(int i=0;i<de;i++){
		for(int j=i+1;j<de;j++){
			int mi = st[i],mj = st[j];
			if(min(xr[i],xb[mi])<=max(xr[j],xb[mj])&&min(yr[j],yb[mj])<=max(yr[i],yb[mi])&&min(xr[j],xb[mj])<=max(xr[i],xb[mi]) && min(yr[i],yb[mi])<=max(yr[j],yb[mj])){
				
				if(((xb[mi]-xr[i])*(yb[mj]-yb[mi])-(xb[mj]-xb[mi])*(yb[mi]-yr[j]))*
				   ((xb[mi]-xr[i])*(yr[j]-yb[mi])-(xr[j]-xb[mi])*(yb[mi]-yr[j]))<=0){
					//cout<<i<<' '<<j<<endl;
					cans = 0;
				}
				
			}
		}
	}
	if(cans&&de == r){
		ans = 1;
	}
	return cans;
}
void dfs(int depth){
	if(depth == r){
		check(depth);
		return;
	}
	if(!check(depth))return;
	for(int i=0;i<r;i++){
		if(!us[i]){
			us[i] = 1;
			st[depth] = i;
			
			dfs(depth+1);
			us[i] = 0;
		}
	}
}
int main() {
	cin>>r>>b;
	if(r!=b){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=0;i<r;i++){
		cin>>xr[i]>>yr[i];
	}
	for(int i=0;i<b;i++){
		cin>>xb[i]>>yb[i];
	}
	dfs(0);
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}