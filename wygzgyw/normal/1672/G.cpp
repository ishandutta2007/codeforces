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
const int maxn=4010;
int n,m,val[maxn];
char s[maxn];
vector<int> g[maxn];
int mi[2010*2010],ans,cnt,c[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
bool vis[maxn];
int V,E,Val;
struct node { int n,m,val; };
vector<node> D;
void dfs(int u) {
	V++; vis[u]=1; Val^=val[u];
	for (int &v : g[u]) {
		E++;
		if (!vis[v]) dfs(v);
	}
}
int main() {
	read(n),read(m);
	mi[0]=1; for (int i=1;i<=n*m;i++) mi[i]=mi[i-1]*2%mod;
	bool flag=0;
	if (n%2==1&&m%2==0) flag=1;
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) {
			if (s[j]=='?') {
				if (!flag) g[i].push_back(j+n),g[j+n].push_back(i),c[i]++;
				else g[j].push_back(i+m),g[i+m].push_back(j),c[j]++;
				cnt++;
			}
			else if (s[j]=='1') {
				if (!flag) val[i]^=1,val[j+n]^=1;
				else val[i+m]^=1,val[j]^=1;
			}
		}
	}
	if (n%2==0&&m%2==0) { printf("%d\n",mi[cnt]); return 0; }
	if (flag) swap(n,m);
	if (n%2==0&&m%2==1) {
		for (int op=0;op<=1;op++) {
			int tmp=1;
			for (int i=1;i<=n;i++) {
				if (val[i]==op) { if (c[i]) tmp=(ll)tmp*mi[c[i]-1]%mod; }
				else if (!c[i]) { tmp=0; break; } else tmp=(ll)tmp*mi[c[i]-1]%mod;
			}
			update(ans,tmp);
		}
		printf("%d\n",ans); return 0;
	}
	for (int i=1;i<=n+m;i++) if (!vis[i]) {
		V=E=Val=0; dfs(i); E/=2; D.push_back((node){V,E,Val});
	}
	for (int op=0;op<=1;op++) {
		int tmp=1;
		for (node &A : D) {
			if ((A.n%2==0&&A.val)||(A.n%2==1&&A.val!=op)) { tmp=0; break; }
			else tmp=(ll)tmp*mi[A.m-A.n+1]%mod;
		}
		update(ans,tmp);
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