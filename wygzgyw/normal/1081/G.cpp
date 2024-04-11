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
int mod,n,k;
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
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int cnt[maxn];
void dfs(int l,int r,int k) {
	if (l>r) return;
	if (k<=1||l==r) { cnt[r-l+1]++; return; }
	int mid=(l+r)>>1;
	dfs(l,mid,k-1),dfs(mid+1,r,k-1);
}
int ans,iv[maxn],pre[maxn];
int S(int l,int r) {
	return (pre[r]-(l==0?0:pre[l-1])+mod)%mod;
}
int solve(int a,int b) {
	int tmp=0;
	for (int i=1;i<=a;i++) {
		int now=(ll)iv[2]*iv[i+1]%mod*(i-1)%mod;
		update(now,iv[i+1]);
		now=(ll)now*(b-1-(ll)(i+1)*S(i+2,i+b)%mod+mod)%mod;
		update(tmp,now);
	}
	return tmp;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(k),read(mod);
	init();
	dfs(1,n,k);
	int iv2=(mod+1)/2;
	if (cnt[n]==1) {
		ans=(ll)n*(n-1)%mod*iv2%mod*iv2%mod;
		printf("%d\n",ans);
		return 0;
	}
	iv[0]=1;
	for (int i=1;i<=n;i++) iv[i]=ksm(i,mod-2);
	pre[0]=1; for (int i=1;i<=n;i++) pre[i]=(pre[i-1]+iv[i])%mod;
	for (int len=1;len<=n;len++) if (cnt[len]) {
		int t1=(ll)len*(len-1)%mod*iv2%mod*iv2%mod;
		update(ans,(ll)t1*cnt[len]%mod);
		//printf("%d %d\n",len,cnt[len]);
	}
	for (int a=1;a<=n;a++) if (cnt[a]) for (int b=a;b<=n;b++) if (cnt[b]) {
		if (a==b&&cnt[a]==1) continue;
		int tmp=(solve(a,b)+solve(b,a))%mod;
		if (a==b) tmp=(ll)tmp*cnt[a]%mod*(cnt[a]-1)%mod*iv2%mod;
		else tmp=(ll)tmp*cnt[a]%mod*cnt[b]%mod;
		update(ans,tmp);	
	}
	printf("%d\n",ans);
	return 0;
}