#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int A[210000],len,where[210000],w[210000],n,m,phi[210000],f[210000],pre[210000],tot[210000],g[210000],pd[210000];
int getphi(int k){
	int ans=1;
	for (int i=2;i*i<=k;i++)
		if (k%i==0){
			k/=i; ans*=(i-1);
			while (k%i==0){
				ans*=i; k/=i;
			}
		}
	if (k>1) ans*=(k-1);
	return ans;
}
void getdp(int k){
	pre[k]=-1; f[k]=0;
	if (w[k]==tot[k]){
		f[k]=-1e9; return;
	}
	for (int i=1;i<=len;i++)
		if (A[i]!=k&&A[i]%k==0)
			if (f[A[i]]>f[k]){
				f[k]=f[A[i]]; pre[k]=A[i];
			}
	f[k]+=tot[k]-w[k];
}
int pr=1,prew;
int quick(int k1,int k2,int mo){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k1=1ll*k1*k1%mo; k2>>=1;
	}
	return k3;
}
void getnext(int k2,int num){
	int w=num/prew; int prek2=k2,prenum=num;
	pr=1ll*pr*w%n; pr/=num,k2/=num; int mo=n/num;
	int rev=1ll*k2*quick(pr,phi[mo]-1,mo)%mo;
	pr=prek2; prew=prenum;
	rev=1ll*rev*w%n;
	printf("%d ",rev);
}
void printans(int k){
	for (int i=0;i<n;i++) if (g[i]==k&&pd[i]==0) getnext(i,k);
	if (pre[k]==-1) return;
	printans(pre[k]);
}
int main(){
	scanf("%d%d",&m,&n); prew=1;
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1); w[__gcd(k1,n)]++; pd[k1]=1;
	}
	for (int i=0;i<n;i++) g[i]=__gcd(i,n),tot[g[i]]++;
	for (int i=1;i<=n;i++)
		if (n%i==0) A[++len]=i,where[i]=len;
	for (int i=1;i<=len;i++){
		phi[A[i]]=getphi(A[i]);
	}
	for (int i=len;i;i--) getdp(A[i]);
	int where=A[1];
	for (int i=1;i<=len;i++) if (f[A[i]]>f[where]) where=A[i];
	printf("%d\n",f[where]);
	printans(where);
}