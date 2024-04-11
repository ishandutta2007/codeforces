#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
const int INF=1e9;
int n,lg[maxn];
ll ans;
char S[maxn];
struct SASA {
	int sa[maxn],rk[maxn];
	int SA[maxn],RK[maxn];
	int h[maxn],st[maxn][21];
	int cnt[maxn];
	void initSA() {
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[S[i]]++;
		for (int i='a';i<='z';i++) cnt[i]+=cnt[i-1];
		for (int i=1;i<=n;i++) sa[cnt[S[i]]--]=i;
		for (int i=1;i<=n;i++) rk[sa[i]]=rk[sa[i-1]]+(S[sa[i]]!=S[sa[i-1]]);
		for (int j=1;j<=n;j*=2) {
			for (int i=1;i<=n;i++) cnt[rk[sa[i]]]=i;
			for (int i=n;i>=1;i--) if (sa[i]>j) SA[cnt[rk[sa[i]-j]]--]=sa[i]-j;
			for (int i=n;i>=1;i--) if (sa[i]>n-j) SA[cnt[rk[sa[i]]]--]=sa[i];
			for (int i=1;i<=n;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+j]!=rk[SA[i-1]+j]);
			for (int i=1;i<=n;i++) swap(sa[i],SA[i]),swap(rk[i],RK[i]);
			if (rk[sa[n]]>=n) break;
		}
	}
	void initH() {
		for (int i=1,j,lst=1;i<=n;i++) {
			j=sa[rk[i]-1]; if (lst) lst--;
			while (S[i+lst]==S[j+lst]) lst++;
			h[rk[i]]=lst;
		}
		for (int i=1;i<=n;i++) st[i][0]=h[i];
		for (int j=1;(1<<j)<=n;j++)
		for (int i=(1<<j);i<=n;i++)
			st[i][j]=min(st[i][j-1],st[i-(1<<(j-1))][j-1]);
	}
	int STQ(int l,int r) {
		if (l==r) return n-l+1;
		l=rk[l],r=rk[r];
		if (l>r) swap(l,r);
		int j=lg[r-l];
		return min(st[r][j],st[l+(1<<j)][j]);
	}
} T;
int cnt,lst,len[maxn*3],a[maxn*3][30],fa[maxn*3],pos[maxn*3];
void extend(int c,int i) {
	int p=lst,np=lst=++cnt;
	len[np]=len[p]+1;
	pos[lst]=i;
	while (a[p][c]==0&&p!=0)
		a[p][c]=np,p=fa[p];
	if (p==0) fa[np]=1;
	else {
		int q=a[p][c];
		if (len[p]+1==len[q]) fa[np]=q;
		else {
			int nq=++cnt; len[nq]=len[p]+1;
			memcpy(a[nq],a[q],sizeof(a[q]));
			fa[nq]=fa[q];
			fa[np]=fa[q]=nq;
			while (a[p][c]==q) a[p][c]=nq,p=fa[p];
		}
	}
}
set<int> s[maxn];
set<int>::iterator it,it1,it2;
ll sum[maxn];
queue<int> q;
int deg[maxn*3],rt[maxn];
int merge(int x,int y) {
	if (!x||!y) return x+y;
	if ((int)s[x].size()<(int)s[y].size()) swap(x,y);
	//printf("%d %d\n",x,y);
	int a,b,c;
	for (it=s[y].begin();it!=s[y].end();it++) {
		b=*it;
		if (b==0||b==INF) continue;
		s[x].insert(b),it1=s[x].find(b),it2=it1;
		it1--,it2++;
		a=(*it1),c=(*it2);
		if (abs(c)!=INF) sum[x]-=n-T.sa[c]+1-T.STQ(T.sa[a],T.sa[c]);
		if (abs(a)!=INF) sum[x]+=n-T.sa[b]+1-T.STQ(T.sa[a],T.sa[b]);
		if (abs(c)!=INF) sum[x]+=n-T.sa[c]+1-T.STQ(T.sa[b],T.sa[c]);
	}
	//s[y].clear();
	return x;
}
void dfs() {
	for (int i=2;i<=cnt;i++) deg[fa[i]]++;
	for (int i=1;i<=cnt;i++) if (deg[i]==0) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		//printf("HI %d\n",u);
		int p=fa[u]; deg[p]--;
		if (!deg[p]) q.push(p);
		if (pos[u]) rt[u]=merge(rt[u],pos[u]+2);
		ans+=(ll)(len[u]-len[p])*(sum[rt[u]]+1);
		rt[p]=merge(rt[p],rt[u]);
	}
}
int main() {
	//freopen("harmony1.in","r",stdin);
	scanf("%s",S+1); n=strlen(S+1);
	for (int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	T.initSA(),T.initH();
	cnt=lst=1;
	for (int i=1;i<n;i++) extend(S[i]-'a',i);
	for (int i=1;i<=n;i++) {
		s[i].insert(0),s[i].insert(INF);
		s[i].insert(T.rk[i]);
		sum[i]=n-i+1;
	}
	dfs();
	//printf("%lld\n",ans);
	extend(S[n]-'a',n);
	for (int i=1;i<=cnt;i++) ans+=len[i]-len[fa[i]];
	//for (int i=1;i<=n;i++) printf("%lld ",sum[i]); printf("\n");
	memset(a,0,sizeof(a)); memset(len,0,sizeof(len)); memset(fa,0,sizeof(fa));
	cnt=lst=1;
	for (int i=n;i>=2;i--) extend(S[i]-'a',i);
	for (int i=1;i<=cnt;i++) ans+=len[i]-len[fa[i]];
	
	printf("%lld\n",ans+2);
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