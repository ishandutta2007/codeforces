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
	vector<int> ans;
	int n,a[1010];
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	for(int i=n-1;i>0;i--)a[i] = a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int ok = 1;
		for(int j=0;j+i<n;j++){
			if(a[j]!=a[j+i])ok=0;
		}
		if(ok)ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}