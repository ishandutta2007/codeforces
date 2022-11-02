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
const int maxn=(2e5)+10;
int n,sz[maxn],k;
int ans,fa[maxn];
int jc[maxn],iv[maxn],ivjc[maxn];
void init(){jc[0]=jc[1]=iv[0]=iv[1]=ivjc[0]=ivjc[1]=1;for(int i=2;i<maxn;++i)jc[i]=(ll)jc[i-1]*i%mod,iv[i]=(ll)iv[mod%i]*(mod-mod/i)%mod,ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;}
inline int C(int n,int m){return n<m||m<0?0:(ll)jc[n]*ivjc[m]%mod*ivjc[n-m]%mod;}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
vector<int> g[maxn];
void dfs(int u,int p) {
	sz[u]=1; fa[u]=p;
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u),sz[u]+=sz[v];
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	init();
	int tmp;
	for (int x=1;x<=n;x++) {
		int s1=0,s2=0;
		for (int &j : g[x]) if (fa[j]==x) update(s1,(ll)(mod-(n-sz[j]))*sz[j]%mod),update(s2,sz[j]);
		for (int &i : g[x]) if (fa[i]==x) {
			tmp=(ll)C(sz[i],k)*sz[i]%mod*s2%mod;
			update(ans,tmp);
			tmp=(ll)C(sz[i],k)*s1%mod;
			update(ans,tmp);
			tmp=(ll)C(sz[i],k)*(sz[i]-(n-sz[i])+mod)%mod*sz[i]%mod;
			update(ans,mod-tmp);
		}
		/*
		for (int &i : g[x]) if (fa[i]==x)
		for (int &j : g[x]) if (i!=j&&fa[j]==x) {
			tmp=(ll)C(sz[i],k)*(sz[i]-(n-sz[j])+mod)%mod*sz[j]%mod;
			update(ans,tmp);
		}*/
		for (int &i : g[x]) if (fa[i]==x) {
			tmp=(ll)C(sz[i],k)*(sz[i]-sz[x]+mod)%mod*(n-sz[x])%mod;
			update(ans,tmp);
			tmp=(ll)C(sz[i],k)*(sz[i]-n+mod)%mod;
			update(ans,tmp);
		}
		if (fa[x]) {
			int i=fa[x];
			for (int &j : g[x]) if (fa[j]==x) {
				tmp=(ll)C(n-sz[x],k)*(n-sz[x]-(n-sz[j])+mod)%mod*sz[j]%mod;
				update(ans,tmp);
			}
			tmp=(ll)C(n-sz[x],k)*(n-sz[x]-n+mod)%mod;
			update(ans,tmp);
		}
	}
	for (int i=1;i<=n;i++) update(ans,(ll)n*C(n,k)%mod);
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