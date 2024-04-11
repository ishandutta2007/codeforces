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
const int maxn=2010;
int n;
char s[maxn][maxn];
namespace chk {
vector<int> g[maxn];
int dfn[maxn],low[maxn],id;
int st[maxn],top;
int bel[maxn],col;
void tarjan(int x) {
	dfn[x]=low[x]=++id;
	st[++top]=x;
	for (int &v : g[x]) {
		if (!dfn[v]) {
			tarjan(v);
			low[x]=min(low[x],low[v]);
		} else if (!bel[v]) low[x]=min(low[x],dfn[v]);
	}
	if (dfn[x]==low[x]) {
		bel[x]=++col;
		while(st[top]!=x) {
			bel[st[top]]=col;
			--top;
		}
		--top;
	}
}
void clear() { for (int i=1;i<=n;i++) g[i].clear(); }
void add(int x,int y) {
	g[x].push_back(y);
}
bool solve() {
	for (int i=1;i<=n;i++) dfn[i]=bel[i]=0;
	top=id=col=0;
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	return col==1;
}
};
namespace BF {
void solve() {
	int mn=1e9,cnt=0;
	for (int t=0;t<(1<<n);t++) {
		chk::clear();
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) if (i!=j) {
				int x=(s[i][j]-'0');
				if (t>>(i-1)&1) x^=1;
				if (t>>(j-1)&1) x^=1;
				if (x) chk::add(i,j);
			}
		}
		if (chk::solve()) {
			int tmp=__builtin_popcount(t);
			if (tmp<mn) mn=tmp,cnt=1; else if (tmp==mn) cnt++;
		}
	}
	if (mn==1e9) { puts("-1"); exit(0); }
	for (int i=1;i<=mn;i++) cnt=(ll)cnt*i%mod;
	printf("%d %d\n",mn,cnt); exit(0);
}
};
int d[maxn],e[maxn];
int main() {
	read(n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if (n<=15) BF::solve();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) if (s[i][j]=='1') chk::add(i,j),d[i]++;
	}
	if (chk::solve()) { puts("0 1"); return 0; }
	int ans=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) e[j]=d[j];
		for (int j=1;j<=n;j++) {
			if (s[i][j]=='1') e[i]--,e[j]++;
			else e[i]++,e[j]--;
		}
		sort(e+1,e+n+1);
		int cnt=0,flag=0;
		for (int j=1;j<n;j++) {
			cnt+=e[j];
			flag|=(cnt==j*(j-1)/2);
		}
		if (!flag) ans++;
	}
	printf("1 %d\n",ans);
	return 0;
}