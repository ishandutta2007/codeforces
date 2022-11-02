#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50],T,n,M;
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&M);
		int len;
		int k=2;n--;a[len=1]=1;
		while (n>k){
			a[++len]=k;
			n-=k;
			k<<=1;
		}
		a[++len]=n;
		int ans=1;
		for (int i=1;i<=len;i++)(ans*=1+a[i])%=M;
		printf("%lld\n",(ans-1+M)%M);
	}
}