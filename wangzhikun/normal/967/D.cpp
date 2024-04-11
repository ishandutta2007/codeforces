//
//  main.cpp
//  Round 477
//
//  Created by  on 2018/4/29.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,x1,x2;

struct server{
	ll cap,id;
}c[300030];

bool cmp(server a,server b){
	return a.cap<b.cap;
}
vector<ll> usage[2];

bool solve(ll a,ll b,ll desc){
	ll lb = -1;
	for(int i=n-1;i>=0;i--){
		if((n-i)*c[i].cap>=b){lb = i;break;}
	}
	if(lb == -1)return 0;
	for(int i=0;i<n;i++){
		if(i+((a+c[i].cap-1)/c[i].cap)-1<lb){
			for(int j=i;j<i+((a+c[i].cap-1)/c[i].cap);j++){
				usage[desc].push_back(c[j].id);
			}
			for(int j=lb;j<n;j++){
				usage[desc^1].push_back(c[j].id);
			}
			return 1;
		}
	}
	return 0;
}

void opt(){
	cout<<"Yes"<<endl;
	cout<<usage[0].size()<<' '<<usage[1].size()<<endl;
	for(int i=0;i<usage[0].size();i++){
		cout<<usage[0][i]<<' ';
	}
	cout<<endl;
	for(int i=0;i<usage[1].size();i++){
		cout<<usage[1][i]<<' ';
	}
	cout<<endl;
}

int main() {
	cin>>n>>x1>>x2;
	for(int i=0;i<n;i++){
		cin>>c[i].cap;
		c[i].id = i+1;
	}
	sort(c,c+n,cmp);
	if(solve(x1,x2,0)){
		opt();
		return 0;
	}
	if(solve(x2,x1,1)){
		opt();
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}