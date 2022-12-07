#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
const int mo=998244353;
int mu[N],f[N];
int n,m,l[55],r[55];
void init(){
	mu[1]=1;
	for (int i=1;i<N;i++)
		for (int j=2;j*i<N;j++)
			mu[i*j]-=mu[i];
}
int F(int x){
	int M=m/x;
	for (int i=0;i<=M;i++) f[i]=(i==0?1:0);
	for (int i=1;i<=n;i++){
		int pl=(l[i]+x-1)/x,pr=r[i]/x;
		for (int j=1;j<=M;j++) f[j]=(f[j]+f[j-1])%mo;
		for (int j=M;j>=0;j--) f[j]=((j>=pl?f[j-pl]:0)+mo-(j>pr?f[j-pr-1]:0))%mo;
	}
	int sum=0;
	for (int j=0;j<=M;j++) sum=(sum+f[j])%mo;
	return sum;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	int ans=0;
	for (int i=1;i<=m;i++)
		if (mu[i]) ans=(ans+1ll*F(i)*(mo+mu[i]))%mo;
	cout<<ans<<endl;
}