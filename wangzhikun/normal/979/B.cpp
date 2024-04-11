//
//  main.cpp
//  Round 482
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,ans[3];
int cnt[3][200] = {0};
char s[100010];

int main() {
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>s;
		m = strlen(s);
		for(int j=0;j<m;j++){
			cnt[i][s[j]]+=1;
		}
		ans[i] = 0;
		for(int j=0;j<200;j++){
			int cur = min(m,n+cnt[i][j]);
			if(cnt[i][j] == m && n == 1){
				cur-=1;
			}
			ans[i] = max(ans[i],cur);
		}
	}
	if(ans[0]>ans[1] && ans[0]>ans[2]){
		cout<<"Kuro"<<endl;
	}
	else if(ans[1]>ans[0] && ans[1]>ans[2]){
		cout<<"Shiro"<<endl;
	}
	else if(ans[2]>ans[1] && ans[2]>ans[0]){
		cout<<"Katie"<<endl;
	}else{
		cout<<"Draw"<<endl;
	}
	
	return 0;
}