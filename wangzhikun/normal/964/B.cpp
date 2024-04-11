//
//  main.cpp
//  CF pre
//
//  Created by  on 2018/4/17.
//  Copyright  2018 . All rights reserved.
//

#include <set>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;

int n,a,b,c,t,T[1010],ans = 0;
int main() {
	cin>>n>>a>>b>>c>>t;
	for(int i=0;i<n;i++){
		cin>>T[i];
	}
	if(b<c){
		for(int i=0;i<n;i++){
			ans+=(t-T[i])*(c-b)+a;
		}
	}else{
		for(int i=0;i<n;i++){
			ans+=a;
		}
	}
	cout<<ans<<endl;
	return 0;
}