//
//  main.cpp
//  Round 483
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,m,ans = 1;
char a[220][220];
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		int cs,ca = 0;
		if(a[i][j]=='*')continue;
		if(a[i][j]=='.')cs = 0;
		else cs = a[i][j]-'0';
		for(int di = i-1;di<=i+1;di++)for(int dj = j-1;dj<=j+1;dj++){
			if(di<0 || di>=n || dj<0 || dj>=m)continue;
			if(a[di][dj] == '*')ca+=1;
		}
		if(cs!=ca)ans = 0;
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}