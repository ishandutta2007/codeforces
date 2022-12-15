#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;
	int t=0;
	while(xb!=0||yb!=0){
		if(xb)xb--;
		if(yb)yb--;
		t++;
		if(abs(xa-xb)+abs(ya-yb)<=t){
			cout<<"Polycarp\n";
			return 0;
		}
	}
	cout<<"Vasiliy\n";
}