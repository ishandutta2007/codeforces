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
const int maxn=110;
int T,n;
int tot;
bitset<110> ans[maxn];
char s[maxn];
vector<int> g[maxn];
int in[maxn],hd,tl,q[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) in[i]=0,g[i].clear();
		for (int i=1;i<=n;i++) ans[i].reset(); tot=0;
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for (int j=1;j<=n;j++) if (s[j]=='1') {
				g[i].push_back(j),in[j]++;
			}
		}
		hd=1,tl=0;
		for (int i=1;i<=n;i++) if (!in[i]) q[++tl]=i;
		while (hd<=tl) {
			int x=q[hd]; hd++;
			ans[x].set(++tot);
			for (int &y : g[x]) {
				in[y]--;
				ans[y]|=ans[x];
				if (!in[y]) q[++tl]=y;
			}
		}
		for (int i=1;i<=n;i++) {
			printf("%d ",(int)ans[i].count());
			for (int j=1;j<=n;j++) if (ans[i].test(j)) printf("%d ",j); puts("");
		}
	}
	return 0;
}