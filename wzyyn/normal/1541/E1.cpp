#include<bits/stdc++.h>
using namespace std;

const int N=10005;
const int mo=1000000007;
int n,c[N],b[N],f[N],X;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%*d%d",&X);
	f[0]=1;
	int s=0,v=X;
	for (int i=1;i<=n;i++){
		for (int j=1;j<N;j++)
			f[j]=(f[j]+f[j-1])%mo;
		for (int j=N-1;j>=c[i]+1;j--)
			f[j]=(f[j]+mo-f[j-c[i]-1])%mo; 
		s+=v; v+=b[i];
		for (int j=0;j<N&&j<s;j++)
			f[j]=0;
	}
	int ans=0;
	for (int j=0;j<N;j++)
		ans=(ans+f[j])%mo;
	cout<<ans<<endl;
}