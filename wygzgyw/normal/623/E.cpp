#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=300010;
const int msk=65535;
const double PIE=acos(-1.0);
int N;
ll n,m,mod;
ll mi[maxn],ans;
ll f[maxn],g[maxn];
ll jc[maxn],iv[maxn],ivjc[maxn];
ll c(int x,int y) {
	if (y<0||x<y) return 0;
	return jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y/=2;
	}
	return res;
}
void update(ll &x,ll y) {
	x+=y; if (x>=mod) x-=mod;
}
struct node {
	double re,im;
	node() {}
	node (double a,double b) : re(a),im(b) {}
	void operator = (const double &t) { re=t; im=0; }
	node operator + (const node &t) const {
		return node(re+t.re,im+t.im);
	}
	node operator + (const double &t) const {
		return node(re+t,im);
	}
	node operator - (const node &t) const {
		return node(re-t.re,im-t.im);
	}
	node operator - (const double &t) const {
		return node(re-t,im);
	}
	node operator * (const node &t) const {
		return node(re*t.re-im*t.im,re*t.im+im*t.re);
	}
} A[maxn],B[maxn],C[maxn],D[maxn],w[2][maxn];
int rev[maxn];
void init(int nn) {
	N=1;
	while (N<=nn) N<<=1;
	for (int i=1;i<N;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
}
void fft(node *a,int flag) {
	for (int i=0;i<N;i++)
		if (rev[i]<i) swap(a[i],a[rev[i]]);
	for (int step=1,l=N/2;step<N;step<<=1,l>>=1) {
		for (int i=0;i<N;i+=step<<1) {
			for (int k=i,d=0;k<i+step;k++,d+=l) {
				node u=a[k],v=a[k+step]*w[flag][d];
				a[k]=u+v; a[k+step]=u-v;
			}
		}
	}
	if (flag)
		for (int i=0;i<N;i++)
			a[i].re/=(double)N;
}
void conv(ll f[],ll g[],ll h[],int len) {
	int t1,t2;
	for (int i=0;i<=n;i++) {
		t1=f[i]*ksm(2,(ll)i*len)%mod,t2=g[i]%mod;
		A[i]=t1>>16,B[i]=t1&msk;
		C[i]=t2>>16,D[i]=t2&msk;
	//	printf("%lld %lld\n",t1,t2);
	}
	//printf("\n");
	for (int i=n+1;i<N;i++) A[i]=0,B[i]=0,C[i]=0,D[i]=0;
	fft(A,0); fft(B,0); fft(C,0); fft(D,0);
	
	for (int i=0;i<N;i++) {
		node aa=A[i],bb=B[i],cc=C[i],dd=D[i];
		A[i]=aa*cc,B[i]=bb*cc,C[i]=aa*dd,D[i]=bb*dd;
	}
	fft(A,1); fft(B,1); fft(C,1); fft(D,1);
	for (int i=0;i<=n;i++) {
		ll aa=(ll)(A[i].re+0.5),bb=(ll)(B[i].re+0.5);
		ll cc=(ll)(C[i].re+0.5),dd=(ll)(D[i].re+0.5);
		aa=(aa%mod+mod)%mod,bb=(bb%mod+mod)%mod,cc=(cc%mod+mod)%mod,dd=(dd%mod+mod)%mod;
		h[i]=((aa<<16)%mod<<16)%mod+(bb<<16)%mod+(cc<<16)%mod+dd;
		h[i]%=mod;
	}
	//for (int i=0;i<=n;i++) printf("%lld ",h[i]); printf("\n\n");
}
int main() {
	//freopen("1.txt","r",stdin);
	read(m); read(n); mod=(1e9)+7;
	if (m>n) { printf("0\n"); return 0; }
	mi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	jc[0]=jc[1]=iv[0]=iv[1]=ivjc[0]=ivjc[1]=1;
	for (int i=2;i<=n;i++) {
		jc[i]=jc[i-1]*i%mod;
		iv[i]=(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=ivjc[i-1]*iv[i]%mod;
	}
	init(n*2);
	for (int i=0;i<N;i++) {
		long double theta=PIE*2*i/N;
		w[0][i]=node(cos(theta),sin(theta));
		w[1][i]=node(cos(-theta),sin(-theta));
	}
	for (int i=1;i<=n;i++) f[i]=ivjc[i];
	g[0]=1;
	for (int x=1;m;m/=2,x*=2) {
		if (m&1) conv(g,f,g,x);
		conv(f,f,f,x);
	}
//	for (int i=1;i<=n;i++) printf("%d %d ",g[i],g[i]%mod); printf("\n");
	for (int i=1;i<=n;i++) update(ans,g[i]*c(n,i)%mod*jc[i]%mod);
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/