//
//  main.cpp
//  CF470
//
//  Created by  on 2018/4/21.
//  Copyright  2018 . All rights reserved.
//

#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;


int n,a[300030],cp,tn = 2;

struct tr{
	int ls = 0,rs = 0,n = 0,v;
} alt[10000030];

void insert(int x){
	int op = 1;
	for(int i=30;i>=0;i--){
		if(x& 1<<i){
			if(alt[op].ls == 0){
				alt[op].ls = tn;
				tn+=1;
			}
			op = alt[op].ls;
		}else{
			if(alt[op].rs == 0){
				alt[op].rs = tn;
				tn+=1;
			}
			op = alt[op].rs;
		}
		alt[op].n+=1;
	}
	alt[op].v = x;
}

int query(int x){
	int op = 1;
	for(int i=30;i>=0;i--){
		if(x& 1<<i){
			if(alt[alt[op].ls].n)op = alt[op].ls;
			else op = alt[op].rs;
		}else{
			if(alt[alt[op].rs].n)op = alt[op].rs;
			else op = alt[op].ls;
		}
		alt[op].n-=1;
	}
	return alt[op].v;
}


int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>cp;
		insert(cp);
	}
	for(int i=0;i<n;i++){
		cp = query(a[i]);
		cout<<(cp^a[i])<<' ';
	}
	cout<<endl;
	return 0;
}