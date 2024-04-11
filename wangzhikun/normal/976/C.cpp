//
//  main.cpp
//  Edu Round 43
//
//  Created by  on 2018/5/5.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

pair<pair<int,int>,int> sts[300030];
int n,mr = 0,mid = 0;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	if(a.first.first!=b.first.first)return a.first.first<b.first.first;
	return a.first.second>b.first.second;
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sts[i].first.first>>sts[i].first.second;
		sts[i].second = i+1;
	}
	sort(sts,sts+n,cmp);
	for(int i=0;i<n;i++){
		if(sts[i].first.second>mr){
			mr = sts[i].first.second;
			mid = sts[i].second;
		}else{
			cout<<sts[i].second<<' '<<mid;
			return 0;
		}
	}
	cout<<-1<<' '<<-1<<endl;
	return 0;
}