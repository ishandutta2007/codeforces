#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define ldb long double
using namespace std;
const int FFTN=1<<19;
const int N=FFTN+5;
int n,m,mo;
struct E{
	ldb r,i;
	E(){}
	E(ldb _r,ldb _i){
		r=_r; i=_i;
	}
	E operator +(const E &a)const{
		return E(r+a.r,i+a.i);
	}
	E operator -(const E &a)const{
		return E(r-a.r,i-a.i);
	}
	E operator *(const E &a)const{
		return E(r*a.r-i*a.i,r*a.i+i*a.r);
	}
	E conj(){
		return E(r,-i);
	}
};
E W[N],w[N];
void FFTinit(){
	ldb pi=2*acos(-1),ang=pi/FFTN;
	For(i,0,FFTN) W[i]=E(cos(i*ang),sin(i*ang));
}
int R[N];
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(E *a,int n){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				E y=a[i+j+d]*w[j];
				a[i+j+d]=a[i+j]-y;
				a[i+j]=a[i+j]+y;
			}
	}
}
void IDFT(E *a,int n){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				E y=a[i+j+d]*w[j];
				a[i+j+d]=a[i+j]-y;
				a[i+j]=a[i+j]+y;
			}
	}
}
E A[N],B[N],C[N],D[N];
void mul(int *a,int *b,int *c,int la,int lb){
	int L=FFTinit(la+lb);
	For(i,0,L-1) A[i]=B[i]=E(0,0);
	For(i,0,la) A[i]=E(a[i]&1023,a[i]>>10);
	For(i,0,lb) B[i]=E(b[i]&1023,b[i]>>10);
	DFT(A,L); DFT(B,L);
	For(i,0,L-1){
		int ano=(L-i)&(L-1);
		E v1=(A[i]+A[ano].conj())*E(0.5,0);
		E v2=(A[i]-A[ano].conj())*E(0,-0.5);
		E v3=(B[i]+B[ano].conj())*E(0.5,0);
		E v4=(B[i]-B[ano].conj())*E(0,-0.5);
		C[i]=v1*v3+v2*v4*E(0,1);
		D[i]=v1*v4+v2*v3;
	}
	IDFT(C,L); IDFT(D,L);
	For(i,0,la+lb){
		int v1=(ll)(C[i].r/L+0.5)%mo;
		int v2=(ll)(C[i].i/L+0.5)%mo;
		int v3=(ll)(D[i].r/L+0.5)%mo;
		c[i]=((1ll<<20)*v2+(1ll<<10)*v3+v1)%mo;
	}
	//For(i,0,la+lb) c[i]=0;
	//For(i,0,la) For(j,0,lb) c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mo;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int get_g(int x){
	int di[105],X=x-1;
	*di=0;
	for (int i=2;i*i<=X;i++)
		if (X%i==0){
			di[++*di]=i;
			for (;X%i==0;X/=i);
		}
	if (X!=1)
		di[++*di]=X;
	for (int g=2;;g++){
		bool flag=0;
		For(i,1,*di)
			if (power(g,(mo-1)/di[i])==1)
				flag=1;
		if (!flag)
			return g;
	}
}
bool isprime(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}
int S(int x){
	return 1ll*x*(x+1)/2%(mo-1);
}
int WW[N],RWW[N];
char s1[N],s2[N];
int a[N],b[N],c[N];
int main(){
	FFTinit();
	scanf("%d%d",&n,&mo);
	scanf("%s%s",s1,s2);
	mo=max(n,mo)+5;
	for (;;mo++){
		if (!isprime(mo)) continue;
		int p=mo-1;
		WW[0]=1; WW[1]=get_g(mo);
		For(i,2,p) WW[i]=1ll*WW[i-1]*WW[1]%mo;
		For(i,0,p) RWW[i]=WW[p-i];
		For(i,0,p) c[p-i]=(s1[i]-s2[i]+10*mo)%mo;
		For(i,0,p) c[p-i]=1ll*c[p-i]*RWW[S(i)]%mo;
		For(i,0,2*p) a[i]=WW[S(i)];
		mul(c,a,b,p,2*p);
		For(i,0,p-1){
			int ans=1ll*b[p+i]*RWW[S(i)]%mo;
			if (ans==0&&WW[i]>1&&WW[i]<p){
				printf("%d %d\n",mo,WW[i]);
				exit(0);
			}
		}
	}
}