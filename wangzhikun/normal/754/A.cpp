//
//  main.cpp
//  CF WJH
//
//  Created by  on 2018/4/15.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>

using namespace std;

int n,a[110],zc = 0,l,lv = 0,ansl[110],ansr[110];

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] == 0)zc+=1;
	}
	if(zc == n){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(a[i] == 0||a[i] == 102020)continue;
		int l = i-1,r = i+1;
		if(i>0)  for(l=i-1;l>=0&&a[l] == 0;l--) a[l] = 102020;
		if(i<n-1)for(r=i+1;r<n&&a[r] == 0;r++) a[r] = 102020;
		ansl[cnt] = l+2;
		ansr[cnt] = r;
		cnt+=1;
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<ansl[i]<<' '<<ansr[i]<<endl;
	}
	return 0;
}