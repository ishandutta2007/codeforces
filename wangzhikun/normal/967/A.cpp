//
//  main.cpp
//  Round 477
//
//  Created by  on 2018/4/29.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,s,l = 0,c,h,m;

int main() {
	cin>>n>>s;
	l = -s;
	for(int i=0;i<n;i++){
		cin>>h>>m;
		c = h*60+m;
		if(c-l>=2*s+1){
			cout<<(l+s)/60<<' '<<(l+s)%60<<endl;
			return 0;
		}
		l = c+1;
	}
	cout<<(l+s)/60<<' '<<(l+s)%60<<endl;
	return 0;
}