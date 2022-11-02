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
const ll INF=1e18;
const int maxn=(1e5)+10;
int n;
int dx1[maxn],dx2[maxn],dy1[maxn],dy2[maxn];
void chkmin(ll &x,ll y) { if (x>y) x=y; }
struct Matrix {
	ll d[2][2];
	friend Matrix operator + (Matrix t1,Matrix t2) {
		Matrix res;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
			res.d[i][j]=INF;
			for (int k=0;k<2;k++) chkmin(res.d[i][j],t1.d[i][k]+t2.d[k][j]);
		}
		return res;
	}
	void init() {
		d[0][0]=d[1][1]=0,d[0][1]=d[1][0]=INF;
	}
} tr[maxn*4];
int dis(int x1,int y1,int x2,int y2) { return abs(x1-x2)+abs(y1-y2); }
void build(int l,int r,int root) {
	if (l==r) {
		Matrix &A=tr[root];
		int d=dis(dx1[l],dy1[l],dx2[l],dy2[l]);
		A.d[0][0]=min(dis(dx1[l],dy1[l]+1,dx1[l+1],dy1[l+1]),d+dis(dx2[l]+1,dy2[l],dx1[l+1],dy1[l+1]))+1;
		A.d[0][1]=min(dis(dx1[l],dy1[l]+1,dx2[l+1],dy2[l+1]),d+dis(dx2[l]+1,dy2[l],dx2[l+1],dy2[l+1]))+1;
		A.d[1][0]=min(dis(dx2[l]+1,dy2[l],dx1[l+1],dy1[l+1]),d+dis(dx1[l],dy1[l]+1,dx1[l+1],dy1[l+1]))+1;
		A.d[1][1]=min(dis(dx2[l]+1,dy2[l],dx2[l+1],dy2[l+1]),d+dis(dx1[l],dy1[l]+1,dx2[l+1],dy2[l+1]))+1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=tr[root<<1]+tr[root<<1|1];
}
Matrix res;
void query(int L,int R,int l,int r,int root) {
	if (L>R) return;
	if (L<=l&&r<=R) { res=res+tr[root]; return; }
	int mid=(l+r)>>1;
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<n;i++) {
		read(dx1[i]),read(dy1[i]),read(dx2[i]),read(dy2[i]);
		swap(dx1[i],dy1[i]);
		swap(dx2[i],dy2[i]);
	}
	build(1,n,1);
	int m; read(m);
	while (m--) {
		int x1,y1,x2,y2;
		read(x1),read(y1),read(x2),read(y2);
		swap(x1,y1),swap(x2,y2);
		int a=max(x1,y1),b=max(x2,y2);
		if (a>b) swap(a,b),swap(x1,x2),swap(y1,y2);
		if (a==b) { printf("%d\n",abs(x1-x2)+abs(y1-y2)); continue; }
		res.init();
		query(a,b-2,1,n,1);
		ll d[2],e[2];
		d[0]=dis(x1,y1,dx1[a],dy1[a]);
		d[1]=dis(x1,y1,dx2[a],dy2[a]);
		e[0]=dis(x2,y2,dx1[b-1],dy1[b-1]+1);
		e[1]=dis(x2,y2,dx2[b-1]+1,dy2[b-1]);
	//	printf("%d %d\n",dx2[b-1]+1,dy2[b-1]);
		//printf("%lld %lld\n",d[1],e[1]);
		ll ans=INF;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
			chkmin(ans,res.d[i][j]+d[i]+e[j]+1);
			//if (ans==4) printf("%d %d %lld %lld %lld\n",i,j,d[i],e[j],res.d[i][j]);
		}
		printf("%lld\n",ans);
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