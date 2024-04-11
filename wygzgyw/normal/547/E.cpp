#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxm=(1e7);
const int maxn=(4e5)+10;
const int INF=(1e9);
char s[maxn];
int n,q,N,lg[maxn],S[maxn];
int L[maxn/2],R[maxn/2],ans;
struct string {
	int sa[maxn],rk[maxn];
	int SA[maxn],RK[maxn];
	int h[maxn],st[maxn][21];
	int cnt[maxn];
	void initSA() {
		for (int i=1;i<=N;i++) cnt[S[i]]++;
		for (int i='a';i<='z'+n;i++) cnt[i]+=cnt[i-1];
		for (int i=1;i<=N;i++) sa[cnt[S[i]]--]=i;
		for (int i=1;i<=N;i++) rk[sa[i]]=rk[sa[i-1]]+(S[sa[i]]!=S[sa[i-1]]);
		for (int j=1;j<=N;j*=2) {
			for (int i=1;i<=N;i++) cnt[rk[sa[i]]]=i;
			for (int i=N;i>=1;i--) if (sa[i]>j) SA[cnt[rk[sa[i]-j]]--]=sa[i]-j;
			for (int i=N;i>=1;i--) if (sa[i]>N-j) SA[cnt[rk[sa[i]]]--]=sa[i];
			for (int i=1;i<=N;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+j]!=rk[SA[i-1]+j]);
			swap(sa,SA); swap(rk,RK);
			if (rk[sa[n]]>=N) break;
		}
	}
	void initH() {
		for (int i=1,j,lst=1;i<=N;i++) {
			j=sa[rk[i]-1]; if (lst) lst--;
			while (S[i+lst]==S[j+lst]) lst++;
			h[rk[i]]=lst;
		}
		for (int i=1;i<=N;i++) st[i][0]=h[i];
		for (int j=1;(1<<j)<=N;j++)
		for (int i=(1<<j);i<=N;i++)
			st[i][j]=min(st[i][j-1],st[i-(1<<(j-1))][j-1]);
	}
	int STQ(int l,int r) {
		if (l==r) return INF;
		if (l>r) swap(l,r);
		int j=lg[r-l];
		return min(st[r][j],st[l+(1<<j)][j]);
	}
} T;
int rt[maxn/2],tr[maxm],ls[maxm],rs[maxm],tot;
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
int query(int L,int R,int l,int r,int x,int y) {
	if (L<=l&&r<=R) return tr[y]-tr[x];
	int mid=(l+r)/2,res=0;
	if (L<=mid) res+=query(L,R,l,mid,ls[x],ls[y]);
	if (mid<R) res+=query(L,R,mid+1,r,rs[x],rs[y]);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	//printf("MLE %d\n",(sizeof(tr)*3)/1024/1024);
	read(n); read(q);
	int len;
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		len=strlen(s+1);
		L[i]=N+1;
		for (int j=1;j<=len;j++)
			S[++N]=s[j];
		S[++N]=i+'z';
		R[i]=N;
	}
	T.initSA();
	T.initH();
	/*for (int i=1;i<=N;i++) printf("%d ",S[i]); printf("\n");
	for (int i=1;i<=N;i++) printf("%d ",T.rk[i]); printf("\n");
	for (int i=1;i<=N;i++) printf("%d ",T.h[i]); printf("\n");*/
	for (int i=1;i<=n;i++) {
		rt[i]=rt[i-1];
		for (int j=L[i];j<=R[i];j++) {
			add(T.rk[j],1,N,rt[i]);
		}
	}
	for (int j=1;(1<<j)<=N;j++)
	for (int i=(1<<j);i<(1<<(j+1))&&i<=N;i++) lg[i]=j;
	tot=0;
	int l,r,mid,res,x,y,k;
	int t1,t2;
	while (q--) {
		read(x); read(y); read(k);
		l=1,r=T.rk[L[k]];
		while (l<=r) {
			mid=(l+r)/2;
			if (T.STQ(mid,T.rk[L[k]])>=R[k]-L[k]) res=mid,r=mid-1;
			else l=mid+1;
		}
		t1=res;
		l=T.rk[L[k]],r=N;
		while (l<=r) {
			mid=(l+r)/2;
			if (T.STQ(T.rk[L[k]],mid)>=R[k]-L[k]) res=mid,l=mid+1;
			else r=mid-1;
		}
		t2=res;
		ans=query(t1,t2,1,N,rt[x-1],rt[y]);
		//printf("%d %d %d\n",t1,T.rk[L[k]],t2);
		printf("%d\n",ans);
	}
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