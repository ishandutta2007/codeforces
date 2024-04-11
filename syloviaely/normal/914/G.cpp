#include <bits/stdc++.h>
using namespace std;
const int N=1<<17,mo=1e9+7,inv2=(mo+1)/2,M=17;
int s[N],n,A[N],B[N],C[N][18],fib[N];
void dft1(int l,int r,int *a){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	dft1(l,mid,a); dft1(mid+1,r,a);
	for (int i=0;i<len;i++){
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=(x1+x2)%mo;
	}	
}
void idft1(int l,int r,int *a){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	idft1(l,mid,a); idft1(mid+1,r,a);
	for (int i=0;i<len;i++){
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=(x1-x2+mo)%mo;
	}
}
void dft(int l,int r,int *a){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	dft(l,mid,a); dft(mid+1,r,a);
	for (int i=0;i<len;i++){
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=(x1+x2)%mo;
		a[l+len+i]=(x1-x2+mo)%mo;
	}	
}
void idft(int l,int r,int *a){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	for (int i=0;i<len;i++){
		int x1=a[l+i],x2=a[l+len+i];
		a[l+i]=1ll*inv2*(x1+x2)%mo;
		a[l+len+i]=1ll*inv2*(x1-x2+mo)%mo;
	}
	idft(l,mid,a); idft(mid+1,r,a);
}
void dft2(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	dft2(l,mid); dft2(mid+1,r);
	for (int i=0;i<len;i++){
		for (int j=0;j<=17;j++)
		 	C[l+i+len][j]=(C[l+i][j]+C[l+len+i][j])%mo;
	}	
}
void idft2(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1,len=(r-l+1)>>1;
	idft2(l,mid); idft2(mid+1,r);
	for (int i=0;i<len;i++){
		for (int j=0;j<=17;j++)
		 	C[l+i+len][j]=(C[l+i+len][j]-C[l+i][j]+mo)%mo;
	}
}
int D[18];
int main(){
	scanf("%d",&n);
	fib[0]=0; fib[1]=1;
	for (int i=2;i<N;i++) fib[i]=(fib[i-1]+fib[i-2])%mo;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); s[k1]++;
	}
	memcpy(A,s,sizeof s);
	dft(0,N-1,A);
	for (int i=0;i<N;i++) A[i]=1ll*A[i]*A[i]%mo;
	idft(0,N-1,A);
	for (int i=0;i<N;i++) C[i][__builtin_popcount(i)]=s[i];
	dft2(0,N-1);
	for (int i=0;i<N;i++){
		memset(D,0x00,sizeof D);
		for (int j=0;j<=17;j++)
			for (int k=0;k<=17-j;k++)
				D[j+k]=(D[j+k]+1ll*C[i][j]*C[i][k])%mo;
		memcpy(C[i],D,sizeof D);
	}
	idft2(0,N-1);
	for (int i=0;i<N;i++) B[i]=C[i][__builtin_popcount(i)];
	for (int i=0;i<N;i++){
		A[i]=1ll*A[i]*fib[i]%mo;
		B[i]=1ll*B[i]*fib[i]%mo;
		s[i]=1ll*s[i]*fib[i]%mo;
	}
	dft1(0,N-1,A); dft1(0,N-1,B); dft1(0,N-1,s);
	for (int i=0;i<N;i++) s[i]=1ll*s[i]*A[i]%mo*B[i]%mo;
	idft1(0,N-1,s); int ans=0;
	for (int i=0;i<17;i++) ans=(ans+s[1<<i])%mo;
	cout<<ans<<endl; return 0;
}