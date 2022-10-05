#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int pr=3;
const int ipr=332748118;
const int MAXP=1<<18;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,a,b,fac[MAXP+5],ifac[MAXP+5];
void init_fac(int n){
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n]=qpow(fac[n],MOD-2);for(int i=n-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
int A[MAXP+5],B[MAXP+5],C[MAXP+5],D[MAXP+5],E[MAXP+5];
int F[MAXP+5],G[MAXP+5],H[MAXP+5],I[MAXP+5];
int LEN=1,prs[MAXP+5][2],rev[MAXP+5],inv[MAXP+5];
void NTT(int *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=prs[i][type<0];
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i]=1ll*a[i]*inv[len]%MOD;
}
void polymul(int *a,int *b,int *c,int len){
	for(int i=0;i<len;i++) A[i]=a[i],B[i]=b[i];
	NTT(A,len,1);NTT(B,len,1);
	for(int i=0;i<len;i++) c[i]=1ll*A[i]*B[i]%MOD;
	NTT(c,len,-1);
}
void getinv(int *a,int *b,int len){
	for(int i=0;i<len;i++) b[i]=0;
	b[0]=qpow(a[0],MOD-2);
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<(i<<1);j++) C[j]=D[j]=0;
		for(int j=0;j<i;j++) C[j]=a[j];
		for(int j=0;j<(i>>1);j++) D[j]=b[j];
		polymul(D,D,D,i);polymul(C,D,C,i<<1);
		for(int j=0;j<i;j++) b[j]=(2*b[j]%MOD-C[j]+MOD)%MOD;
	}
}
void direv(int *a,int *b,int len){
	for(int i=1;i<len;i++) b[i-1]=1ll*a[i]*i%MOD;b[len-1]=0;
}
void inter(int *a,int *b,int len){
	for(int i=1;i<len;i++) b[i]=1ll*a[i-1]*inv[i]%MOD;b[0]=0;
}
void getln(int *a,int *b,int len){
	for(int i=0;i<(len<<1);i++) E[i]=F[i]=G[i]=0;
	direv(a,E,len);getinv(a,F,len);polymul(E,F,E,len<<1);
	for(int i=0;i<len;i++) G[i]=E[i];inter(G,b,len);
}
void getexp(int *a,int *b,int len){
	for(int i=0;i<len;i++) b[i]=0;
	b[0]=1;
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<(i<<1);j++) H[j]=I[j]=0;
		getln(b,H,i);
		for(int j=0;j<i;j++) H[j]=(-H[j]+a[j]+MOD)%MOD;
		(H[0]+=1)%=MOD;
		for(int j=0;j<(i>>1);j++) I[j]=b[j];
		polymul(H,I,H,(i<<1));
		for(int j=0;j<i;j++) b[j]=H[j];
	}
}
int x[2][MAXP+5],y[MAXP+5],z[MAXP+5];
void solve(int *a,int k){
	for(int i=0;i<LEN;i++) y[i]=inv[i+1];
	getln(y,z,LEN);for(int i=0;i<LEN;i++) z[i]=1ll*z[i]*k%MOD;getexp(z,y,LEN);
	for(int i=0;i<=n;i++) a[i]=1ll*y[i-k]*fac[i]%MOD*ifac[k]%MOD;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(!a||!b) return printf("0\n"),0;
	a--;b--;while(LEN<=n) LEN<<=1;init_fac(n);
	for(int i=1;i<=MAXP;i++) inv[i]=qpow(i,MOD-2);
	for(int i=1;i<=MAXP;i<<=1){
		prs[i][0]=qpow(pr,(MOD-1)/i);
		prs[i][1]=qpow(ipr,(MOD-1)/i);
	} int ans=0;solve(x[0],a);solve(x[1],b);
//	for(int i=0;i<=n;i++) printf("%d%c",x[0][i],(i==n)?'\n':' ');
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*binom(n-1,i-1)*x[0][i-1]%MOD*x[1][n-i]%MOD)%MOD;
	} printf("%d\n",ans);
	return 0;
}