#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int P=1000000007;
inline int ksm(int a,int t){
	int r=1;
	while(t){
		if(t&1) r=(ll)r*a%P;
		a=(ll)a*a%P; t>>=1;
	}
	return r;
}
const int N=1000005,M=1000000;
int pri[N>>3],pcnt,fl[N],fac[N*2],ifac[N*2],las[N];
void init(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<=2*M;i++)fac[i]=(ll)fac[i-1]*i%P;
	ifac[2*M]=ksm(fac[2*M],P-2);
	for(int i=2*M;i>=2;i--)ifac[i-1]=(ll)ifac[i]*i%P;
	for(int i=2;i<=M;i++){
		if (!fl[i]) pri[++pcnt]=i, las[i]=i;
		for(int j=1;i*pri[j]<=M&&j<=pcnt;j++){
			fl[i*pri[j]]=1; las[i*pri[j]]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
}
inline int f(int r,int k){
	if(r==0) return 2;
	int res = r+2*k;
	res = (ll)res*fac[r+k-1]%P;
	res = (ll)res*ifac[r]%P;
	res = (ll)res*ifac[k]%P;
	return res;
}
int q,r,n,t;
int main(){
	init(); int ans;
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf ("%d%d",&r,&n); ans=1;
		while (n>1){
			int p=las[n]; t=0;
			while(n%p==0) n/=p,t++;
			ans=(ll)ans*f(r,t)%P;
		}
		printf("%d\n",ans);
	}
	return 0;
}