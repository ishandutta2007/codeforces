//
//  main.cpp
//  Round 492
//
//  Created by  on 2018/7/3.
//  Copyright  2018 . All rights reserved.
//


#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,a[20020],l,r,ans = 0;

int main() {
	cin>>n;
	l = 0;r = 2*n-1;
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	while(r-l>1){
		int c1,c2;
		for(int j=l;j<=r;j++){
			if(a[j] == a[l] && j!=l){
				c1 = j-l-1;
			}
			if(a[j] == a[r] && j!=r){
				c2 = r-j-1;
			}
		}
		if(c1<=c2){
			ans+=c1;
			for(int i=c1;i>0;i-=1){
				swap(a[l+i],a[l+i+1]);
			}
			l+=2;
		}else{
			ans+=c2;
			for(int i=c2;i>0;i-=1){
				swap(a[r-i],a[r-i-1]);
			}
			r-=2;
		}
		//cout<<l<<' '<<r<<endl;
	}
	cout<<ans<<endl;
	return 0;
}