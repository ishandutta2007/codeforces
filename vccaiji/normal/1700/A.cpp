#include<bits/stdc++.h>
using namespace std;
int a[1100000],b[1100000];
char s[1100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		printf("%lld\n",(m-1)*m/2+1ll*m*(n+1)*n/2);
	}
	return 0;
}