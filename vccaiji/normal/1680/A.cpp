#include<bits/stdc++.h>
using namespace std;
int n;
char s[2100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(max(l1,l2)<=min(r1,r2))cout<<max(l1,l2)<<"\n";
		else cout<<l1+l2<<"\n";
	}
	return 0;
}