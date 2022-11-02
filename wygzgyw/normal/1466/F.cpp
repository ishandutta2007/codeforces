#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(5e5)+10;
int n,m,fa[maxn],flag[maxn],mi[maxn];
struct node { int x,y; } d[maxn];
void init() {
	for (int i=1;i<=m;i++) fa[i]=i,flag[i]=0;
}
int find(int x) {
	if (!x) return 0;
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
//int dfn[maxn],low[maxn],cut[maxn],idx,faa[maxn];
/*int head[maxn],nxt[maxn*2],to[maxn*2],TOT;
void add(int x,int y) {
	TOT++; nxt[TOT]=head[x];
	head[x]=TOT; to[TOT]=y;
}
void tarjan(int u) {
    dfn[u]=low[u]=++idx;
    for (int i=head[u],v;i;i=nxt[i]) {
        v=to[i];
        if (dfn[v]==-1) {
            faa[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]) {
            	cut[i/2]=1;
            }
        }
        else if (v!=faa[u])
            low[u]=min(low[u],dfn[v]);
    }
}*/
bool insert(node A) {
	int x=find(A.x),y=find(A.y);
	if (!y) {
		if (!flag[x]) { flag[x]=1; return 1; }
		return 0;
	}
	if (x==y) return 0;
	int res=1;
	if (flag[x]&&flag[y]) res=0;
	fa[x]=y,flag[y]|=flag[x];
	return res;
}
//int mk_pre[maxn],fx[maxn],fy[maxn];
int dd[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*2%mod;
	read(n),read(m); int op,x,y,ans=0;
	init(); //TOT=1;
	for (int i=1;i<=n;i++) {
		read(op);
		if (op==1) read(x),y=0;
		else read(x),read(y);
		d[i]=(node){x,y};
		/*if (y) add(x,y),add(y,x);
		fx[i]=flag[find(x)]; if (y) fy[i]=flag[find(y)];
		if (y&&find(x)==find(y)) mk_pre[i]=1;*/
		if (insert(d[i])) ans++,dd[ans]=i;
	}
	printf("%d ",mi[ans]);
	/*memset(dfn,-1,sizeof(dfn));
	for (int i=1;i<=m;i++) if (dfn[i]==-1) tarjan(i);
	init();
	int f1,f2,res,tot=0;
	for (int i=n;i>=1;i--) {
		x=d[i].x,y=d[i].y;
		f1=(fx[i]|flag[find(x)]);
		f2=(fy[i]|flag[find(y)]);
		res=1;
		if (f1&&f2) res=0;
		else if (mk_pre[i]||find(x)==find(y)) res=0;
		else if (cut[i]) res=0;
		if (res) dd[++tot]=i;
		insert(d[i]);
	}
	reverse(dd+1,dd+tot+1);*/
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d ",dd[i]); printf("\n");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/