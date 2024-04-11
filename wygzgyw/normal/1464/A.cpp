#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int T,n,m,to[maxn],in[maxn],ans;
bool vis[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T); int x,y;
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) to[i]=vis[i]=in[i]=0;
		for (int i=1;i<=m;i++) read(x),read(y),to[x]=y,in[y]=1;
		ans=m;
		for (int i=1;i<=n;i++) if (to[i]==i) ans--;
		for (int i=1;i<=n;i++) if (!vis[i]&&to[i]!=i) {
			x=i;
			while (1) {
				if (vis[x]) break;
				vis[x]=1;
				if (!to[x]) break;
				x=to[x];
				if (x==i) {
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/