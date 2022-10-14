#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,cur,lc = -1,l = 1000000000,ans = 1,x,y,lx,ly;
int st[200020] = {0};
int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>st[i];
	for(int i=1;i<n;i++){
		cur = st[i];
		lc = st[i-1];
		if(abs(cur-lc)>1){
			//cout<<abs(cur-lc)<<endl;
			if(l==1000000000)l = abs(cur-lc);
			if(abs(cur-lc)!=l)ans = 0;
		}
	}
	for(int i=1;i<n;i++){
		cur = st[i]-1;
		lc = st[i-1]-1;
		x = cur/l;
		y = cur%l;
		lx = lc/l;
		ly = lc%l;
		//cout<<abs(y-ly)<<' '<<abs(x-lx)<<endl;
		if(abs(y-ly)+abs(x-lx)>1)ans = 0;
		if(abs(y-ly)+abs(x-lx)==0)ans = 0;
	}
	if(ans == 1){
		cout<<"YES"<<endl;
		cout<<1000000000<<' '<<l<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}