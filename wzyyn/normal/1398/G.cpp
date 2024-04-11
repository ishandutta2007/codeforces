#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=998244353;
const int FFTN=(1<<19);
const int N=FFTN+5;
int n,x,y,L;
int a[N],b[N],R[N];
int w[N],W[N],f[N*2];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) W[i]=1ll*W[i-1]*W[1]%mo;
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
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
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
		if (d==1<<10)
			For(i,0,n-1) p[i]%=mo;
	}
	int v=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*v%mo;
}
int main(){
	FFTinit();
	scanf("%d%d%d",&n,&x,&y);
	L=524288;
	For(i,1,n+1){
		int p;
		scanf("%d",&p);
		a[p]=b[(1<<18)-p]=1;
	}
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	DFT(a,L); DFT(b,L);
	For(i,0,L-1) a[i]=1ll*a[i]*b[i]%mo;
	IDFT(a,L);
	memset(f,-1,sizeof(f));
	For(i,1,x) if (a[(1<<18)+i]) f[2*i+2*y]=2*i+2*y;//cout<<i<<endl;
	For(i,1,1000000) For(j,1,1000000/i)
		f[i*j]=max(f[i*j],f[i]);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		printf("%d ",f[x]);
	} 
}