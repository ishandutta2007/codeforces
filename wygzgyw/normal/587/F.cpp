#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,q,tot,pos[maxn];
int fail[maxn];
int ch[maxn][26];
char s[maxn];
vector<int> CH[maxn];
void add(int id) {
	scanf("%s",s+1);
    int len=strlen(s+1);
    int u=0,tmp;
    for (int i=1;i<=len;i++) {
        tmp=s[i]-'a';
        if (!ch[u][tmp]) {
        	ch[u][tmp]=++tot;
        	CH[u].push_back(tot);
        }
        u=ch[u][tmp];
    }
    pos[id]=u;
}
int Q[maxn];
void ACinit() {
    int u,l=1,r=0;
    for (int i=0;i<26;i++)
        if (ch[0][i]) Q[++r]=ch[0][i],fail[ch[0][i]]=0;
    while (l<=r) {
        u=Q[l]; l++;
        for (int i=0;i<26;i++)
            if (ch[u][i]) Q[++r]=ch[u][i],fail[ch[u][i]]=ch[fail[u]][i];
            else ch[u][i]=ch[fail[u]][i];
    }
}
vector<int> son[maxn];
int block,dfn[maxn],ed[maxn],cnt,idx,bk[maxn];
void dfs(int u) {
	dfn[u]=idx; bk[idx]=u; idx++;
	for (int v : son[u]) dfs(v);
	ed[u]=idx-1;
}
ll ans[maxn],res; int bel[maxn],L[maxn],R[maxn],mk[maxn];
int ycl[350][maxn],delta[maxn],dfn2[maxn],ed2[maxn];
void dfs2(int u) {
	dfn2[u]=idx; idx++;
	for (int v : CH[u]) {
		ycl[cnt][v]=ycl[cnt][u]+mk[v];
		dfs2(v);
	}
	ed2[u]=idx-1;
}
struct event {
	int id,delta,k;
};
vector<event> g[maxn];
namespace BIT {
	ll a[maxn],b[maxn];
	void ADD(int x,int delta) {
		a[x]+=delta;
		b[bel[x]]+=delta;
	}
	ll query(int x) {
		ll res=0;
		for (int i=1;i<bel[x];i++) res+=b[i];
		for (int i=L[bel[x]];i<=x;i++) res+=a[i];
		return res;
	}
	void add(int x) {
		x=bk[x];
		//printf("add %d\n",x);
		ADD(dfn2[x],1);
		ADD(ed2[x]+1,-1);
	}
};
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) add(i);
	ACinit();
	for (int i=1;i<=tot;i++) {
		son[fail[i]].push_back(i);
		//printf("%d %d\n",i,fail[i]);
	}
	dfs(0); block=(int)sqrt(tot*1.0);
	for (int i=0,j;i<=tot;i=j+1) {
		j=min(tot,i+block-1);
		L[++cnt]=i,R[cnt]=j;
		//printf("?? %d %d\n",i,j);
		for (int k=i;k<=j;k++) {
			bel[k]=cnt;
			mk[bk[k]]++;
		}
		idx=0;
		dfs2(0);
		for (int k=i;k<=j;k++) mk[bk[k]]--;
	}
	
	int l,r,k,x;
	for (int i=1;i<=q;i++) {
		read(l),read(r),read(k);
		if (l>1) g[l-1].push_back((event){i,-1,k});
		g[r].push_back((event){i,1,k});
	}
	for (int i=1;i<=n;i++) {
		x=pos[i];
		l=dfn[x],r=ed[x];
		//printf("HI i=%d, x=%d, %d %d\n",i,x,l,r);
		if (bel[l]==bel[r]) {
			for (int j=l;j<=r;j++) BIT::add(j);
		} else {
			for (int j=l;j<=R[bel[l]];j++) BIT::add(j);
			for (int j=L[bel[r]];j<=r;j++) BIT::add(j);
			for (int j=bel[l]+1;j<bel[r];j++) delta[j]++;
		}
		for (event A : g[i]) {
			x=pos[A.k]; res=0;
			for (int j=1;j<=cnt;j++) {
				res+=(ll)ycl[j][x]*delta[j];
			}
			res+=BIT::query(dfn2[x]);
			ans[A.id]+=res*A.delta;
		}
	}
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
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