// wygzgyw
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
#define MP make_pair
typedef __int128 LL;
typedef unsigned long long ull;
typedef long long ll;
const ull mod=9000000000000000041ULL;
int n,X[60],Y[60];
ull ksm(ull x,ull y) {
	ull res=1;
	while (y) {
		if (y&1) res=(LL)res*x%mod;
		x=(LL)x*x%mod; y>>=1;
	} return res;
}
void update(ull &x,ull y) { x+=y; if (x>=mod) x-=mod; }
struct node {
	ull a[60];
	friend node operator * (node A,ull x) { for (int i=1;i<n;i++) A.a[i]=(LL)A.a[i]*x%mod; return A; }
	friend node operator * (ull x,node A) { for (int i=1;i<n;i++) A.a[i]=(LL)A.a[i]*x%mod; return A; }
	friend node operator + (node A,node B) { for (int i=1;i<n;i++) update(A.a[i],B.a[i]); return A; }
	friend node operator - (node A,node B) { for (int i=1;i<n;i++) update(A.a[i],mod-B.a[i]); return A; }
} Z[60],W[60];
vector<ull> z[60],w[60];
ull x[60];
LL zz[60],ww[60],coef[60][60];
LL coef_z[60][60];
void guass(vector<ull> *z,node *Z) {
	for (int i=1;i<n;i++) {
		if (!z[i][i]) {
			for (int j=i+1;j<n;j++) if (z[j][i]) { swap(Z[j],Z[i]); swap(z[j],z[i]); break; }
		}
		assert(z[i][i]);
		ull v=ksm(z[i][i],mod-2);
		for (int j=i+1;j<n;j++) {
			ull tmp=(LL)v*z[j][i]%mod;
			for (int k=i;k<n;k++) update(z[j][k],mod-(LL)tmp*z[i][k]%mod);
			Z[j]=Z[j]-(tmp*Z[i]);
		}
	}
	for (int i=n-1;i>=1;i--) {
		for (int j=i+1;j<n;j++) Z[i]=Z[i]-(z[i][j])*Z[j];
		Z[i]=Z[i]*ksm(z[i][i],mod-2);
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		z[i].resize(n+2);
		w[i].resize(n+2);
		z[i][i]=w[i][i]=mod-2;
		Z[i].a[i]=1,W[i].a[i]=mod-1;
		
		coef[i][i]=-2;
	}
	for (int i=1;i<n;i++) {
		read(X[i]),read(Y[i]);
		update(z[X[i]][i],1),update(w[X[i]][i],1);
		update(z[Y[i]][i],1),update(w[Y[i]][i],1);
		update(Z[Y[i]].a[i],mod-1);
		coef[X[i]][i]++,coef[Y[i]][i]++;
		coef_z[Y[i]][i]++;
	}
	guass(z,Z);
	guass(w,W);
	//printf("%llu %llu\n",Z[1].a[1],W[1].a[1]);
	
	int q; read(q);
	while (q--) {
		int xx; read(xx);
		char s[60]; scanf("%s",s);
		for (int i=1;i<n;i++) {
			ww[i]=zz[i]=0;
			if (xx==i) ww[i]--;
			if (i==1) ww[i]++;
			if (s[i-1]=='R') zz[i]=1;
			//write(ww[i]),putchar(' '),write(zz[i]); puts("");
		}
		for (int i=1;i<n;i++) {
			x[i]=0;
			for (int j=1;j<n;j++) {
				update(x[i],(LL)(ww[j]+mod)%mod*W[i].a[j]%mod);
				update(x[i],(LL)zz[j]*Z[i].a[j]%mod);
			}
			//printf("x=%d %llu\n",i,x[i]);
		}
		int flag=1;
		for (int i=1;i<n;i++) {
			LL sum=0;
			for (int j=1;j<n;j++) sum+=(LL)x[j]*coef[i][j]+(LL)coef_z[i][j]*zz[j];
			//writeln(sum-zz[i]+ww[i]);
			if (sum-zz[i]+ww[i]!=0) { flag=0; break; }
		}
		if (!flag) { puts("-1"); continue; }
		for (int i=1;i<n;i++) if (i!=xx&&(x[i]||x[i]+zz[i])) {
			int x=i,fd=0;
			for (int j=1;j<=n;j++) {
				if (x==xx) { fd=1; break; }
				if (s[x-1]=='R') x=Y[x]; else x=X[x];
			}
			if (!fd) { flag=0; break; }
		}
		if (!flag) { puts("-1"); continue; }
		LL ans=0;
		for (int i=1;i<n;i++) ans+=(LL)x[i]*2+zz[i];
		writeln(ans);
		
	}
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