#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int x[110000],A[100];
int n,m,len;
int phi(int K){
	int num=1;
	for (int i=2;i*i<=K;i++)
		while (K%i==0){
			num*=(i-1);
			K/=i;
			while (K%i==0){
				K/=i; num*=i;
			}
		}
	if (K>1) num*=(K-1);
	return num;
}
int quick(int k1,int k2,int mo){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int forcecalc(int l,int r){
	int num=1;
	for (int i=r;i>=l;i--){
		if (x[i]==1){
			num=1; continue;
		}
		long long ans=1;
		for (int j=1;j<=num;j++){
			ans=min(40ll,ans*x[j]);
			if (ans>=40) break;
		}
		num=ans;
	}
	return num;
}
int getans(int l,int r,int w){
	if (A[w]==1) return forcecalc(l,min(r,l+6));
	if (l>r||x[l]==1) return 1;
	int num=getans(l+1,r,w+1);
	if (num<40){
		long long tot=1;
		for (int i=1;i<=num;i++){
			tot*=x[l]; if (tot>=40) break;
		}
		if (tot<40) return tot;
	}
	num=quick(x[l],num,A[w]);
	return (num-40+A[w])%A[w]+40;
}
void calc(){
	int l,r; scanf("%d%d",&l,&r);
	printf("%d\n",getans(l,r,1)%m);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	len=1; A[1]=m; while (A[len]>1){len++; A[len]=phi(A[len-1]);}
	int q; scanf("%d",&q);
	for (;q;q--) calc();
	return 0;
}