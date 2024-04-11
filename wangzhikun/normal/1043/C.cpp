//  Created by WangZhikun on 2018/10/28.

#include <cstdio>
#include <vector>
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
	int ans[1010] = {0};
	char s[1010];
	cin>>s;
	int n = strlen(s);
	char cu = s[0],ced = s[1];
	for(int i=1;i<n-1;i++){
		if(cu == s[i+1]){
			ans[i] = 1;
			swap(cu,ced);
		}else{
			ced = s[i+1];
		}
	}
	if(cu == 'b')ans[n-1] = 1;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}