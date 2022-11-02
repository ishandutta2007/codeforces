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
const int mod=998244353;
const int maxn=(1e5)+10;
int n,jc[maxn],ivjc[maxn];
int T; char s[maxn];
bool flag[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	jc[0]=ivjc[0]=jc[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
	}
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=2;i--)
		ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
	read(T);
	while (T--) {
		read(n); scanf("%s",s+1);
		int a=0,b=0;
		for (int i=1;i<=n;i++) flag[i]=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='1') {
				if (s[i-1]=='1'&&!flag[i-1]&&i>1) flag[i]=flag[i-1]=1,a++;
			} else b++;
		}
		printf("%d\n",C(a+b,a));
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