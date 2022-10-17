#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100005,mod=998244353;
int T,n;
int fac[maxn],nfac[maxn],inv[maxn];
string s;
inline int C(int n,int m){
	return n<m? 0:1ll*fac[n]*nfac[m]%mod*nfac[n-m]%mod;
}
int main(){
	fac[0]=nfac[0]=fac[1]=nfac[1]=inv[1]=1;
	for(int i=2;i<=100000;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s;
		int cnt=0,tot=1;
		for(int i=1;i<n;i++)
			if(s[i]=='1'&&s[i-1]=='1')
				cnt++,i++; 
		for(int i=0;i<n;i++)
			tot+=s[i]=='0';
		printf("%d\n",C(tot+cnt-1,cnt));
	}
	return 0;
}