#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=4000005;
int n,mo,f[N],g[N],s;
int main(){
	scanf("%d%d",&n,&mo);
	for (int i=1;i<=n;i++){
		g[i]=(g[i]+g[i-1])%mo;
		f[i]=(g[i]+(i==1?1:s))%mo;
		s=(s+f[i])%mo;
		for (int j=2;j*i<=n;j++){
			int l=j*i,r=min(n,l+j-1);
			g[l]=(g[l]+f[i])%mo;
			g[r+1]=(g[r+1]+mo-f[i])%mo;
		}
	}
	cout<<f[n]<<endl;
}