#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const double pi=acos(-1);
const int N=65555;
const int FFTN=65536;
const int M=105;
const int K=40005;
struct E{
	double x,y;
	E(){}
	E(double _x,double _y){
		x=_x; y=_y;
	}
	E operator +(const E &a)const{
		return E(x+a.x,y+a.y);
	}
	E operator -(const E &a)const{
		return E(x-a.x,y-a.y);
	}
	E operator *(const E &a)const{
		return E(x*a.x-y*a.y,x*a.y+y*a.x);
	}
};
E W[N],w[N];
E A[N],B[N];
int R[N];
int n,m,T,wzp;
int x[M],y[M],v[M];
int d[M][M],tr[M][K];
double f[M][K],val[M][K];
void FFTinit(){
	W[0]=E(1,0);
	W[1]=E(cos(2*pi/FFTN),sin(2*pi/FFTN));
	For(i,2,N-1) W[i]=W[i-1]*W[1];
	//printf("%.10lf %.10lf\n",W[FFTN].x,W[FFTN].y);
}
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
void divide(int l,int r){
	if (r<T) return;
	if (l==r){
		For(i,1,n) f[i][l]=(i==n?0:1e100);
		For(i,1,m) f[x[i]][l]=min(f[x[i]][l],val[i][l]+v[i]);
		//For(i,1,n) printf("%d %d %.10lf\n",i,l,f[i][l]);
		//For(i,1,m) printf("%d %d %.10lf\n",i,l,val[i][l]);
		return;
	}
	int mid=(l+r)/2;
	divide(l,mid);
	int L=FFTinit(r-l+1);
	//printf("%d %d %d\n",l,r,L);
	For(i,1,m){
		For(j,0,L-1) A[j]=B[j]=E(0,0);
		For(j,l,mid) A[j-l]=E(f[y[i]][j],0);
		For(j,1,min(T,r-l)) B[j]=E(tr[i][j]/100000.0,0);
		DFT(A,L); DFT(B,L);
		For(j,0,L-1) A[j]=A[j]*B[j];
		IDFT(A,L);
		For(j,mid+1,r) val[i][j]+=A[j-l].x/L;
	}
	divide(mid+1,r);
}
int main(){
	FFTinit();
	scanf("%d%d%d%d",&n,&m,&T,&wzp);
	For(i,1,n) For(j,1,n) d[i][j]=(i==j?0:1e9);
	For(i,1,m){
		scanf("%d%d%d",&x[i],&y[i],&v[i]);
		d[x[i]][y[i]]=min(d[x[i]][y[i]],v[i]);
		For(j,1,T) scanf("%d",&tr[i][j]);
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	For(i,1,n) For(j,0,T-1)
		f[i][j]=wzp+(d[i][n]==1e9?1e100:d[i][n]);
	divide(0,2*T);
	printf("%.10lf\n",f[1][2*T]);
}