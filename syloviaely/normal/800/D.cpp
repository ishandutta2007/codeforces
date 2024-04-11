#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000000,mo=1e9+7;
int A[N+10],B[N+10],C[N+10],n,ans[N+10],two[N+10];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		A[k1]++; B[k1]=(B[k1]+k1)%mo; C[k1]=(C[k1]+1ll*k1*k1)%mo;
	}
	two[0]=1;
	for (int i=1;i<=N;i++) two[i]=two[i-1]*2%mo;
	for (int i=1;i<N;i*=10)
		for (int j=N-1;j>=0;j--)
			if ((j/i)%10!=9){
				A[j]=(A[j]+A[i+j])%mo; 
				B[j]=(B[j]+B[i+j])%mo; 
				C[j]=(C[j]+C[i+j])%mo; 
			}
	for (int i=0;i<N;i++){
		if (A[i]==0) continue;
		if (A[i]==1) ans[i]=C[i];
		else ans[i]=1ll*two[A[i]-2]*(1ll*B[i]*B[i]%mo+C[i])%mo;
	}
	for (int i=1;i<N;i*=10)
		for (int j=0;j<N;j++)
			if ((j/i)%10!=9) ans[j]=(ans[j]-ans[i+j])%mo;
	for (int i=0;i<N;i++) ans[i]=(ans[i]+mo)%mo;
	long long num=0;
	for (int i=0;i<N;i++) num^=(1ll*i*ans[i]);
	cout<<num<<endl;
	return 0;
}