#include<bits/stdc++.h>
using namespace std;

const int mo=998244353;
int S,f[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			f[j]++;
	int s=0;
	for (int i=1;i<=n;i++){
		f[i]=(f[i]+s)%mo;
		s=(s+f[i])%mo;
	}
	cout<<f[n]<<endl;
}
/*

*/