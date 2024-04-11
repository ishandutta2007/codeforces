//  Created by WangZhikun on 2018/10/28.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}
int main() {
	int n,a,s = 0,cc = 0;
	read(n);
	for(int i=0;i<n;i++){
		read(a);
		s+=a;
		cc = max(cc,a);
	}
	for(int i=cc;i;i++){
		if(i*n-s>s){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}