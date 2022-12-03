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
const int maxn=(4e6)+10;
const int mod=(1e9)+7;
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn];
void init() {
	jc[0]=jc[1]=ivjc[0]=ivjc[1]=1;
	for(int i=2;i<maxn;++i) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=1;i--) ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
}
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
int n,k;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ans,mi[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	init();
	mi[0]=1; for (int i=1;i<=n+1;i++) mi[i]=(ll)mi[i-1]*3%mod;
	if (k==0) { printf("%d\n",mi[n]); return 0; }
	for (int i=0;i<k;i++) {
		int All=C(n-(k-1-i)-i,k-i);
		int A=C(n-(k-1-i)-i-1,k-i-1);
		int B=(All-A+mod)%mod;
		int tmp=(ll)C(k-1,i)*A%mod;
	//	printf("%d %d\n",A,B);
		if (tmp) {
			tmp=(ll)tmp*mi[n-k-(k-i)+1]%mod*mi[i]%mod;
			update(ans,tmp);
		}
		tmp=(ll)C(k-1,i)*B%mod;
		if (tmp) {
			tmp=(ll)tmp*mi[n-k-(k-i)]%mod*mi[i]%mod;
			update(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}