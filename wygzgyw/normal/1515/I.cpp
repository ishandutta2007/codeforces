#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=5e18;
const int maxn=(2e5)+10;
const int lg=18;
int n,q;
ll a[maxn],w[maxn],v[maxn];
int p[maxn],pos[maxn],r[maxn];
bool cmp(int x,int y) {
	if (v[x]==v[y]) return w[x]<w[y];
	return v[x]>v[y];
}
struct Seg1 {
	ll sumw[maxn*4],sumv[maxn*4];
	void pushup(int root) {
		sumw[root]=sumw[root<<1]+sumw[root<<1|1];
		sumv[root]=sumv[root<<1]+sumv[root<<1|1];
	}
	void add(int x,int l,int r,int root,ll delta) {
		if (l==r) {
			sumw[root]+=delta*w[p[l]];
			sumv[root]+=delta*v[p[l]];
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
		pushup(root);
	}
	int find(int L,int R,int l,int r,int root,ll &z,ll &ans) {
		if (L>R) return 0;
		if (L<=l&&r<=R&&sumw[root]<=z) {
		//	printf("HI %d\n",root);
			z-=sumw[root],ans+=sumv[root]; return R+1;
		}
		if (l==r) return l;
		int mid=(l+r)>>1,res;
		if (L<=mid) {
			res=find(L,R,l,mid,root<<1,z,ans);
			if (res<=R) return res;
		}
		if (mid<R) return find(L,R,mid+1,r,root<<1|1,z,ans);
		return R+1;
	}
	ll query(int L,int R,int l,int r,int root) {
		if (L>R) return 0;
		if (L<=l&&r<=R) return sumw[root];
		int mid=(l+r)>>1; ll res=0;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res+=query(L,R,mid+1,r,root<<1|1);
		return res;
	}
} T1[20];
struct Seg2 {
	ll mn[maxn*4],lazy[maxn*4];
	void puttag(int root,ll delta) { mn[root]+=delta,lazy[root]+=delta; }
	void pushdown(int root) {
		if (!lazy[root]) return;
		puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]); lazy[root]=0;
	}
	void pushup(int root) { mn[root]=min(mn[root<<1],mn[root<<1|1]); }
	void change(int x,int l,int r,int root,ll delta) {
	//	if (root==1) printf("change %d %lld\n",x,delta);
		if (l==r) { mn[root]=delta; return; }
		int mid=(l+r)>>1; pushdown(root);
		if (x<=mid) change(x,l,mid,root<<1,delta);
		else change(x,mid+1,r,root<<1|1,delta);
		pushup(root);
	}
	void add(int L,int R,int l,int r,int root,ll delta) {
		if (L>R) return;
		if (L<=l&&r<=R) { puttag(root,delta); return; }
		int mid=(l+r)>>1;
		pushdown(root);
		if (L<=mid) add(L,R,l,mid,root<<1,delta);
		if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
		pushup(root);
	}
	int find(int L,int R,int l,int r,int root,ll delta) {
		//printf("find %d %d %d %d %lld %lld\n",L,R,l,r,delta,mn[1]);
		if (L<=l&&r<=R&&mn[root]>delta) return R+1;
		if (l==r) return l;
		pushdown(root);
		int mid=(l+r)>>1;
		int res;
		if (L<=mid) {
			res=find(L,R,l,mid,root<<1,delta);
			if (res<=R) return res;
		}
		if (mid<R) return find(L,R,mid+1,r,root<<1|1,delta);
		return R+1;
	}
} T2[20];
void init(int id) {
	for (int i=1;i<=n;i++) if (w[i]<(1<<id)) T1[id].add(pos[i],1,n,1,a[i]);
	//if (id==2) puts("--");
	for (int i=1;i<=n;i++)
		if (r[i]!=id||!a[i]) T2[id].change(pos[i],1,n,1,INF);
		else T2[id].change(pos[i],1,n,1,w[i]+T1[id].query(1,pos[i]-1,1,n,1));
	//if (id==2) puts("--");
}
void add(int x,ll y) {
	for (int i=0;i<lg;i++) if (w[x]<(1<<i)) {
		T1[i].add(pos[x],1,n,1,y);
		//if (i==2) printf("??? %d\n",
		T2[i].add(pos[x]+1,n,1,n,1,y*w[x]);
	}
	if (!a[x]) T2[r[x]].change(pos[x],1,n,1,w[x]+T1[r[x]].query(1,pos[x]-1,1,n,1));
	a[x]+=y;
	if (!a[x]) T2[r[x]].change(pos[x],1,n,1,INF);
}
ll ans;
void query(ll z) {
	ans=0;
	int now=1,nxt; ll tmp;
	for (int i=lg-1;i>=0;i--) if (z>=(1<<i)) {
		ll val=z-(1<<i);
		//printf("now=%d\n",now);
		//printf("%lld, %d\n",T1[i].query(1,now-1,1,n,1),i);
		nxt=T2[i].find(now,n,1,n,1,z+T1[i].query(1,now-1,1,n,1));
		if (nxt>now) now=T1[i].find(now,nxt-1,1,n,1,val,ans);
		//printf("%d %d %lld\n",now,nxt,ans);
		z=val+(1<<i);
		if (now<=n) {
			tmp=min(a[p[now]],z/w[p[now]]);
			ans+=tmp*v[p[now]];
			z-=tmp*w[p[now]];
			now++;
		}
		if (now>n) break;
	}
	printf("%lld\n",ans);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) {
		read(a[i]),read(w[i]),read(v[i]);
		while (w[i]>=(1<<(r[i]+1))) r[i]++;
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++) pos[p[i]]=i;
	for (int i=0;i<lg;i++) init(i);
	//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
	// 3 1 2
	int op,x,y; ll z;
	while (q--) {
		read(op);
		if (op<=2) {
			read(y),read(x);
			if (op==1) add(x,y); else add(x,-y);
		}
		else {
			read(z),query(z);
			//exit(0);
		}
//		exit(0);
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