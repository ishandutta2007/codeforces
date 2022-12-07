#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int mo=998244353;
const int BLK=30000;
const int FFTN=(1<<17);
const int N=FFTN+5;
int n,S,a[1005];
int inv[N],fac[N];
int w[N],W[N],R[N];
ull p[N];

int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) W[i]=1ll*W[i-1]*W[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	For(i,0,n-1) a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}


int A[N],B[N];
int v[N],V[N],IV[N];

void extend(int *a,int *b,int d,int k){
	int L=FFTinit(2*d);
	For(i,0,L-1) A[i]=B[i]=0;
	int val=power(BLK,mo-1-(d-1));
	For(i,0,d-1) A[i]=1ll*a[i]*val%mo;
	For(i,0,d-1){
		A[i]=1ll*A[i]*inv[i]%mo*inv[d-1-i]%mo;
		if ((d-1-i)&1) A[i]=mo-A[i];
	}
	For(i,1,2*d-1) v[i]=((i-d)*BLK+k+1ll*mo)%mo;
	V[0]=1;
	For(i,1,2*d-1) V[i]=1ll*V[i-1]*v[i]%mo;
	IV[2*d-1]=power(V[2*d-1],mo-2);
	Rep(i,2*d-1,1) IV[i-1]=1ll*IV[i]*v[i]%mo;
	For(i,1,2*d-1) B[i]=1ll*IV[i]*V[i-1]%mo;
	
	
	DFT(A,L); DFT(B,L);
	For(i,0,L-1) A[i]=1ll*A[i]*B[i]%mo;
	IDFT(A,L);
	For(i,0,d-1) b[i]=1ll*A[i+d]*V[i+d]%mo*IV[i]%mo;
}

int g1[N],g2[N],g3[N];
int f1[N],f2[N],f3[N];
void divide(int d){
	if (d==1){
		f1[0]=2*S-1;
		f1[1]=2*S-BLK-1;
		f2[0]=S-1;
		f2[1]=S-BLK-1;
		f3[0]=f1[0];
		f3[1]=f1[1];
		return;
	}
	int D=d/2;
	divide(D);
	
	extend(f1,g1,D+1,(D+1)*BLK);
	For(i,0,D) f1[i+D+1]=g1[i];
	extend(f1,g1,2*D+1,D);
	
	extend(f2,g2,D+1,(D+1)*BLK);
	For(i,0,D) f2[i+D+1]=g2[i];
	extend(f2,g2,2*D+1,D);
	
	extend(f3,g3,D+1,(D+1)*BLK);
	For(i,0,D) f3[i+D+1]=g3[i];
	extend(f3,g3,2*D+1,D);
	
	For(i,0,2*D){
		f3[i]=(1ll*f3[i]*g2[i]+1ll*g3[i]*f1[i])%mo;
		f1[i]=1ll*f1[i]*g1[i]%mo;
		f2[i]=1ll*f2[i]*g2[i]%mo;
	}
	
	if (d&1){
		f1[d]=f2[d]=1; f3[d]=0;
		For(i,0,d-1){
			f1[i]=1ll*f1[i]*(2*S+1ll*mo-(i*BLK+d))%mo;
			f2[i]=1ll*f2[i]*(  S+1ll*mo-(i*BLK+d))%mo;
			f3[i]=(1ll*(S+1ll*mo-(i*BLK+d))*f3[i]+f1[i])%mo;
		}
		g3[d+1]=1;
		Rep(i,d,1) g3[i]=1ll*g3[i+1]*(S+1ll*mo-(d*BLK+i))%mo;
		For(i,1,d){
			f1[d]=1ll*f1[d]*(2*S+1ll*mo-(d*BLK+i))%mo;
			f3[d]=(f3[d]+1ll*f1[d]*g3[i+1])%mo;
		}
		f2[d]=g3[1];
	}
}

int facS;
int Query(int x){
	int re=facS,v=1,fac1=1,fac2=1;
	For(i,0,(x-1)/BLK-1){
		re=(re+f3[i])%mo;
		fac1=1ll*fac1*f1[i]%mo;
		fac2=1ll*fac2*f2[i]%mo;
	}
	int L=(x-1)/BLK*BLK;
	int R=min(L+BLK,x-1);
	int tmp=0;
	g3[R+1-L]=1;
	Rep(i,R,L+1) g3[i-L]=1ll*g3[i+1-L]*(S-i)%mo;
	For(i,L+1,R){
		fac1=1ll*fac1*(2*S-i)%mo;
		if (i<x) tmp=(tmp+1ll*fac1*g3[i+1-L])%mo;
		fac2=1ll*fac2*(S-i)%mo;
	}
	re=(re+1ll*tmp*facS%mo*power(fac2,mo-2))%mo;
	//cout<<re<<endl;
	return 1ll*(mo-2)*re%mo;
}

int main(){
	init();
	FFTinit();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),S+=a[i];
	divide(BLK);
	
	facS=1;
	For(i,0,(S-1)/BLK-1)
		facS=1ll*facS*f2[i]%mo;
	for (int i=(S-1)/BLK*BLK+1;i<S;i++)
		facS=1ll*facS*(S-i)%mo;
	//cout<<facS<<' '<<(S-1)/BLK*BLK+1<<endl;
	int v=1;
	For(i,0,BLK){
		f3[i]=1ll*f3[i]*v%mo;
		v=1ll*v*f1[i]%mo;
	}
	v=1;
	For(i,0,BLK){
		v=1ll*v*f2[i]%mo;
		f3[i]=1ll*f3[i]*facS%mo*power(v,mo-2)%mo;
	}
	int vS=0,vT=Query(S);
	For(i,1,n) vS=(vS+Query(a[i]))%mo;
	int ans=1ll*(vS+mo-vT)*power(facS,mo-2)%mo;
	cout<<ans<<endl;
}