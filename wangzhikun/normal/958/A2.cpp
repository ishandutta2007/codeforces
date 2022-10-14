//
//  main.cpp
//  Death Stars
//
//  Created by  on 2018/4/14.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int n,m,B = 19260817,C = 1e9+7;
char a[2020][220],b[220][2020];
ull hsha[2020],hshb[220][2020],hsa[2020],hsb[2020];

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	ull t = 1;
	for(int i=0;i<m;i++)t*=C;
	ull x = 1;
	for(int i=0;i<m;i++)x*=B;
	
	for(int i=0;i<n;i++){
		hsha[i] = a[i][0];
		for(int j=1;j<m;j++)hsha[i] = hsha[i]*B+a[i][j];
	}
	hsa[0] = hsha[0];
	for(int i=1;i<m;i++) hsa[i] = hsa[i-1]*C+hsha[i];
	for(int i=m;i<n;i++){
		hsa[i] = hsa[i-1]*C+hsha[i]-hsha[i-m]*t;
	}
	for(int i=0;i<m;i++){
		hshb[i][0] = b[i][0];
		for(int j=1;j<m;j++)hshb[i][j] = hshb[i][j-1]*B+b[i][j];
		for(int j=m;j<n;j++){
			hshb[i][j] = hshb[i][j-1]*B+b[i][j]-b[i][j-m]*x;
		}
	}
	for(int i=0;i<n;i++){
		hsb[i] = hshb[0][i];
		for(int j=1;j<m;j++) hsb[i] = hsb[i]*C+hshb[j][i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(hsa[i] == hsb[j]){
				cout<<i-m+2<<' '<<j-m+2<<endl;
				return 0;
			}
		}
	}
	return 0;
}