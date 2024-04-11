#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
//long long po(int x,int y){
//	long long res=1;
//	while(y){
//		if(y&1)res*=x;
//		x*=x;
//		x%=mod;
//		y>>=1;
//	}
//	return res;
//}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,k;
		scanf("%lld%lld",&n,&k);
		long long ans=0,p=1;
		while(k){
			if(k&1)ans+=p;
			k>>=1;
			ans%=mod;
			p*=n;
			p%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}