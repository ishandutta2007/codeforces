//
//  main.cpp
//  Round 483
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,a[5050][5050],b[5050][5050] = {0};
int q,l,r;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[0][i];
		b[0][i] = a[0][i];
	}
	for(int l = 1;l<n;l++){
		for(int i=0;i<n-l;i++){
			a[l][i] = a[l-1][i]^a[l-1][i+1];
			b[l][i] = max(b[l-1][i],b[l-1][i+1]);
			b[l][i] = max(b[l][i],a[l][i]);
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		cout<<b[r-l][l-1]<<endl;
	}
	return 0;
}