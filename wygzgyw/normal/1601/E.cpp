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
const int maxn=(3e5)+10;
const int INF=0x7f7f7f7f;
int n,lg[maxn],q,k;
int st[maxn][20],top;
pair<int,int> s[maxn];
ll ans[maxn]; int a[maxn],cnt;
struct node { int l,r,id,a; };
vector<node> Q[maxn];
int query(int l,int r) {
	l=max(l,1),r=min(r,n);
	if (l>r) return INF;
	int j=lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
int nxt[maxn],f[maxn][20]; ll g[maxn][20];
bool cmp(node A,node B) { return A.l>B.l; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q),read(k);
	for (int i=1;i<=n;i++) read(st[i][0]);
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++) st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	int l,r;
	for (int i=1;i<=q;i++) {
		read(l),read(r);
		Q[l%k].push_back((node){l,r,i,st[l][0]});
	}
	for (int i=0;i<k;i++) if ((int)Q[i].size()) {
		//printf("i=%d\n",i);
		sort(Q[i].begin(),Q[i].end(),cmp); cnt=0;
		for (int j=0;j*k+i-k+1<=n;j++) {
			a[j]=query(j*k+i-k+1,j*k+i); cnt=j;
		}
	//	for (int j=0;j<=cnt;j++) printf("%d ",a[j]); puts("");
		top=0;
		int now=0;
		for (int j=cnt;j>=0;j--) {
			while (now<(int)Q[i].size()) {
				node &A=Q[i][now];
				if (A.l/k!=j) break;
				A.l=A.l/k,A.r=(A.r-i)/k+1;
				while (top&&s[top].first>=A.a) top--;
				ans[A.id]+=(ll)A.a*(min(top?s[top].second:cnt+1,A.r)-A.l);
				A.l=top?s[top].second:cnt+1;
				now++;
			}
			while (top&&s[top].first>=a[j]) top--;
			nxt[j]=top?s[top].second:cnt+1;
			s[++top]=MP(a[j],j);
		}
		//for (int i=0;i<=cnt;i++) printf("%d ",nxt[i]); puts("");
		f[cnt+1][0]=cnt+1,g[cnt+1][0]=0;
		for (int i=0;i<=cnt;i++) f[i][0]=nxt[i],g[i][0]=(ll)(nxt[i]-i)*a[i];
		for (int i=1;i<=19;i++) for (int j=0;j<=cnt+1;j++)
			f[j][i]=f[f[j][i-1]][i-1],g[j][i]=g[j][i-1]+g[f[j][i-1]][i-1];
		for (node &A : Q[i]) {
			l=A.l,r=A.r;
		//	printf(" %d %d\n",l,r);
			for (int i=19;i>=0;i--) if (f[l][i]<r) ans[A.id]+=g[l][i],l=f[l][i];
			if (l<r) ans[A.id]+=(ll)(r-l)*a[l];
		}
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