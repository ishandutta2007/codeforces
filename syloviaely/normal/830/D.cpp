#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo=1e9+7;
int f[500][500],C[500][500],I[500],nI[500];
long long A[500];
int n;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int main(){
	scanf("%d",&n);
	f[0][0]=1;
	for (int i=0;i<=n;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	I[0]=1; for (int i=1;i<=n;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=n;i++) nI[i]=quick(I[i],mo-2);
	for (int i=1;i<=n;i++){
		f[i][0]=1; memset(A,0x00,sizeof A); A[0]=1;
		for (int j=n;j;j--)
			for (int k=0;k<=j;k++)
				if (A[j]<0) A[j]+=1ll*f[i-1][k]*f[i-1][j-k];
				else A[j]+=1ll*(f[i-1][k]-mo)*f[i-1][j-k]; 
		for (int j=1;j<=n;j++) A[j]=1ll*(A[j]%mo+mo)*I[j]%mo;
		for (int j=n;j;j--)
			f[i][j]=(1ll*(2*j+1)*A[j]+1ll*j*A[j+1]+1ll*j*A[j-1])%mo*nI[j]%mo;
	}
	printf("%d\n",f[n][1]);
	return 0;
}