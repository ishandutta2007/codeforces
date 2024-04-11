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

char ans[50][60];

int a,b,c,d;
int main() {
	read(a);read(b);read(c);read(d);
	for(int i=0;i<50;i++){
		for(int j=0;j<25;j++)ans[i][j] = 'A';
		for(int j=25;j<50;j++)ans[i][j] = 'B';
	}
	for(int i=0;i<a-1;i++){
		ans[(i/10)*2+1][(i%10)*2+26] = 'A';
	}
	int cnt = 0;
	for(int i=0;i<b-1;i++){
		ans[(cnt/12)*2+1][(cnt%12)*2+1] = 'B';
		cnt+=1;
	}
	for(int i=0;i<c;i++){
		ans[(cnt/12)*2+1][(cnt%12)*2+1] = 'C';
		cnt+=1;
	}
	for(int i=0;i<d;i++){
		ans[(cnt/12)*2+1][(cnt%12)*2+1] = 'D';
		cnt+=1;
	}
	cout<<"50 50"<<endl;
	for(int i=0;i<50;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}