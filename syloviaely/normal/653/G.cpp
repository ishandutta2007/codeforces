#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=300000,mo=1e9+7;
int A[100000][20];
int pd[310000],len,prime[310000],x[310000],n,m,I[310000],nI[310000],B[20],y[310000],two[310000];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2>>=1;
	}
	return k3;
}
void insert(int k1){
	for (int i=1;prime[i]*prime[i]<=k1;i++)
		if (k1%prime[i]==0){
			 int k2=1;
			 while (k1%prime[i]==0){
			 	k2++; k1/=prime[i];
			 }
			 A[i][k2]++;
		}
	if (k1>1) A[pd[k1]][2]++;
}
int C(int k1,int k2){
	if (k1<k2) return 0;
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int solve(int l,int mid,int r){
	int ans=0;
	if (l){
		for (int i=0;i<=r+mid;i++) y[i]=C(r+mid,i);
		for (int i=1;i<=r+mid;i++) y[i]=(y[i]+y[i-1])%mo;
		for (int i=0;i<=r+mid-1;i++) ans=(ans+1ll*(two[r+mid]-y[i])*C(l-1,i))%mo;
	//	cout<<"solve "<<l<<" "<<mid<<" "<<r<<" "<<ans<<" "<<two[r+mid]<<" "<<y[0]<<endl;
		ans=1ll*ans*l%mo;
	}
	if (r){
		for (int i=0;i<=r-1;i++) y[i]=C(r-1,i);
		for (int i=1;i<=r-1;i++) y[i]=(y[i]+y[i-1])%mo;
		int tot=two[n-1];
		for (int i=0;i<=r;i++)
			if (i>1) tot=(tot-1ll*(two[r-1]-y[i-2])*C(l+mid,i))%mo;
			else tot=(tot-1ll*two[r-1]*C(l+mid,i))%mo;
	//	cout<<"solve "<<l<<" "<<mid<<" "<<r<<" "<<tot<<endl;
		ans=(ans+1ll*r*tot)%mo;
	}
	return (ans+mo)%mo;
}
int solve(int kk,int *A){
	m=1;
	for (int i=1;i<=19;i++) if (A[i]>0) m=i;
	A[1]=n;
	for (int i=2;i<=m;i++) A[1]-=A[i];
	for (int i=1;i<=m;i++) B[i]=A[i];
	for (int i=1;i<=m;i++) B[i]+=B[i-1];
	int ans=0;
	for (int i=1;i<=m;i++){
		int l=B[i-1],mid=A[i],r=n-B[i];
		ans=(ans+solve(l,mid,r))%mo;
	}
	return ans;
}
int main(){
	memset(pd,0x00,sizeof pd);
	for (int i=2;i<=N;i++)
		if (pd[i]==0){
			pd[i]=++len; prime[len]=i;
			for (int j=i+i;j<=N;j+=i) pd[j]=-1;
		}
	scanf("%d",&n);
	I[0]=1; for (int i=1;i<=N;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=N;i++) nI[i]=quick(I[i],mo-2);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) insert(x[i]);
	two[0]=1;
	for (int i=1;i<=n;i++) two[i]=two[i-1]*2%mo;
	int ans=0;
	for (int i=1;i<=len;i++) ans=(ans+solve(i,A[i]))%mo;
	cout<<ans<<endl; return 0;
}