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
const int maxn=(6e5)+10;
const int B=40;
int n,q,a[maxn];
int lsh[maxn],N;
struct node {
	int op,l,r,k,x,y;
} Q[maxn];
void F(int &x) { x=lower_bound(lsh+1,lsh+N+1,x)-lsh; }
bool in[B][maxn];
struct BIT {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x<=n;x+=x&(-x)) tr[x]+=delta;
	}
	int query(int x) {
		int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
	}
	int query(int l,int r) { return query(r)-query(l-1); }
} T[B];
mt19937 rnd(time(0));
int main() {
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
	for (int i=1;i<=q;i++) {
		read(Q[i].op);
		if (Q[i].op==1) read(Q[i].x),read(Q[i].y),lsh[++N]=Q[i].y;
		else read(Q[i].l),read(Q[i].r),read(Q[i].k);
	}
	sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
	for (int i=1;i<=n;i++) F(a[i]);
	for (int i=1;i<=q;i++) if (Q[i].op==1) F(Q[i].y);
	for (int i=0;i<B;i++) {
		for (int j=1;j<=N;j++) if (rnd()&1) in[i][j]=1;
	}
	for (int i=1;i<=n;i++) for (int j=0;j<B;j++) if (in[j][a[i]]) T[j].add(i,1);
	for (int i=1;i<=q;i++) {
		if (Q[i].op==1) {
			int x=Q[i].x,y=Q[i].y;
			for (int j=0;j<B;j++) {
				if (in[j][a[x]]) T[j].add(x,-1);
				if (in[j][y]) T[j].add(x,1);
			}
			a[x]=y;
		} else {
			int k=Q[i].k,l=Q[i].l,r=Q[i].r;
			if (k==1) { puts("YES"); continue; }
			if ((r-l+1)%k!=0) { puts("NO"); continue; }
			int flag=1;
			for (int j=0;j<B&&flag;j++) {
				flag&=(T[j].query(Q[i].l,Q[i].r)%Q[i].k==0);
			}
			if (flag) puts("YES"); else puts("NO");
		}
	}
	return 0;
}