//
//  main.cpp
//  CF470
//
//  Created by  on 2018/4/21.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int r,c;
char mp[510][510];
int main() {
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>mp[i];
	}
	int ans = 1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i-1>=0){
				if(mp[i][j] == 'S' && mp[i-1][j] == 'W')ans = 0;
			}
			if(i+1<r){
				if(mp[i][j] == 'S' && mp[i+1][j] == 'W')ans = 0;
			}
			if(j-1>=0){
				if(mp[i][j] == 'S' && mp[i][j-1] == 'W')ans = 0;
			}
			if(j+1<c){
				if(mp[i][j] == 'S' && mp[i][j+1] == 'W')ans = 0;
			}
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mp[i][j]!='.')cout<<mp[i][j];
				else cout<<'D';
			}
			cout<<endl;
		}
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}