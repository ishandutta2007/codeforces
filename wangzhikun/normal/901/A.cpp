//
//  main.cpp
//  Round 453
//
//  Created by  on 2018/5/17.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n,cu,ls,su,o = 0;
int ansa[200020],ansb[200020];
int main() {
	cin>>n;
	n+=1;
	ls = 1;
	su = 0;
	for(int i=0;i<n;i++){
		cin>>cu;
		if(ls>1 && cu>1){
			o = 1;
			ansa[su+1] = ansb[su+1] = su;
			for(int i = su+2;i<=su+cu;i++){
				ansa[i] = su;
				ansb[i] = su-1;
			}
		}else{
			for(int i = su+1;i<=su+cu;i++) ansa[i] = ansb[i] = su;
		}
		su+=cu;
		ls = cu;
	}
	if(o){
		cout<<"ambiguous"<<endl;
		for(int i = 1;i<=su;i++) cout<<ansa[i]<<' ';
		cout<<endl;
		for(int i = 1;i<=su;i++) cout<<ansb[i]<<' ';
		cout<<endl;
	}else{
		cout<<"perfect"<<endl;
	}
	return 0;
}