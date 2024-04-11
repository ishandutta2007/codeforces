#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxm=(2e5)+10;
const int mod=998244353;
const int maxn=30010;
int n,a,b;
int jc[maxm],ivjc[maxm],iv[maxm];
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int N,rev[maxn],ycl[maxn],ycr[maxn],IV;
void init(int n) {
    N=1; int lg=0;
    while (N<n) N*=2,lg++;
    for (int i=0;i<N;i++)
    	rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    IV=ksm(N,mod-2);
    for (int step=1;step<N;step<<=1) {
        ycl[step]=ksm(3,(mod-1)/(step<<1));
        ycr[step]=ksm(ycl[step],mod-2);
    }
}
void fft(int *a,int flag) {
    for (int i=0;i<N;i++)
    	if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int step=1;step<N;step<<=1) {
        int wn=ycl[step];
        if (flag==-1) wn=ycr[step];
        for (int i=0;i<N;i+=(step<<1)) {
            int w=1;
            for (int k=i;k<i+step;k++) {
                int u=a[k],v=(ll)a[k+step]*w%mod;
                a[k]=(u+v)%mod; a[k+step]=(u-v+mod)%mod;
                w=(ll)w*wn%mod;
            }
        }
    }
    if (flag==-1) {
        for (int i=0;i<N;i++)
            a[i]=(ll)a[i]*IV%mod;
    }
}
int f[maxn],g[maxn],ans;
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	iv[0]=jc[0]=ivjc[0]=iv[1]=jc[1]=ivjc[1]=1;
	for (int i=2;i<maxm;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	int tot=0,now;
	f[0]=1;
	
	for (int i=1;i<=n;i++) {
		read(a),read(b);
		now=tot+a-b;
		for (int j=-tot;j<=now;j++) {
			g[j+tot]=C(a+b,b+j);
		}
		init(tot+now+tot+10);
		for (int j=now+tot+1;j<N;j++) g[j]=0;
		fft(f,1),fft(g,1);
		for (int j=0;j<N;j++) f[j]=(ll)f[j]*g[j]%mod;
		fft(f,-1);
		for (int j=0;j<=now;j++) f[j]=f[j+tot];
		tot=now;
		for (int j=now+1;j<N;j++) f[j]=0;
		
		//for (int j=0;j<=tot;j++) printf("%d ",f[j]); printf("\n");
		
	}
	for (int i=0;i<=tot;i++) update(ans,f[i]);
	printf("%d\n",ans);
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