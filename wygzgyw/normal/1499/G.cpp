#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(4e5)+10;
int n1,n2,m,deg[maxn],q;
int ans,mi[maxn];
vector<int> res;
vector<deque<int> > cyc,path;
int id[maxn],bg[maxn],ed[maxn];
int haxi[maxn][2];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void add(int x,int y,int now) {
	if (!deg[x]&&!deg[y]) {
		int cur=id[x]=id[y]=(int)path.size();
		bg[cur]=x,ed[cur]=y;
		path.push_back({now});
		haxi[cur][0]=mi[now];
		haxi[cur][1]=0;
	} else {
		if (deg[x]) swap(x,y);
		if (!deg[x]) {
			int cur=id[x]=id[y];
			update(ans,mod-haxi[cur][1]);
			//if (m==21) printf("%d %d %d %d %d\n",x,y,deg[x],deg[y],ans);
			if (y==ed[cur]) {
				update(haxi[cur][(int)path[cur].size()&1],mi[now]);
				path[cur].push_back(now); ed[cur]=x;
			} else {
				path[cur].push_front(now);
				swap(haxi[cur][0],haxi[cur][1]);
				update(haxi[cur][0],mi[now]);
				bg[cur]=x;
			}
			id[y]=-1;
			update(ans,haxi[cur][1]);
		} else {
			//if (m==22) printf("%d %d %d %d %d %d %d\n",x,y,id[x],id[y],deg[x],deg[y],ans);
			if (id[x]==id[y]) {
				int cur=id[x];
				cyc.push_back(path[cur]);
				update(ans,mod-haxi[cur][1]);
				update(haxi[cur][(int)path[cur].size()&1],mi[now]);
				update(ans,haxi[cur][1]);
				cyc.back().push_back(now);
				path[cur].clear();
				id[x]=id[y]=-1;
			} else {
				if ((int)path[id[x]].size()<(int)path[id[y]].size()) swap(x,y);
				update(ans,mod-haxi[id[y]][1]);
				if (bg[id[y]]!=y) reverse(path[id[y]].begin(),path[id[y]].end()),swap(bg[id[y]],ed[id[y]]);
				int cur=id[x];
				update(ans,mod-haxi[id[x]][1]);
				if (x==bg[cur]) {
					path[cur].push_front(now);
					swap(haxi[cur][0],haxi[cur][1]);
					update(haxi[cur][0],mi[now]);
					for (int v : path[id[y]]) {
						path[cur].push_front(v);
						swap(haxi[cur][0],haxi[cur][1]);
						update(haxi[cur][0],mi[v]);
					}
					bg[cur]=ed[id[y]];
				} else {
					update(haxi[cur][(int)path[cur].size()&1],mi[now]);
					path[cur].push_back(now);
					for (int v : path[id[y]]) {
						update(haxi[cur][(int)path[cur].size()&1],mi[v]);
						path[cur].push_back(v);
					}
					ed[cur]=ed[id[y]];
					//printf("OK %d %d\n",ans,haxi[cur][1]);
				}
				update(ans,haxi[cur][1]);
				id[ed[id[y]]]=cur;
				path[id[y]].clear();
				id[x]=id[y]=-1;
			}
		}
	}
	deg[x]^=1,deg[y]^=1;
}
int main() {
	//freopen("1.txt","r",stdin);
	memset(id,-1,sizeof(id)); mi[0]=1;
	for (int i=1;i<maxn;i++) mi[i]=(mi[i-1]<<1)%mod;
	read(n1),read(n2),read(m);
	int x,y,op;
	for (int i=1;i<=m;i++) {
		read(x),read(y); y+=n1;
		add(x,y,i);
	}
	//printf("%d\n",ans);
	read(q);
	while (q--) {
		read(op);
		if (op==1) {
			read(x),read(y); y+=n1;
			m++; add(x,y,m);
			printf("%d\n",ans);
		} else {
			res.clear();
			for (deque<int> A : cyc) for (int i=0;i<A.size();i++) if (i&1) res.push_back(A[i]);
			for (deque<int> A : path) for (int i=0;i<A.size();i++) if (i&1) res.push_back(A[i]);
			printf("%d ",(int)res.size());
			for (int x : res) printf("%d ",x); puts("");
		}
		fflush(stdout);
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