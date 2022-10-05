#include<bits/stdc++.h>
using namespace std;
int a[4100000];
int main(){
	a[1]=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n/i;j++)a[i*j]=(a[i*j]+1ll*a[i]+m-a[i-1])%m;
		a[i+1]=(a[i]+a[i+1])%m;
		a[i+1]=(a[i]+a[i+1])%m;
		if(i==1)a[2]=2;
	}
	cout<<a[n];
	return 0;
}