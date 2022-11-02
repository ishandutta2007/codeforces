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
const int maxn=(4e5)+10;
int T,n,m,nxt[maxn],to[maxn],head[maxn],tot,w[maxn];
void add(int x,int y,int z) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; w[tot]=z;
}
int dep[maxn];
struct node {
	int x,y,z;
}; vector<node> vec;
char s[maxn]; int fa[maxn];
void dfs(int x,int id,int d) {
	dep[x]=d;
	for (int i=head[x];i;i=nxt[i]) if ((i^id)!=1) {
		int y=to[i];
		if (!dep[y]) dfs(y,i,d+1),fa[y]=w[i];
		else if (dep[y]<dep[x]) {
			vec.push_back((node){x,y,w[i]});
		}
	}
}
bool cmp(int x,int y) { return dep[x]<dep[y]; }
bool chk(int x,int y,int a,int b) { return (x==a&&y==b)||(x==b&&y==a); }
int main() {
	read(T); while (T--) {
		read(n),read(m);
		int x,y; for (int i=1;i<=n;i++) head[i]=0; tot=1;
		for (int i=1;i<=m;i++) {
			read(x),read(y); s[i]='0';
			add(x,y,i),add(y,x,i);
		}
		for (int i=1;i<=n;i++) dep[i]=0; vec.clear();
		dfs(1,0,1);
		vector<int> V;
		for (node &A : vec) V.push_back(A.x),V.push_back(A.y);
		sort(V.begin(),V.end()),V.resize(unique(V.begin(),V.end())-V.begin());
		if ((int)vec.size()==3&&(int)V.size()==3) {
			sort(V.begin(),V.end(),cmp);
			for (node &A : vec) s[A.z]='1';
			s[fa[V[1]]]='1';
			for (node &A : vec) if (chk(A.x,A.y,V[0],V[1])) s[A.z]='0';
		} else {
			for (node &A : vec) s[A.z]='1';
		}
		for (int i=1;i<=m;i++) printf("%c",s[i]); puts("");
	}
	return 0;
}