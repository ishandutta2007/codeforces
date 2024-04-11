#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
inline int qow(int a,int n){
	int ans=1;
	for(a%=p;n;n>>=1){
		if(n&1) ans=(1ll*ans*a)%p;
		a=(1ll*a*a)%p;
	}
	return ans;
}
inline int inverse(int a){
	return qow(a,p-2);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int pp=0;pp<T;pp++){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int t=inverse(qow(2,n-m));
		int ans=0;
		if(n==m){
			printf("%lld\n",(1ll*n*k)%p);
			continue;
		}
		for(int i=0;i<m;i++){
			ans=(ans+1ll*t*(m-i))%p;
			t=(1ll*t*((1ll*((p+1)/2)*((1ll*(n-m+i)*inverse(i+1))%p))%p))%p;
		}
		printf("%lld\n",(1ll*k*ans)%p);
	}
	return 0;
}