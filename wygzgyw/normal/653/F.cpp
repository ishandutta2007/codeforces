#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+5;
const int maxm=(2e7)+5;
const int INF=(1e9);
int n;
char S[maxn];
ll ans;
struct string {
	int sa[maxn],rk[maxn];
	int SA[maxn],RK[maxn];
	int h[maxn];
	int cnt[maxn];
	void initSA() {
		for (int i=1;i<=n;i++) cnt[S[i]]++;
		for (int i='(';i<=')';i++) cnt[i]+=cnt[i-1];
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
		//for (int i=1;i<=n;i++) printf("%d ",rk[i]); printf("\n");
	}
	void initH() {
		for (int i=1,j,lst=1;i<=n;i++) {
			j=sa[rk[i]-1]; if (lst) lst--;
			while (S[i+lst]==S[j+lst]) lst++;
			h[rk[i]]=lst;
		}
		//for (int i=1;i<=n;i++) printf("%d ",h[i]); printf("\n");
	}
} T;
int rt[maxn],s[maxn];
ll tr[maxm];
int tot,ls[maxm],rs[maxm],N,mx,mn;
int d[maxn],nxt[maxn];
void add(int x,int l,int r,int &root) {
	tot++;
	ls[tot]=ls[root];
	rs[tot]=rs[root];
	tr[tot]=tr[root];
	root=tot;
	if (l==r) { tr[root]++; return; }
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,ls[root]);
	else add(x,mid+1,r,rs[root]);
	tr[root]=tr[ls[root]]+tr[rs[root]];
}
int query(int z,int l,int r,int x,int y) {
	if (l==r) return tr[y]-tr[x];
	int mid=(l+r)/2;
	if (z<=mid) return query(z,l,mid,ls[x],ls[y]);
	return query(z,mid+1,r,rs[x],rs[y]);
}
int query(int x,int y) {
	if (x>y) return 0;
	y=min(y,nxt[x-1]);
	return query(s[x-1],0,N,rt[x-1],rt[y]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",S+1);
	T.initSA();
	T.initH();
	mx=mn=0;
	for (int i=1;i<=n;i++) {
		s[i]=s[i-1];
		if (S[i]=='(') s[i]++;
		else s[i]--;
		mx=max(mx,s[i]);
		mn=min(mn,s[i]);
	}
	N=mx-mn;
	for (int i=0;i<=n;i++) s[i]-=mn;
	d[0]=n+1;
	for (int i=n;i>=0;i--) {
		while (tot&&s[d[tot]]>=s[i]) tot--;
		nxt[i]=d[tot];
		d[++tot]=i;
	}
	for (int i=0;i<=n;i++) nxt[i]--;
	//for (int i=0;i<=n;i++) printf("%d ",s[i]); printf("\n");
	//for (int i=0;i<=n;i++) printf("%d ",nxt[i]); printf("\n");
	tot=0;
	add(s[0],0,N,rt[0]);
	for (int i=1;i<=n;i++)
		rt[i]=rt[i-1],add(s[i],0,N,rt[i]);
	//for (int i=1;i<=n;i++) printf("%d %d\n",i,query(i,n));
	for (int i=1,pos;i<=n;i++) {
		pos=T.sa[i];
		ans+=query(pos,n)-query(pos,pos+T.h[i]-1);
		//printf("%d %lld\n",pos,ans);
	}
	printf("%lld\n",ans);
//	printf("MLE %d\n",(sizeof(tr)+sizeof(ls)+sizeof(rs)+sizeof(T)+sizeof(S)+sizeof(s))/1024/1024);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/