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
const int maxn=(2e5)+10;
const int mod=998244353;
int T,n;
ll a[maxn],pre[maxn],suf[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
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
int nxt[maxn],dy[maxn];
int mi[maxn],rgt[maxn],lft[maxn];
int f(int i,int j) {
	if (pre[j]==pre[i-1]) return mi[j-i];
	assert(i<=j);
	if (a[i]==0&&a[j]==0) {
		int x=rgt[i],y=lft[j],res=0;
		for (int k=0;k<=x&&k<=y;k++) update(res,(ll)C(x,k)*C(y,k)%mod);
		res=(ll)res*f(i+x,j-y)%mod;
		return res;
	}
	int l=nxt[i+rgt[i]];
	int r=dy[l];
	if (l>=r) return 1;
	if (l==j) return 1;
	if (l+1==r) return 2;
//	printf("%d %d %d %d\n",i,j,l,r);
	if (pre[r-1]==pre[l]) return mi[r-l];
	int x=rgt[l+1],y=lft[r-1],res=1;
	for (int k=0;k<=x&&k<=y;k++) update(res,(ll)C(x+1,k+1)*C(y+1,k+1)%mod);
	res=(ll)res*f(l+x+1,r-y-1)%mod;
	return res;
}
pair<ll,int> vec[maxn];
int main() {
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=mi[i-1]*2%mod; init();
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),pre[i]=pre[i-1]+a[i];
		suf[n+1]=rgt[n+1]=0;
		for (int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i],vec[n-i+1]=MP(suf[i],-i);
		for (int i=n;i>=1;i--) if (a[i]==0) rgt[i]=rgt[i+1]+1; else rgt[i]=0;
		for (int i=1;i<=n;i++) if (a[i]==0) lft[i]=lft[i-1]+1; else lft[i]=0;
		nxt[n+1]=0;
		for (int i=n;i>=1;i--) {
			int pos=lower_bound(vec+1,vec+n+1,MP(pre[i],-n))-vec;
			if (vec[pos].first==pre[i]) {
				nxt[i]=i; dy[i]=-vec[pos].second;
			} else nxt[i]=nxt[i+1];
		}
		printf("%d\n",f(1,n));
	}
	return 0;
}