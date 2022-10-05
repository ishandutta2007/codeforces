#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1) ans=((long long)ans*a)%p;
		a=((long long)a*a)%p;
	}
	return ans;
}
int inverse(int a){
	return qow(a,p-2);
}
int fac[1100000];
int infac[1100000];
int a[1100000];
int aa[1100000];
int aaa[1100000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=k+1;i++) fac[i]=((long long)fac[i-1]*i)%p;
	for(int i=0;i<=k+1;i++) infac[i]=inverse(fac[i]);
	a[0]=0;
	for(int i=1;i<=k+1;i++) a[i]=(a[i-1]+qow(i,k))%p;
	if(n<=k+1){
		printf("%d",a[n]);
		return 0;
	}
	aa[0]=1;
	for(int i=1;i<=k+1;i++) aa[i]=((long long)aa[i-1]*(n-(i-1)))%p;
	aaa[0]=1;
	for(int i=1;i<=k+1;i++) aaa[i]=((long long)aaa[i-1]*(n-(k+1)+(i-1)))%p;
	int ans=0;
	for(int i=0,j=qow(p-1,k+1);i<=k+1;i++,j=p-j)
		ans=(ans+(((((((((long long)aa[i]*aaa[k+1-i])%p)*j)%p)*infac[i])%p)*infac[k+1-i])%p)*a[i])%p;
	printf("%d",ans);
	return 0;
}