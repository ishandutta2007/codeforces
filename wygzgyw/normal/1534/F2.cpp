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
int n,m,N,ans;
vector<char> s[maxn];
vector<int> num[maxn];
int in[maxn];
char S[maxn];
set<int> c[maxn];
int cnt,idx;
vector<int> g[maxn],h[maxn];
int dfn[maxn],low[maxn];
int sid[maxn];
vector<int> scc[maxn];
bool inStack[maxn];
int a[maxn];
pair<int,int> pos[maxn];
stack<int> st;
void tarjan(int u) {
    dfn[u]=low[u]=++idx;
    inStack[u]=1;
    st.push(u);
    for (int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if (dfn[v]==-1) {
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
            scc[cnt].push_back(v);
            sid[v]=cnt;
            if (v==u) break;
        }
    }
}
int L[maxn],R[maxn],id[maxn],tot;
vector<int> H[maxn];
queue<int> q;
void add(int x,int y) { g[x].push_back(y); h[y].push_back(x); }

int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=0;i<=n+1;i++) s[i].resize(m+1),num[i].resize(m+1);
	for (int i=1;i<=n;i++) {
		scanf("%s",S+1);
		for (int j=1;j<=m;j++) {
			s[i][j]=S[j];
			if (s[i][j]=='#') {
				c[j].insert(i);
				num[i][j]=++N; pos[N]=MP(i,j);
				if (i>1&&s[i-1][j]=='#') add(num[i][j],num[i-1][j]),add(num[i-1][j],num[i][j]);
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='#') {
		set<int>::iterator it;
		it=c[j].upper_bound(i);
		if (it!=c[j].end()) add(num[i][j],num[*it][j]);
		if (j>1) {
			it=c[j-1].lower_bound(i);
			if (it!=c[j-1].end()) add(num[i][j],num[*it][j-1]);
		}
		if (j<m) {
			it=c[j+1].lower_bound(i);
			if (it!=c[j+1].end()) add(num[i][j],num[*it][j+1]);
		}
	}
	
	for (int i=1;i<=N;i++) dfn[i]=-1;
	for (int i=1;i<=N;i++) if (dfn[i]==-1) tarjan(i);
	
	for (int i=1;i<=N;i++) for (int j : g[i]) if (sid[i]!=sid[j]) H[sid[i]].push_back(sid[j]),in[sid[j]]++;
	
	for (int i=1;i<=cnt;i++) if (!in[i]) q.push(i);
	
	while (!q.empty()) {
		int x=q.front(); q.pop(); id[++tot]=x;
		for (int y : H[x]) { in[y]--; if (!in[y]) q.push(y); }
	}
	
	for (int ii=1;ii<=cnt;ii++) {
		int l=(1e9),r=0,i=id[ii];
		for (int x : scc[i]) {
			l=min(l,pos[x].second),r=max(r,pos[x].second);
			for (int y : h[x]) if (sid[x]!=sid[y]) l=min(l,L[y]),r=max(r,R[y]);
		}
		for (int x : scc[i]) L[x]=l,R[x]=r;
	}
	vector<pair<int,int> > seg;
	for (int i=1;i<=m;i++) {
		read(a[i]);
		if (!a[i]) continue;
		for (int j=n;j>=1;j--) if (s[j][i]=='#') {
			a[i]--;
			if (!a[i]) {
				seg.push_back(MP(R[num[j][i]],L[num[j][i]]));
				break;
			}
		}
	}
	sort(seg.begin(),seg.end());
	int lst=-1;
	for (pair<int,int> A:seg) {
		if (A.second>lst) ans++,lst=A.first;
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