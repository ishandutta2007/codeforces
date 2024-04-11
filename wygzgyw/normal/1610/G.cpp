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
typedef unsigned long long ull;
const int maxn=(3e5)+10;
const ull M=23333;
char s[maxn]; int n,nxt[maxn],sum[maxn],st[maxn][20],lg[maxn];
int query(int l,int r) {
	int j=lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
map<int,int> lst;
int fa[maxn][20],to[maxn],W[maxn],dep[maxn];
ull g[maxn][20],mi[1<<20];
void link(int x,int y,int z) {
	W[x]=g[x][0]=z,fa[x][0]=y,dep[x]=dep[y]+1;
	for (int i=1;i<=19;i++) {
		fa[x][i]=fa[fa[x][i-1]][i-1];
		g[x][i]=g[x][i-1]+g[fa[x][i-1]][i-1]*mi[1<<(i-1)];
	}
}
int chkmin(int x,int y) {
	int a=x,b=y;
	for (int i=19;i>=0;i--) {
		if (fa[a][i]&&fa[b][i]) {
			if (g[a][i]==g[b][i]) a=fa[a][i],b=fa[b][i];
		}
	}
	if (!W[a]) return x;
	if (!W[b]) return y;
	if (W[a]<W[b]) return x;
	return y;
}
int main() {
	mi[0]=1; for (int i=1;i<(1<<20);i++) mi[i]=mi[i-1]*M;
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) nxt[i]=-1;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='('?1:-1),st[i][0]=sum[i];
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=n;i>=1;i--) {
		if (lst.count(sum[i-1])) {
			int pos=lst[sum[i-1]];
			if (query(i,pos)-sum[i-1]>=0) nxt[i]=pos+1;
		}
		lst[sum[i]]=i;
	}
	//for (int i=1;i<=n;i++) printf("%d ",nxt[i]); puts("");
	int x,y; to[n+1]=n+1;
	for (int i=n;i>=1;i--) {
		x=nxt[i]; to[i]=i;
		if (x==-1) {
			link(i,to[i+1],s[i]=='('?1:2);
		} else {
			x=to[x];
			y=n+2; link(y,to[i+1],s[i]=='('?1:2);
			if (chkmin(x,y)==n+2) link(i,to[i+1],s[i]=='('?1:2);
			else to[i]=to[nxt[i]];
		}
	//	printf("fa[%d]=%d %d\n",i,to[i],fa[i][0]);
	}
	x=to[1];
	while (x<=n) {
		if (W[x]==1) putchar('('); else putchar(')');
		x=fa[x][0];
	}
	puts("");
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