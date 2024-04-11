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

int n,ans = 0;
char b[20][20],a[20][20],c[20][20],d[20][20];

void flipx(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j] = c[i][n-j-1];
}

void flipy(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j] = c[n-i-1][j];
}

void flipn(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j] = c[i][j];
}

void check(){
	int can = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j] != d[i][j]) can = 0;
	if(can) ans = 1;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<4;i++){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				c[i][j] = b[n-j-1][i];
		flipn();
		check();
		flipx();
		check();
		flipy();
		check();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				b[i][j] = c[i][j];
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}