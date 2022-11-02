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
const int INF=1e9;
const int maxn=400*400+10;
const int maxm=maxn*20;
int n,a[210][210];
int num[210][210];
int idx,s,t,tot=1;
int head[maxn],nxt[maxm],to[maxm],w[maxm];
ll ans;
int now;
struct node { int x,y,z; }; vector<node> V;
bool cmp(node A,node B) { return A.z<B.z; }
bool vis[maxn];
void add(int x,int y,int z) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; w[tot]=z;
	swap(x,y);
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; w[tot]=0;
}
int dfs(int x,int f) {
	if (x==t||!f) return f;
	int used=0,tmp;
	vis[x]=1;
	for (int i=head[x];i;i=nxt[i]) {
		int y=to[i];
		if (!vis[y]&&w[i]&&(tmp=dfs(y,min(f,w[i])))) {
			w[i]-=tmp,w[i^1]+=tmp;
			f-=tmp,used+=tmp;
			if (!f) return used;
		}
	}
	return used;
}
int idfs(int x,int f,int sp) {
	if (x==s||!f) return f;
	int used=0,tmp;
	vis[x]=1;
	for (int i=head[x];i;i=nxt[i]) {
		int y=to[i];
		if (x==t&&y!=sp) continue;
		if (!vis[y]&&w[i]&&(tmp=idfs(y,min(f,w[i]),sp))) {
			w[i]-=tmp,w[i^1]+=tmp;
			f-=tmp,used+=tmp;
			if (!f) return used;
		}
	}
	return used;
}
void change(int x) {
	while (1) {
		memset(vis,0,sizeof(vis));
		int tmp=idfs(t,INF,x);
		if (tmp) now-=tmp; else break;
	}
	for (int i=head[x];i;i=nxt[i]) if (to[i]==t) w[i]=w[i^1]=0;
	add(s,x,INF);
	while (1) {
		memset(vis,0,sizeof(vis));
		int tmp=dfs(s,INF);
		if (tmp) now+=tmp; else break;
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) read(a[i][j]),num[i][j]=++idx;
	s=idx+1,t=idx+2;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (a[i][j]>0) V.push_back((node){i,j,a[i][j]});
	sort(V.begin(),V.end(),cmp);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		if (a[i][j]!=-1&&i<n&&a[i+1][j]!=-1) add(num[i][j],num[i+1][j],1),add(num[i+1][j],num[i][j],1);
		if (a[i][j]!=-1&&j<n&&a[i][j+1]!=-1) add(num[i][j],num[i][j+1],1),add(num[i][j+1],num[i][j],1);
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (a[i][j]>0) add(num[i][j],t,INF);
	int lst=0;
	for (node &A : V) {
	//	printf("%d %d\n",A.z,now);
		ans+=(ll)(A.z-lst)*now;
		change(num[A.x][A.y]);
		lst=A.z;
	}
	printf("%lld\n",ans);
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