#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int mo=998244353,g=3;
int n,G[30],nG[30],two[30],m;
struct atom{
	int l,r;
};
int C[10000000],tot;
int A[500000],B[600000],I[500000],nI[500000];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2=k2/2;
	}
	return k3;
}
void fft(int *x,int n,int fl=1){
	for (int i=(n>>1),j=1;j<n;j++){
		if (i<j) swap(x[i],x[j]);
		int k;
		for (k=(n>>1);k&i;i^=k,k>>=1); i^=k;
	}
	int now=0;
	for (int m=2;m<=n;m<<=1){
		int w; now++; if (fl>0) w=G[now]; else w=nG[now]; 
		for (int i=0;i<n;i+=m){
			int cur=1;
			for (int j=i;j<i+(m>>1);j++){
				int u=x[j],v=1ll*x[j+(m>>1)]*cur%mo;
				x[j]=(u+v)%mo; x[j+(m>>1)]=(u-v+mo)%mo;
				cur=1ll*cur*w%mo;
			}
		}
	}
}
atom solve(int l,int r){
	if (l>r){
		C[++tot]=1; return (atom){tot,tot};
	}
	if (l==r){
		C[++tot]=l; C[++tot]=1; return (atom){tot-1,tot};
	}
	int mid=(l+r)>>1; atom k1=solve(l,mid),k2=solve(mid+1,r);
	int n=max(mid-l+1,r-mid),len=1;
	while ((1<<len)<=(n<<1)) len++;
	for (int i=0;i<(1<<len);i++){A[i]=0; B[i]=0;}
	for (int i=k1.l;i<=k1.r;i++)A[i-k1.l]=C[i]; 
	for (int i=k2.l;i<=k2.r;i++)B[i-k2.l]=C[i];
	fft(A,1<<len); fft(B,1<<len);
	for (int i=0;i<(1<<len);i++) A[i]=1ll*A[i]*B[i]%mo;
	fft(A,1<<len,-1);
	for (int i=0;i<(1<<len);i++) A[i]=1ll*A[i]*two[len]%mo;
	atom ans; ans.l=tot+1;
	for (int i=0;i<=r-l+1;i++) C[++tot]=A[i]; ans.r=tot; 
	return ans;
}
int k1,k2;
int main(){
	scanf("%d%d%d",&n,&k1,&k2); n--;
	if (k1==0||k2==0||k1+k2-2>n){
		printf("0\n"); return 0;
	}
	if (n==0){
		printf("1\n"); return 0;
	}
	k1--; k2--; //cout<<"asd "<<k1<<" "<<k2<<endl;
	int now=(mo-1)/2,ng=quick(g,mo-2),len=0;
	while (now%2==0){
		len++; G[len]=quick(g,now); nG[len]=quick(ng,now); two[len]=quick(1<<len,mo-2); now>>=1;
	}
	atom k=solve(1,n-1);
	//for (int i=k.l;i<=k.r;i++) cout<<C[i]<<" "; cout<<endl;
	int ans=C[k.l+k1+k2-1]; 
	I[0]=1; for (int i=1;i<=k1+k2;i++) I[i]=1ll*I[i-1]*i%mo;
	//cout<<ans<<" "<<I[k1+k2]<<" "<<quick(I[k1],mo-2)<<" "<<quick(I[k2],mo-2)<<endl;
	ans=1ll*ans*I[k1+k2]%mo*quick(I[k1],mo-2)%mo*quick(I[k2],mo-2)%mo; cout<<ans<<endl;
	return 0;
}