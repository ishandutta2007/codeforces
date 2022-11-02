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
const int maxn=(2e5)+10;
const int INF=1e9;
int n,X[maxn],Y[maxn];
int lx[maxn],c1,ly[maxn],c2;
ll ans=3e18;
vector<int> g[maxn],g2[maxn];
int xmx,xmn,ymx,ymn;
void insert(int k) { xmx=max(xmx,X[k]),ymx=max(ymx,Y[k]),xmn=min(xmn,X[k]),ymn=min(ymn,Y[k]); }
void chkmin(ll &x,ll y) { if (x>y) x=y; }
void solve1() {
	for (int i=1;i<=c1;i++) for (int j=i;j<=c1;j++) {
		for (int l=1;l<=c2;l++) g[l].clear();
		xmx=0,xmn=c1+1,ymx=0,ymn=c2+1;
		for (int k=1;k<=n;k++) if (X[k]>=i&&X[k]<=j) g[Y[k]].push_back(k); else insert(k);
		for (int l=1;l<=c2;l++) {
			for (int &k : g[l-1]) {
				insert(k);
			}
			int a=xmx,b=xmn,c=ymx,d=ymn;
			for (int r=c2;r>=l;r--) {
				for (int &k : g[r+1]) insert(k);
				if (xmx) {
					chkmin(ans,(ll)(lx[j]-lx[i])*(ly[r]-ly[l])+(ll)(lx[xmx]-lx[xmn])*(ly[ymx]-ly[ymn]));
					/*if (ans==1390) {
						printf("%d %d %d %d, %d %d %d %d\n",i,j,l,r,xmn,xmx,ymn,ymx);
						for (int k=1;k<=n;k++) printf("%d %d\n",X[k],Y[k]),assert((X[k]>=i&&X[k]<=j&&Y[k]>=l&&Y[k]<=r)||(X[k]>=xmn&&X[k]<=xmx&&Y[k]>=ymn&&Y[k]<=ymx));
						exit(0);
					}*/
				}
			}
			xmx=a,xmn=b,ymx=c,ymn=d;
		}
	}
}
struct node { int mn,mx; void init() { mx=0,mn=INF; } } pre[maxn],suf[maxn];
node insert(node A,int b) { A.mn=min(A.mn,b), A.mx=max(A.mx,b); return A; }
int A[maxn],B[maxn];
int List[maxn];
int rub[maxn*20],sz[maxn*20];
int *now,*tr[maxn*4];
double Slope(int b2,int b) { return (B[b2]-B[b])*1.0/(A[b]-A[b2]); }
void build(int l,int r,int root) {
	sz[root]=0; tr[root]=now;
	for (int i=l;i<=r;i++) {
		while (sz[root]>1&&Slope(tr[root][sz[root]-2],tr[root][sz[root]-1])<Slope(tr[root][sz[root]-1],i)) sz[root]--;
		tr[root][sz[root]]=i; sz[root]++; now++;
	}
	if (l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
}
ll F(int b,int &k1,int &k2) { return (ll)k1*A[b]+(ll)k2*B[b]; }
void query(int L,int R,int l,int r,int root,int &k1,int &k2,ll &RES) {
	if (L<=l&&r<=R) {
		l=0,r=sz[root]-2; int mid,res=sz[root]-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (F(tr[root][mid],k1,k2)<F(tr[root][mid+1],k1,k2)) res=mid,r=mid-1; else l=mid+1;
		}
		chkmin(RES,F(tr[root][res],k1,k2));
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid) query(L,R,l,mid,root<<1,k1,k2,RES);
	if (mid<R) query(L,R,mid+1,r,root<<1|1,k1,k2,RES);
}
ll query(int l,int r,int k1,int k2) {
	ll res=3e18;
	query(l,r,1,c2,1,k1,k2,res);
//	for (int i=l;i<=r;i++) chkmin(res,(ll)k1*A[i]+(ll)k2*B[i]);
	return res;
}
void Solve() {
	for (int i=1;i<=n+1;i++) g[i].clear(),g2[i].clear();
	for (int i=1;i<=n;i++) g[Y[i]].push_back(i),g2[X[i]].push_back(i);
	for (int b=1;b<=c2;b++) A[b]=ly[b]-ly[1];
	for (int i=c2,mn=c1+1;i>=1;i--) {
		for (int &l : g[i+1]) mn=min(mn,X[l]);
		List[i]=mn; B[i]=lx[c1]-lx[mn];
	}
	now=rub;
	build(1,c2,1);
	for (int a=c1,mn=c2+1;a>=1;a--) {
		for (int &l : g2[a+1]) mn=min(mn,Y[l]);
		int l=mn,r=upper_bound(List+1,List+c2+1,a)-List-1;
		if (l<=r) chkmin(ans,query(l,r,lx[a]-lx[1],ly[c2]-ly[mn]));
	}
}
int L[maxn],R[maxn];
namespace Seg {
	const ll INF=3e18;
	int K; ll V,mn1[maxn*4],mn2[maxn*4],mn3[maxn*4],mn4[maxn*4];
	void build(int l,int r,int root) {
		if (l==r) {
			mn1[root]=V=-(ll)lx[l+1]*(ly[c2]-ly[1]);
			mn2[root]=V-(ll)ly[L[l]]*K;
			mn3[root]=V+(ll)(ly[R[l]]-ly[L[l]])*K;
			mn4[root]=V+(ll)ly[R[l]]*K;
			//printf("%d %lld %d %d\n",l,mn3[root],K,ly[L[l]]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		mn1[root]=min(mn1[root<<1],mn1[root<<1|1]);
		mn2[root]=min(mn2[root<<1],mn2[root<<1|1]);
		mn3[root]=min(mn3[root<<1],mn3[root<<1|1]);
		mn4[root]=min(mn4[root<<1],mn4[root<<1|1]);
	}
	ll query(int L,int R,int l,int r,int root,ll *tr) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1; ll res=INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1,tr);
		if (mid<R) chkmin(res,query(L,R,mid+1,r,root<<1|1,tr));
		return res;
	}
	ll query1(int l,int r,int R) { if (l>r) return INF; return query(l,r,1,c1,1,mn1)+(ll)R*K; }
	ll query2(int l,int r,int R) { if (l>r) return INF; return query(l,r,1,c1,1,mn2)+(ll)R*K; }
	ll query3(int l,int r) { if (l>r) return INF; return query(l,r,1,c1,1,mn3); }
	ll query4(int l,int r,int R) { if (l>r) return INF; return query(l,r,1,c1,1,mn4)-(ll)R*K; }
};
void solve2() {
	for (int i=1;i<=n+1;i++) g[i].clear();
	for (int i=1;i<=n;i++) g[X[i]].push_back(Y[i]);
	pre[0].init(),suf[c1+1].init();
	for (int i=1;i<=c1;i++) {
		pre[i]=pre[i-1];
		for (int &k : g[i]) pre[i]=insert(pre[i],k);
	}
	for (int i=c1;i>=1;i--) {
		suf[i]=suf[i+1];
		for (int &k : g[i]) suf[i]=insert(suf[i],k);
	}
	for (int i=1;i<c1;i++) chkmin(ans,(ll)(lx[i]-lx[1])*(ly[pre[i].mx]-ly[pre[i].mn])+(ll)(lx[c1]-lx[i+1])*(ly[suf[i+1].mx]-ly[suf[i+1].mn]));
	for (int i=1;i<=c1;i++) g[i].clear();
	for (int i=1;i<=n;i++) g[Y[i]].push_back(X[i]);
	pre[0].init(),suf[c2+1].init();
	for (int i=1;i<=c2;i++) {
		pre[i]=pre[i-1];
		for (int &k : g[i]) pre[i]=insert(pre[i],k);
	}
	for (int i=c2;i>=1;i--) {
		suf[i]=suf[i+1];
		for (int &k : g[i]) suf[i]=insert(suf[i],k);
	}
	for (int i=1;i<c2;i++) {
		chkmin(ans,(ll)(ly[i]-ly[1])*(lx[pre[i].mx]-lx[pre[i].mn])+(ll)(ly[c2]-ly[i+1])*(lx[suf[i+1].mx]-lx[suf[i+1].mn]));
	}
	for (int i=1;i<=c2;i++) g[i].clear();
	Solve();
	for (int i=1;i<=n;i++) X[i]=c1-X[i]+1; for (int i=1;i<=c1;i++) lx[i]*=-1; reverse(lx+1,lx+c1+1); Solve();
	for (int i=1;i<=n;i++) Y[i]=c2-Y[i]+1; for (int i=1;i<=c2;i++) ly[i]*=-1; reverse(ly+1,ly+c2+1); Solve();
	for (int i=1;i<=n;i++) X[i]=c1-X[i]+1; for (int i=1;i<=c1;i++) lx[i]*=-1; reverse(lx+1,lx+c1+1); Solve();
	for (int i=1;i<=n;i++) Y[i]=c2-Y[i]+1; for (int i=1;i<=c2;i++) ly[i]*=-1; reverse(ly+1,ly+c2+1);
	
	for (int i=1;i<=max(c1,c2)+1;i++) g[i].clear(),g2[i].clear();
	for (int i=1;i<=n;i++) g[X[i]].push_back(i),g2[Y[i]].push_back(i);
	for (int i=1;i<=c1;i++) {
		if (i==1) L[i]=1e9,R[i]=0;
		else L[i]=L[i-1],R[i]=R[i-1];
		for (int &k : g[i]) L[i]=min(L[i],Y[k]),R[i]=max(R[i],Y[k]);
	}
	Seg::K=lx[c1]-lx[1];
	Seg::build(1,c1,1);
	for (int i=1;i<=c1;i++) L[i]=-L[i];
	for (int j=c1,l=1e9,r=0;j>=2;j--) {
		for (int &k : g[j]) l=min(l,Y[k]),r=max(r,Y[k]);
		ll coef=(ll)lx[j-1]*(ly[c2]-ly[1]);
		int a=upper_bound(L+1,L+j-1,-l)-L-1;
		int b=upper_bound(R+1,R+j-1,r)-R-1;
		if (a<b) {
			chkmin(ans,Seg::query1(1,a,ly[r]-ly[l])+coef);
			chkmin(ans,Seg::query2(a+1,b,ly[r])+coef);
			chkmin(ans,Seg::query3(b+1,j-2)+coef);

		} else {
			chkmin(ans,Seg::query1(1,b,ly[r]-ly[l])+coef);
			chkmin(ans,Seg::query4(b+1,a,ly[l])+coef);
			chkmin(ans,Seg::query3(a+1,j-2)+coef);
		}
		//if (j==3) printf("%d %d %lld %d\n",a,b,Seg::query1(1,a,ly[r]-ly[l]),ly[r]);
	}
	/*for (int i=2;i<=c1;i++) for (int j=i;j<c1;j++) {
		Node tmp=Pre[i-1]+Suf[j+1];
		chkmin(ans,(ll)(lx[j]-lx[i])*(ly[c2]-ly[1])+(ll)(lx[tmp.y]-lx[tmp.x])*(ly[tmp.r]-ly[tmp.l]));
	}*/
}
int main() {
	//freopen("matrix.in","r",stdin);
	//freopen("matrix.out","w",stdout);
	int T;
	read(T);
	while (T--) {
		read(n); ans=3e18;
		c1=c2=0;
		for (int i=1;i<=n;i++) {
			read(X[i]),read(Y[i]);
			lx[++c1]=X[i],ly[++c2]=Y[i];
		}
		sort(lx+1,lx+c1+1),c1=unique(lx+1,lx+c1+1)-lx-1;
		sort(ly+1,ly+c2+1),c2=unique(ly+1,ly+c2+1)-ly-1;
		if (c1==1||c2==1) { puts("0"); continue; }
		for (int i=1;i<=n;i++) X[i]=lower_bound(lx+1,lx+c1+1,X[i])-lx,Y[i]=lower_bound(ly+1,ly+c2+1,Y[i])-ly;
		ans=(ll)(lx[c1]-lx[1])*(ly[c2]-ly[1]);
		/*if (n<=50) solve1();
		else*/ solve2();
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