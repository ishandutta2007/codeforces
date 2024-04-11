#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
typedef long long ll;
typedef vector<int> poly;
const int mod=998244353;
const int maxn=(2e5)+10;
int n,V,ans,k;
int ksm(int x,int y) {
    int res=1;
    while (y) {
        if (y&1) res=(ll)res*x%mod;
        x=(ll)x*x%mod; y>>=1;
    }
    return res;
}
int N,rev[maxn*4],w[maxn*4],lg;
int jc[maxn],ivjc[maxn],iv[maxn];
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void init(int n) {
    N=1; lg=0;
    while (N<=n) N*=2,lg++;
    for (int i=0;i<N;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    int V=ksm(3,(mod>>lg));
    w[N>>1]=1;
    for (int i=(N>>1)+1;i<N;i++) w[i]=(ll)w[i-1]*V%mod;
    for (int i=(N>>1)-1;i>=1;i--) w[i]=w[i<<1];
}
int BB[maxn*4];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void ntt(int *a,int len,int flag) {
    if (flag==-1) reverse(a+1,a+len);
    int tmp;
    for (int i=0;i<len;i++) BB[i]=a[rev[i]];
    for (int i=1;i<len;i<<=1)
    for (int j=0;j<len;j+=(i<<1))
    for (int k=0;k<i;k++) {
        tmp=(ll)BB[i+j+k]*w[i+k]%mod;
        BB[i+j+k]=(BB[j+k]+mod-tmp)%mod;
        update(BB[j+k],tmp);
    }
    for (int i=0;i<len;i++) a[i]=BB[i];
    if (flag==-1) {
        int V=mod-(mod-1)/len;
        for (int i=0;i<N;i++) a[i]=(ll)a[i]*V%mod;
    }
}
void print(poly A) {
    for (int i=0;i<A.size();i++) printf("%d ",A[i]); printf("\n");
}
poly operator * (poly A,poly B) {
    int n=(int)A.size(),m=(int)B.size();
    if (n+m<=150) {
        poly res(n+m-1,0);
        for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) update(res[i+j],(ll)A[i]*B[j]%mod);
        return res;
    }
    init(n+m+2);
    A.resize(N,0),B.resize(N,0);
    ntt(A.data(),N,1),ntt(B.data(),N,1);
    for (int i=0;i<N;i++) A[i]=(ll)A[i]*B[i]%mod;
    ntt(A.data(),N,-1);
    A.resize(n+m-1);
    return A;
}
poly Stirling(int n) {
	poly A,B;
	A.resize(n+5,0),B.resize(n+5,0);
	for (int i=0;i<=n;i++) {
		A[i]=(ll)ivjc[i]*ksm(i,n)%mod;
		B[i]=ivjc[i]; if (i&1) B[i]=mod-B[i];
	}
	poly res=A*B;
	res.resize(n+5);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	ivjc[0]=iv[0]=jc[0]=ivjc[1]=jc[1]=iv[1]=1;
	for (int i=2;i<maxn;i++) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=2;i--) {
		ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
		iv[i]=(ll)ivjc[i]*jc[i-1]%mod;
	}
	poly tmp=Stirling(k);
	int mi=ksm(n+1,n),t=ksm(n+1,mod-2);
	int fz=1;
	for (int i=1;i<=k;i++) {
		mi=(ll)mi*t%mod; fz=(ll)fz*(n-i+1)%mod;
		update(ans,(ll)tmp[i]*jc[i]%mod*fz%mod*ivjc[i]%mod*mi%mod);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/