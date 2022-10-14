//
//  main.cpp
//  Round 476
//
//  Created by  on 2018/4/26.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,k,ans[250][250] = {0},o = 1;
char mp[250][250];

int main() {
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>mp[i];
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		o = 1;
		for(int l=0;l<k;l++)if(mp[i+l][j]!='.')o = 0;
		if(o)for(int l=0;l<k;l++)ans[i+l][j]+=1;
		o = 1;
		for(int l=0;l<k;l++)if(mp[i][j+l]!='.')o = 0;
		if(o)for(int l=0;l<k;l++)ans[i][j+l]+=1;
	}
	int x = 0,y = 0,m = 0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		if(ans[i][j]>m){
			m = ans[i][j];
			x = i;
			y = j;
		}
	}
	cout<<x+1<<' '<<y+1<<endl;
	return 0;
}