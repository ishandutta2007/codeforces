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
const int mo=1000000007;
const int N=255;
int n,B;
int a[N],b[N],c[N],d[N];
int f[N],g[N],h[N*2];
ll T;
void mul(int *f,int *g){
	memset(h,0,sizeof(h));
	For(i,0,N-1) For(j,0,N-1) h[i+j]=(h[i+j]+1ll*f[i]*g[j])%mo;
	Rep(i,2*N-1,N) For(j,1,B) h[i-b[j]]=(h[i-b[j]]+h[i]) %mo;
	For(i,0,N-1) f[i]=h[i];
}
void power(int *c,ll T){
	memset(d,0,sizeof(d));
	d[0]=1;
	for (;T;T/=2,mul(c,c))
		if (T&1) mul(d,c);
	memcpy(c,d,sizeof(d));
}
int main(){
	scanf("%d%d%lld",&n,&B,&T);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,B) scanf("%d",&b[i]);
	f[0]=1;
	For(i,1,N-1) For(j,1,B)
		if (i>=b[j]) f[i]=(f[i]+f[i-b[j]])%mo;
	For(i,1,n){
		memset(c,0,sizeof(c));
		c[1]=1; power(c,a[i]);
		For(j,0,N-1) g[j]=(g[j]+c[j])%mo;
	} 
	power(g,T);
	int ans=0;
	For(i,0,N-1) ans=(ans+1ll*f[i]*g[i])%mo;
	printf("%d\n",ans);
}
/*

*/