//
//  main.cpp
//  Round 485
//
//  Created by  on 2018/5/30.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>

using namespace std;

int n,p[1000010],a[1000010];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]] = i;
	}
	int cnt = 0;
	for(int i=n;i>=1;i--){
		if(a[i]!=i){
			int pts = p[i];
			p[a[i]] = pts;
			a[pts] = a[i];
			p[i] = i;
			a[i] = i;
			cnt+=1;
		}
	}
	if(cnt%2 == n%2){
		cout<<"Petr"<<endl;
	}else{
		cout<<"Um_nik"<<endl;
	}
	return 0;
}