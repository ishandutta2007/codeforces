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
const int B=25;
const int maxn=(1e5)+10;
int n,q;
int f1,fn;
int L[maxn][B],R[maxn][B];
ll ans[maxn];
int a[maxn],flag[maxn];
struct node { int l,r,id; } Q[maxn],V[maxn];
int tot,lg[maxn],t1[maxn],t2[maxn];
bool cmp(node A,node B) { return A.l>B.l; }
int st1[maxn][20],st2[maxn][20];
int query1(int l,int r) {
	if (l>r) return a[l];
	int j=lg[r-l+1];
	return min(st1[l][j],st1[r-(1<<j)+1][j]);
}
int query2(int l,int r) {
	if (l>r) return a[l];
	int j=lg[r-l+1];
	return max(st2[l][j],st2[r-(1<<j)+1][j]);
}
void clear() { for (int i=1;i<n;i++) t1[i]=n+1,t2[i]=0; }
void add1(int x,int y) { for (;x<n;x+=x&(-x)) t1[x]=min(t1[x],y); }
void add2(int x,int y) { for (;x<n;x+=x&(-x)) t2[x]=max(t2[x],y); }
int query1(int x) { int res=n+1; for (;x;x-=x&(-x)) res=min(res,t1[x]); return res; }
int query2(int x) { int res=0; for (;x;x-=x&(-x)) res=max(res,t2[x]); return res; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]),f1|=(a[i]==1),fn|=(a[i]==n);
	for (int i=1;i<n;i++) L[i][0]=min(a[i],a[i+1]),R[i][0]=max(a[i],a[i+1]);
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<B;i++) {
		tot=0; clear();
		for (int j=1;j<n;j++) {
			int l=L[j][i-1],r=R[j][i-1]-1;
			if (l>r) { L[j][i]=R[j][i]=a[l]; continue; }
			V[++tot]=(node){l,r,j};
		}
		sort(V+1,V+tot+1,cmp);
		int pos=n;
		for (int j=1;j<=tot;j++) {
			while (pos-1>0&&pos-1>=V[j].l) {
				pos--; add1(pos,L[pos][i-1]); add2(pos,R[pos][i-1]);
			}
			L[V[j].id][i]=query1(V[j].r);
			R[V[j].id][i]=query2(V[j].r);
		}
	}
	tot=0;
	//for (int i=1;i<=3;i++) printf("%d\n",L[i][0]);
	for (int i=1;i<=q;i++) {
		int l,r; read(l),read(r);
		if (n==1||(l==1&&r==n)) { flag[i]=1; ans[i]=0; continue; }
		if (l==r||!f1||!fn) { flag[i]=1; ans[i]=-1; continue; }
		Q[++tot]=(node){l,r,i}; ans[i]=1;
	}
	for (int i=B-1;i>=0;i--) {
		sort(Q+1,Q+tot+1,cmp); clear();
		int pos=n;
		for (int j=1;j<=tot;j++) {
			while (pos-1>0&&pos-1>=Q[j].l) {
				pos--; add1(pos,L[pos][i]); add2(pos,R[pos][i]);
			}
			int a,b;
			if (Q[j].l==Q[j].r) a=b=::a[Q[j].l];
			else a=query1(Q[j].r-1),b=query2(Q[j].r-1);
			int &l=Q[j].l,&r=Q[j].r;
			if (a==1&&b==n) flag[Q[j].id]=1; else l=a,r=b,ans[Q[j].id]+=1LL<<i;
		}
		//exit(0);
	}
	for (int i=1;i<=q;i++) if (!flag[i]) puts("-1"); else writeln(ans[i]);
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