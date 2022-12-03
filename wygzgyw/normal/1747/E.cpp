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
const int mod=(1e9)+7;
const int maxn=(2e7)+10;
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
int n,m,rem[maxn];
int ans,T;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	init();
	read(T);
	while (T--) {
		ans=0;
		read(n),read(m);
		for (int len=0;len<=n+m;len++) {
			int coef=(ll)C(n+len-1,n)*C(m+len-1,m)%mod*(len+1)%mod;
			if (!len) {
				rem[len]=0;
				for (int i=0;i+len+1<=n+m+1;i++) {
					int tmp=C(i+len+1,i);
					if (i&1) tmp=mod-tmp;
					update(rem[len],tmp);
				}
			} else {
				rem[len]=rem[len-1];
				int bd=n+m-len;
				if (bd&1) update(rem[len],mod-C(bd+len+1,bd+1)),update(rem[len],mod-C(bd+len+1,bd));
				else update(rem[len],C(bd+len+1,bd+1)),update(rem[len],C(bd+len+1,bd));
				rem[len]=(ll)rem[len]*((mod+1)/2)%mod;
			}
			update(ans,(ll)rem[len]*coef%mod);
		}
		printf("%d\n",ans);
	}
	return 0;
}