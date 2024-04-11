//
//  main.cpp
//  Interactive
//
//  Created by  on 2018/5/11.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;
int n,a,b,c,d,ans[100010];
int main() {
	cin>>n;
	cout<<"? 1 2\n? 1 3\n? 2 3\n";
	fflush(stdout);
	cin>>a>>b>>c;
	d = (a+b+c)/2;
	ans[1] = d-c;
	ans[2] = d-b;
	ans[3] = d-a;
	for(int i=4;i<=n;i++){
		cout<<"? 1 "<<i<<endl;
		fflush(stdout);
		cin>>d;
		ans[i] = d-ans[1];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}