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
const int maxn=(5e5)+10;
int n;
char s[maxn];
int d[maxn][3];
int Fa[12];
int find(int x) {
	if (Fa[x]==x) return x; return Fa[x]=find(Fa[x]);
}
vector<int> V={0,1,2,9,10,11};
struct node {
	int fa[6],L[4],R[4],cnt;
	void init(int x,int y,int z) {
		fa[0]=0,fa[1]=1,fa[2]=2;
		cnt=x+y+z;
		L[0]=R[0]=x,L[1]=R[1]=y,L[2]=R[2]=z;
		if (x&&y) fa[1]=0,cnt--;
		if (y&&z) fa[2]=fa[1],cnt--;
		fa[3]=fa[0],fa[4]=fa[1],fa[5]=fa[2];
	}
	friend node operator + (node A,node B) {
		node res;
		res.L[0]=A.L[0],res.L[1]=A.L[1],res.L[2]=A.L[2];
		res.R[0]=B.R[0],res.R[1]=B.R[1],res.R[2]=B.R[2];
		res.cnt=A.cnt+B.cnt;
		for (int i=0;i<6;i++) Fa[i]=A.fa[i];
		for (int i=0;i<6;i++) Fa[i+6]=B.fa[i]+6;
		//for (int i=0;i<3;i++) printf("%d ",A.L[i]); puts("");
		//for (int i=0;i<3;i++) printf("%d ",B.L[i]); puts("");
		//for (int i=0;i<12;i++) printf("%d ",Fa[i]); puts("");
		for (int i=0;i<3;i++) {
			if (A.R[i]&&B.L[i]) {
				int x=find(Fa[i+3]),y=find(Fa[i+6]);
				//printf("%d %d\n",x,y);
				if (x!=y) Fa[x]=y,res.cnt--;
			}
		}
		//assert(res.cnt>=0);
		for (int i=0;i<6;i++) {
			res.fa[i]=i;
			for (int j=0;j<i;j++) if (find(V[j])==find(V[i])) { res.fa[i]=j; break; }
		}
		return res;
	}
} tr[maxn*4],res;
int flag;
void build(int l,int r,int root) {
	if (l==r) {
		tr[root].init(d[l][0],d[l][1],d[l][2]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=(tr[root<<1]+tr[root<<1|1]);
	
}
void query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) { if (!flag) res=tr[root]; else res=res+tr[root]; flag=1; return; }
	int mid=(l+r)>>1;
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=0;i<=2;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=n;j++) d[j][i]=s[j]-'0';
	}
	build(1,n,1);
	int q;
	read(q);
	while (q--) {
		flag=0;
		int l,r; read(l),read(r);
		query(l,r,1,n,1);
		printf("%d\n",res.cnt);
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