#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,f[10000000];
signed main(){
	cin>>n;memset(f,10,sizeof(f));f[0]=0;
	for (int i=1;i<=9;i++)f[i]=1;
	for (int i=10;i<=n;i++){
		int k=i;while (k)f[i]=min(f[i-k%10]+1,f[i]),k/=10;
	} cout<<f[n]<<endl;
}