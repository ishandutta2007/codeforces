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
typedef long long ll;
const int mod=31607;
int n,a[25][25],iv[mod],bit[1<<21],b[25][25],lg[1<<21];
int ksm(int x,int y) {
	if (y==mod-2) return iv[x];
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod; x=(ll)x*x%mod; y>>=1;
	} return res;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int lie[25],hang[25],ans,rem[1<<21][25];
int solve() {
	for (int i=1;i<=n;i++) lie[i]=hang[i]=1;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		lie[j]=(ll)lie[j]*b[i][j]%mod;
		hang[i]=(ll)hang[i]*b[i][j]%mod;
	}
	int res=1;
	for (int t=0;t<(1<<n);t++) {
		if (!t) {
			for (int i=1;i<=n;i++) rem[t][i]=lie[i];
		} else {
			int lst=lg[t&(-t)];
			for (int i=1;i<=n;i++) {
				rem[t][i]=(ll)rem[t-(t&(-t))][i]*iv[b[lst+1][i]]%mod;
			}
		}
		int tmp=1;
		for (int i=1;i<=n;i++) {
			tmp=(ll)tmp*(1-rem[t][i]+mod)%mod;
			if (t&(1<<(i-1))) tmp=(ll)tmp*hang[i]%mod;
		}
		if (bit[t]&1) update(res,mod-tmp); else update(res,tmp);
	}
	update(res,mod-1);
	return res;
}
int main() {
	//printf(" %d\n",sizeof(rem)/1024/1024);
	//freopen("1.txt","r",stdin);
	read(n);
	iv[0]=iv[1]=1;
	for (int i=2;i<mod;i++) iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) read(a[i][j]),a[i][j]=(ll)a[i][j]*iv[10000]%mod;
	for (int t=1;t<(1<<21);t++) bit[t]=bit[t-(t&(-t))]+1;
	for (int t=0;t<n;t++) lg[1<<t]=t;
	for (int t=0;t<4;t++) {
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) b[i][j]=a[i][j];
		int tmp=1;
		if (t&1) {
			for (int i=1;i<=n;i++) tmp=(ll)tmp*b[i][i]%mod,b[i][i]=1;
		}
		if (t&2) {
			for (int i=1;i<=n;i++) tmp=(ll)tmp*b[i][n-i+1]%mod,b[i][n-i+1]=1;
		}
		tmp=(ll)tmp*solve()%mod;
		if (bit[t]&1) update(ans,mod-tmp);
		else update(ans,tmp);
	}
	printf("%d\n",(mod-ans+1)%mod);
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