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
typedef long long ll;
const int maxn=(2.5e5)+10;
int N; int S[maxn]; char s[maxn]; ll ans;
int n,k,L[maxn],R[maxn],lg[maxn];
	int sa[maxn],rk[maxn];
	int SA[maxn],RK[maxn];
	int h[maxn],st[maxn][21];
	int cnt[maxn];
	void initSA() {
		for (int i=1;i<=N;i++) cnt[S[i]]++;
		for (int i='a';i<='z'+n+5;i++) cnt[i]+=cnt[i-1];
		for (int i=1;i<=N;i++) sa[cnt[S[i]]--]=i;
		for (int i=1;i<=N;i++) rk[sa[i]]=rk[sa[i-1]]+(S[sa[i]]!=S[sa[i-1]]);
		for (int j=1;j<=N;j*=2) {
			for (int i=1;i<=N;i++) cnt[rk[sa[i]]]=i;
			for (int i=N;i>=1;i--) if (sa[i]>j) SA[cnt[rk[sa[i]-j]]--]=sa[i]-j;
			for (int i=N;i>=1;i--) if (sa[i]>N-j) SA[cnt[rk[sa[i]]]--]=sa[i];
			for (int i=1;i<=N;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+j]!=rk[SA[i-1]+j]);
			for (int i=1;i<=N;i++) swap(sa[i],SA[i]),swap(rk[i],RK[i]);
			if (rk[sa[N]]>=N) break;
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
	int query(int l,int r) {
		if (l==r) return 1e9;
		if (l>r) swap(l,r);
		int j=lg[r-l];
		return min(st[r][j],st[l+(1<<j)][j]);
	}
	void GET(int x,int y,int &L,int &R) {
		int l=1,r=x,mid; L=R=x;
		while (l<=r) {
			mid=(l+r)>>1; if (query(mid,x)>=y) L=mid,r=mid-1; else l=mid+1;
		}
		l=x,r=N;
		while (l<=r) {
			mid=(l+r)>>1; if (query(mid,x)>=y) R=mid,l=mid+1; else r=mid-1;
		}
	}
int rt[maxn],d[maxn],tot;
vector<int> g[maxn];
namespace Seg {
	const int maxm=maxn*40;
	int tot,tr[maxm],ls[maxm],rs[maxm];
	void add(int x,int l,int r,int &root) {
		tot++; ls[tot]=ls[root]; rs[tot]=rs[root]; tr[tot]=tr[root]; root=tot;
		if (l==r) { tr[root]++; return; }
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,ls[root]);
		else add(x,mid+1,r,rs[root]);
		tr[root]=tr[ls[root]]+tr[rs[root]];
	}
	int query(int L,int R,int l,int r,int root) {
		if (L>R) return 0;
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=0;
		if (L<=mid) res=query(L,R,l,mid,ls[root]);
		if (mid<R) res+=query(L,R,mid+1,r,rs[root]);
		return res;
	}
};
vector<pair<int,int> > D;
bool check(int x,int y) {
	y=y-x+1; x=rk[x];
	int l,r; GET(x,y,l,r);
	int res=Seg::query(0,l-1,0,N+1,rt[r+1]),RES=0;
	//for (pair<int,int> &A : D) RES+=(A.first<l&&r<A.second);
//printf("l=%d r=%d,res=%d,RES=%d\n",l,r,res,RES);
	return res<=n-k;
}
int main() {
	read(n),read(k);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		int len=strlen(s+1);
		L[i]=N+1; for (int j=1;j<=len;j++) S[++N]=s[j]; R[i]=N; S[++N]=i+'z';
		if (k==1) printf("%lld ",(ll)len*(len+1)/2);
	}
	if (k==1) { puts(""); return 0; }
	for (int i=2;i<=N;i++) lg[i]=lg[i>>1]+1;
	initSA(); initH();
	for (int i=1;i<=n;i++) {
		tot=0;
		for (int j=L[i];j<=R[i];j++) d[++tot]=rk[j];
		sort(d+1,d+tot+1);
		d[tot+1]=N+1;
		for (int j=0;j<=tot;j++) {
			int l=d[j],r=d[j+1];
			if (l<=r) g[r].push_back(l),D.push_back(MP(l,r));
		}
	}
	for (int i=N+1;i>=0;i--) {
		rt[i]=rt[i+1];
		for (int &j : g[i]) Seg::add(j,0,N+1,rt[i]);
	}
	for (int i=1;i<=n;i++) {
		ans=0;
		for (int l=L[i],r=L[i];l<=R[i];l++) {
			r=max(r,l);
			while (r<R[i]&&check(l,r+1)) r++;
			if (check(l,r)) {
				ans+=r-l+1;
			//	printf("l=%d,r=%d\n",l,r);
			}
		} printf("%lld ",ans);
		//	exit(0);
	} puts("");
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