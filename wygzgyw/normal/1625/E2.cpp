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
int n,q,mat[maxn];
char s[maxn];
int top,st[maxn];
int fa[maxn],dep[maxn];
ll C2(ll x) { return x*(x+1)/2; }
struct BIT {
vector<ll> tr; int sz;
void init(int _sz) { sz=_sz+1; tr.resize(sz+4); }
void add(int x,ll delta) { x++; for (;x<=sz;x+=x&(-x)) tr[x]+=delta; }
ll query(int x) {
	x++;
	ll res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
}
ll query(int l,int r) { if (l>r) return 0; return query(r)-query(l-1); }
} cnt[maxn],T;
vector<int> g[maxn]; int pos[maxn];
ll query(int x,int l,int r) { return C2(cnt[x].query(l,r)); }
int main() {
	read(n),read(q);
	scanf("%s",s+1);
	int mx=0;
	for (int i=1;i<=n;i++) if (s[i]=='(') st[++top]=i;
	else if (top) {
		int j=st[top]; top--;
		mat[i]=j,mat[j]=i;
		dep[i]=dep[j]=top+1;
		mx=max(mx,dep[i]);
		if (dep[i]!=1) {
			if (s[j-1]=='(') fa[i]=fa[j]=j-1; else fa[i]=fa[j]=fa[j-1];
		}
		pos[i]=pos[j]=(int)g[dep[i]].size(); g[dep[i]].push_back(i);
	}
	T.init(n);
	for (int i=mx;i>=1;i--) {
		cnt[i].init((int)g[i].size());
		for (int j=0;j<g[i].size();j++) {
			int r=g[i][j],l=mat[r];
			if (l+1<=r-1) T.add(l,query(i+1,pos[l+1],pos[r-1]));
			cnt[i].add(j,1);
		}
	}
	int op,l,r;
	while (q--) {
		read(op),read(l),read(r);
		if (op==1) {
			cnt[dep[l]].add(pos[l],-1);
			int x=fa[l],y=mat[x];
			if (x&&y&&x+1<=y-1) {
				int k=cnt[dep[x]+1].query(pos[x+1],pos[y-1]); T.add(x,C2(k)-C2(k+1));
			}
		} else {
			printf("%lld\n",T.query(l,r)+query(dep[l],pos[l],pos[r]));
		}
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