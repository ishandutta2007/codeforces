#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,A=1,B=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)A=1ll*A*i%mod;
	for(int i=1;i<n;i++)B=(B<<1)%mod;
	printf("%d\n",(A-B+mod)%mod); 
	return 0;
}