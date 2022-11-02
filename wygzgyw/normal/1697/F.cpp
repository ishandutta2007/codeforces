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
int T,n,m,k,tot;
vector<int> g[maxn];
int N(int x,int y) { assert(y<=k&&y>=1&&x>=1&&x<=n); return (x-1)*k+y; }
void add(int x,int k1,int y,int k2) {
	//printf("%d %d %d %d\n",x,k1,y,k2);
	g[x*2-k1].push_back(y*2-(k2^1));
	g[y*2-k2].push_back(x*2-(k1^1));
}
void add(int x,int k) {
	g[x*2-k].push_back(x*2-(k^1));
}
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
int q[maxn],hd,tl,in[maxn];
vector<int> h[maxn]; int DFN[maxn];
void ADD(int x,int y) {
	in[y]++; h[x].push_back(y);
}
void ban(int i,int x) {
	if (x==k) add(N(i,x),1);
	else add(N(i,x),1,N(i,x+1),0);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	int op,i,j,x;
	for (int I=1;I<=T;I++) {
		read(n),read(m),read(k);
		tot=n*k*2;
		for (int i=1;i<=tot;i++) g[i].clear();
		for (int i=1;i<=n;i++) {
			for (int j=1;j<k;j++) add(N(i,j),0,N(i,j+1),1);
			add(N(i,1),0);
		}
		for (int i=1;i<n;i++) for (int j=1;j<=k;j++) add(N(i,j),1,N(i+1,j),0);
		while (m--) {
			read(op),read(i);
			if (op==1) {
				read(x);
				ban(i,x);
			} else if (op==2) {
				read(j),read(x);
				for (int a=1;a<=k;a++) {
					int b=x-a+1;
					if (1<=b&&b<=k) add(N(i,a),1,N(j,b),1);
					if (a>x) ban(i,a),ban(j,a);
				}
			} else {
				read(j),read(x);
				for (int a=1;a<=k;a++) {
					int b=x-a+1;
					if (1<=b&&b<=k) add(N(i,a),0,N(j,b),0);
					if (k+a<x) ban(i,a),ban(j,a);
				}
			}
		}
		for (int i=1;i<=tot;i++) dfn[i]=bel[i]=low[i]=0;
		top=col=id=0;
		for (int i=1;i<=tot;i++) if (!dfn[i]) tarjan(i);
		int flag=1;
		for (int i=1;i<=n*k;i++) if (bel[i*2-1]==bel[i*2]) { flag=0; break; }
		if (!flag) { puts("-1"); continue; }
		for (int i=1;i<=col;i++) in[i]=0,h[i].clear();
		for (int i=1;i<=tot;i++) for (int &j : g[i]) if (bel[i]!=bel[j]) ADD(bel[i],bel[j]);
		hd=1,tl=0;
		for (int i=1;i<=col;i++) if (!in[i]) q[++tl]=i;
		int pos=0;
		while (hd<=tl) {
			int x=q[hd]; hd++; DFN[x]=++pos;
			for (int &y : h[x]) {
				in[y]--; if (!in[y]) q[++tl]=y;
			}
		}
		for (int i=1;i<=n;i++) {
			int mx=0;
			for (int j=1;j<=k;j++) if (DFN[bel[N(i,j)*2-1]]>DFN[bel[N(i,j)*2]]) mx=j;
			printf("%d ",mx);
		}
		puts("");
	}
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