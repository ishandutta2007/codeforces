//
//  main.cpp
//  Round 487
//
//  Created by  on 2018/6/27.
//  Copyright  2018 . All rights reserved.
//

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	char ch = getchar();
	x = 0;while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x = x*10+ch-48;
		ch = getchar();
	}
}

char a[110],n,ans = 0;

int main() {
	cin>>a;
	n = strlen(a);
	for(int i=1;i<n-1;i++){
		if(a[i-1]!='.' && a[i]!='.' && a[i+1]!='.'){
			if(a[i-1]!=a[i] && a[i]!=a[i+1] && a[i+1]!=a[i-1]){
				ans = 1;
			}
		}
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}