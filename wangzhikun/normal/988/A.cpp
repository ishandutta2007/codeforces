//
//  main.cpp
//  Round 486
//
//  Created by  on 2018/6/2.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,n,cur;
	vector<int> v(110,0);
	vector<int> a;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>cur;
		if(!v[cur]){
			v[cur] = 1;
			a.push_back(i+1);
		}
	}
	if(a.size()>=k){
		cout<<"YES"<<endl;
		for(int i=0;i<k;i++)cout<<a[i]<<' ';
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}