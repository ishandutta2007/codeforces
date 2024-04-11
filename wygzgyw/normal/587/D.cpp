#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9)+10;
const int maxn=(4e5)+10;
int n,m,tot;
struct node { int x,y,c,t; } edge[maxn];
vector<int> g[maxn],to[maxn];
int dfn[maxn],low[maxn],sid[maxn],cnt,idx;
bool inStack[maxn];
stack<int> st;
void tarjan(int u) {
    dfn[u]=low[u]=++idx;
    inStack[u]=1;
    st.push(u);
    for (int i=0,v;i<to[u].size();i++) {
        v=to[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (inStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if (dfn[u]==low[u]) {
        cnt++;
        while (1) {
            int v=st.top();
            st.pop(); inStack[v]=0;
            sid[v]=cnt;
            if (v==u) break;
        }
    }
}
map<int,int> k;
bool mk[maxn];
int A(int x) { return x*2; }
int B(int x) { return x*2+1; }
void add(int x,int y) {
	to[x^1].emplace_back(y);
	to[y^1].emplace_back(x);
	//printf("%d %d\n%d %d\n",x^1,y,y^1,x);
}
bool check(int mid) {
	for (int i=1;i<=tot*2+1;i++) dfn[i]=0,to[i].clear();
	idx=cnt=0; st=stack<int>(); int pre,c;
	tot=m;
	for (int i=1;i<=n;i++) {
		k.clear(); pre=-1;
		for (int id : g[i]) {
			c=edge[id].c;
			if (pre==-1) pre=id;
			else tot++,add(B(pre),B(id)),add(B(pre),A(tot)),add(B(id),A(tot)),pre=tot;
			if (!k[c]) k[c]=id;
			else if (k[c]==-1) return 0;
			else add(A(k[c]),A(id)),k[c]=-1;
		}
	}
	for (int i=1;i<=m;i++) if (edge[i].t>mid) {
		to[A(i)].push_back(B(i));
	}
	for (int i=2;i<=tot*2+1;i++) if (!dfn[i]) tarjan(i);
	//for (int i=2;i<=tot*2+1;i++) printf("sid[%d]=%d\n",i,sid[i]);
	for (int i=1;i<=tot;i++) {
		if (sid[A(i)]==sid[B(i)]) return 0;
		if (sid[A(i)]<sid[B(i)]) mk[i]=1;
		else mk[i]=0;
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=m;i++) {
		read(edge[i].x),read(edge[i].y),read(edge[i].c),read(edge[i].t);
		g[edge[i].x].push_back(i),g[edge[i].y].push_back(i);
	}
	int l=0,r=INF,mid,res=-1;
	while (l<=r) {
		mid=(l+r)>>1;
		if (check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	if (res==-1) { puts("No"); return 0; }
	puts("Yes"); check(res);
	vector<int> ans; ans.clear();
	for (int i=1;i<=m;i++) if (mk[i]) ans.emplace_back(i);
	printf("%d %d\n",res,(int)ans.size());
	for (int i : ans) printf("%d ",i); puts("");
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