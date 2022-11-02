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
int n,q,p[maxn];
ll tmp[maxn],s[maxn],ans,delta[maxn];
int tot,cyc[maxn],bel[maxn];
struct node { int op,x,y; } Q[maxn];
bool mk[maxn],vis[maxn]; int to[maxn];
vector<int> G[maxn];
void solve(int l,int r) {
	for (int i=1;i<=n;i++) delta[i]=mk[i]=vis[i]=bel[i]=0,G[i].clear();
	for (int i=l;i<=r;i++) if (Q[i].op==2) mk[Q[i].x]=1; else if (Q[i].op==3) mk[Q[i].x]=mk[Q[i].y]=1;
	vector<int> A;
	for (int i=1;i<=n;i++) if (mk[i]) A.push_back(i);
	for (int i=1;i<=n;i++) if (!vis[i]) {
		int x=i; tot=0;
		while (1) {
			x=p[x]; cyc[++tot]=x; vis[x]=1; if (x==i) break;
		}
		x=-1; for (int j=1;j<=tot;j++) if (mk[cyc[j]]) { x=cyc[j]; break; }
		if (x==-1) continue;
		for (int j=tot;j>=1;j--) {
			if (mk[cyc[j]]) to[cyc[j]]=x,x=cyc[j];
			bel[cyc[j]]=x;
		}
	}
	for (int i=1;i<=n;i++) if (bel[i]) G[bel[i]].push_back(i);
	for (int i=l;i<=r;i++) {
		int x=Q[i].x,y=Q[i].y;
		if (Q[i].op==1) {
			ans=s[y]-s[x-1];
			for (int &j : A) {
				ans+=(ll)delta[j]*(upper_bound(G[j].begin(),G[j].end(),y)-lower_bound(G[j].begin(),G[j].end(),x));
			}
			printf("%lld\n",ans);
		} else if (Q[i].op==2) {
			while (1) {
				x=to[x]; delta[x]+=y;
				if (x==Q[i].x) break;
			}
		} else {
			swap(to[x],to[y]),swap(p[x],p[y]);
		}
	}
	for (int i=1;i<=n;i++) {
		tmp[i]=(bel[i]?delta[bel[i]]:0)+tmp[i-1];
		s[i]+=tmp[i];
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(s[i]),s[i]+=s[i-1];
	for (int i=1;i<=n;i++) read(p[i]);
	read(q);
	for (int i=1;i<=q;i++) read(Q[i].op),read(Q[i].x),read(Q[i].y);
	int block=sqrt(q*1.0);
	for (int i=1,j;i<=q;i=j+1) {
		j=min(q,i+block-1);
		solve(i,j);
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