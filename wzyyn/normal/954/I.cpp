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
const int FFTN=1<<17;
const int N=FFTN+5;
const int mo=998244353;
int W[N],w[N],R[N];
int a[7][N],b[7][N];
int flg[6][6][N];
int fa[6],n,m;
char s[N],t[N];
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
				p[i+j]=p[i+j]+y; 
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
				p[i+j]=p[i+j]+y; 
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void solve(){
	int L=FFTinit(n+1);
	For(i,0,5){
		For(j,1,n) a[i][j]=(s[j]=='a'+i);
		For(j,1,m) b[i][m-j]=(t[j]=='a'+i);
		DFT(a[i],L); DFT(b[i],L); 
	}
	For(i,0,5) For(j,0,5){
		For(k,0,L-1) flg[i][j][k]=1ll*a[i][k]*b[j][k]%mo;
		IDFT(flg[i][j],L);
	} 
}
int main(){
	FFTinit();
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	solve();
	For(i,m,n){
		For(j,0,5) fa[j]=j;
		int sum=0;
		For(j,0,5) For(k,0,5)
			if (flg[j][k][i]){
				//printf("E %d %d\n",j,k);
				int x=get(j),y=get(k);
				if (x!=y) ++sum,fa[x]=y;
			}
		printf("%d ",sum);
	}
}