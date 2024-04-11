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
int n,q; ll ans[1000010];
int st[maxn],tot,L[maxn],R[maxn],p[maxn],bk[maxn];
struct node {
	int l,r,id;
	friend bool operator < (node A,node B) { return A.l>B.l; }
} Q[1000010];
vector<node> ev[maxn];
void add(int x,int y,int l,int r) {
	//printf("%d %d %d %d\n",x,y,l,r);
	if (x>y||l>r) return;
	ev[x-1].push_back((node){l,r,-1}),ev[y].push_back((node){l,r,1});
}
struct BIT {
	ll tr[maxn];
	void add(int x,ll delta) { for (;x<=n;x+=x&(-x)) tr[x]+=delta; }
	ll query(int x) { ll res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
	void add(int l,int r,ll delta) { add(l,delta),add(r+1,-delta); }
} T1,T2,T3,T4;
vector<pair<int,int> > vec[maxn];
int suf[maxn];
void insert(int l,int pos,int delta) {
	T1.add(l,pos*delta);
	T2.add(l,delta);
	T3.add(l,(ll)l*pos*delta);
	T4.add(l,l*delta);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(p[i]),bk[p[i]]=i;
	for (int i=1;i<=n;i++) {
		while (tot&&p[st[tot]]<p[i]) tot--;
		L[i]=st[tot]+1; st[++tot]=i;
	}
	st[0]=n+1; tot=0;
	for (int i=n;i>=1;i--) {
		while (tot&&p[st[tot]]<p[i]) tot--;
		R[i]=st[tot]-1; st[++tot]=i;
	}
//	for (int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
	for (int i=1;i<=n;i++) {
		int x=p[i];
		for (int j=x;j<=n;j+=x) {
			int y=j/x;
			if (x==y) continue;
			int z=bk[j];
			if (L[z]<=i&&i<=R[z]&&L[z]<=bk[y]&&bk[y]<=R[z]); else continue;
			if (i>bk[y]) continue;
			if (L[z]<=i&&i<=z&&z<=bk[y]&&bk[y]<=R[z]) {
				vec[z].push_back(MP(i,bk[y]));
			} else if (bk[y]<z) vec[z].push_back(MP(i,z));//,printf("> %d %d\n",i,z);
			else if (i>z) vec[z].push_back(MP(z,bk[y]));
		}
	}
	for (int i=1;i<=n;i++) {
		sort(vec[i].begin(),vec[i].end());
		int sz=(int)vec[i].size();
		for (int j=sz-1;j>=0;j--) suf[j]=min(j==sz-1?n+1:suf[j+1],vec[i][j].second);
		int lst=L[i];
		/*if (i==8) {
			for (int j=0;j<sz;j++) printf("%d %d\n",vec[i][j].first,vec[i][j].second);
		}*/
		for (int j=0;j<sz;j++) add(lst,vec[i][j].first,suf[j],R[i]),lst=vec[i][j].first+1;
	}
	for (int i=1;i<=q;i++) read(Q[i].l),read(Q[i].r),Q[i].id=i;
	sort(Q+1,Q+q+1);
	int pos=n;
	for (int i=1;i<=q;i++) {
		while (pos>=Q[i].l) {
			for (node &A : ev[pos]) {
				insert(A.l,pos,A.id);
				insert(A.r+1,pos,-A.id);
			}
			pos--;
		}
		int L=Q[i].l,R=Q[i].r;
		ans[Q[i].id]=T1.query(R)*(R+1)-T2.query(R)*(R+1)*(L-1)-T3.query(R)+T4.query(R)*(L-1);
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