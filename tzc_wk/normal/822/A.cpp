#include <bits/stdc++.h>
using namespace std;
int f[14];
int main(){
	f[0]=1;
	for(int i=1;i<=12;i++)	f[i]=f[i-1]*i;
	int a,b;cin>>a>>b;
	cout<<f[min(a,b)]<<endl;
}