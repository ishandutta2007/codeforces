#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int K,I[31000],nI[31000],C[31000],D[31000],fir[31000],mi[31000],en[31000];
int ans[31000],E[31000],F[31000];
long long n;
const int mo=1e9+7,N=32000;
const long double pi=acos(-1);
struct atom{
	long double x,y;
}A[70000],B[70000];
atom operator + (atom k1,atom k2){
	return (atom){k1.x+k2.x,k1.y+k2.y};
}
atom operator - (atom k1,atom k2){
	return (atom){k1.x-k2.x,k1.y-k2.y};
}
atom operator * (atom k1,atom k2){
	return (atom){k1.x*k2.x-k1.y*k2.y,k1.x*k2.y+k1.y*k2.x};
}
void fft(atom *A,int n,int fl=1){
	for (int j=1,i=(n>>1);j<n;j++){
		if (i<j) swap(A[i],A[j]); int k=(n>>1);
		for (;i&k;i^=k,k>>=1); i^=k;
	}
	for (int m=2;m<=n;m<<=1){
		atom w=(atom){cos(2*pi*fl/m),sin(2*pi*fl/m)};
		for (int i=0;i<n;i+=m){
			atom cur=(atom){1,0};
			for (int j=i;j<i+(m>>1);j++){
				atom u=A[j],v=A[j+(m>>1)]*cur;
				A[j]=u+v; A[j+(m>>1)]=u-v;
				cur=cur*w;
			}
		}
	}
}
void chen(int *x,int *y,int *ans){
//	cout<<"chen"<<endl;
//	for (int i=0;i<K;i++) cout<<x[i]<<" "; cout<<endl;
//	for (int i=0;i<K;i++) cout<<y[i]<<" "; cout<<endl;
	int len=1; while ((1<<len)<(K<<1)) len++;
	for (int i=0;i<K;i++) A[i]=(atom){x[i],0},B[i]=(atom){y[i],0};
	for (int i=K;i<(1<<len);i++) A[i]=(atom){0,0},B[i]=(atom){0,0};
//	for (int i=0;i<K;i++) cout<<(double)B[i].x<<" "<<(double)B[i].y<<endl;
	fft(A,1<<len); fft(B,1<<len);
	for (int i=0;i<(1<<len);i++) A[i]=A[i]*B[i];
	fft(A,1<<len,-1);
//	for (int i=0;i<K;i++) cout<<(double)A[i].x<<" "<<(double)A[i].y<<endl;
	for (int i=0;i<K;i++){
		long long k1=(long long)(A[i].x/(1<<len)+0.5);
		ans[i]=k1%mo;
	}
//	for (int i=0;i<K;i++) cout<<ans[i]<<" "; cout<<endl;
}
void chen(int *x,int *y){
//	cout<<"chen"<<endl;
//	for (int i=0;i<K;i++) cout<<x[i]<<" "; cout<<endl;
//	for (int i=0;i<K;i++) cout<<y[i]<<" "; cout<<endl;
	for (int i=0;i<K;i++){
		C[i]=x[i]%N; D[i]=y[i]%N;}
	chen(C,D,fir);
	for (int i=0;i<K;i++){
		C[i]=(x[i]%N+x[i]/N);
		D[i]=(y[i]%N+y[i]/N);
	}
	chen(C,D,mi);
	for (int i=0;i<K;i++){
		C[i]=(x[i]/N); D[i]=(y[i]/N);
	}
	chen(C,D,en);
	for (int i=0;i<K;i++) mi[i]=((mi[i]-1ll*fir[i]-en[i])%mo+mo)%mo;
	for (int i=0;i<K;i++) x[i]=(fir[i]+1ll*mi[i]*N+1ll*en[i]*N%mo*N)%mo;
//	for (int i=0;i<K;i++) cout<<x[i]<<" "; cout<<endl;
}
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int CC(int k1,int k2){
	if (k2>k1) return 0; return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
void getans(int k){
	if (k==0){
		ans[0]=1; return;
	}
	getans(k>>1);
	for (int i=0;i<K;i++) E[i]=ans[i];
	for (int i=0;i<K;i++) F[i]=ans[i];
	int si=(k>>1);
	for (int i=0;i<K;i++) E[i]=1ll*E[i]*quick(2,1ll*si*i%(mo-1))%mo*nI[i]%mo;
	for (int i=0;i<K;i++) F[i]=1ll*F[i]*nI[i]%mo;
	chen(E,F);
	for (int i=0;i<K;i++) ans[i]=1ll*E[i]*I[i]%mo;
	if (k&1){
		for (int i=0;i<K;i++) E[i]=1ll*ans[i]*quick(2,i)%mo*nI[i]%mo;
		F[0]=0;
		for (int i=1;i<K;i++) F[i]=nI[i];
		chen(E,F);
		for (int i=0;i<K;i++) ans[i]=1ll*E[i]*I[i]%mo;
	}
	//cout<<"fa "<<k<<endl;
	//for (int i=0;i<K;i++) cout<<ans[i]<<" "; cout<<endl;
}
int main(){
	scanf("%I64d%d",&n,&K);
	if (n>K){
		printf("0\n"); return 0;
	}
	I[0]=1;
	for (int i=1;i<=K;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=K;i++) nI[i]=quick(I[i],mo-2);
	int now=0; K++;
	getans(n);
	int an=0;
	for (int i=0;i<K;i++) an=(an+1ll*CC(K-1,i)*ans[i])%mo;
	printf("%d\n",an);
	return 0;
}