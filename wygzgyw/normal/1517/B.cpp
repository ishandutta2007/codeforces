#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,n,m;
int b[110][110];
struct node {
	int v,x,y;
} d[100*100+10];
int tot,ans[110][110],mk[110][110],pos;
bool cmp(node A,node B) { return A.v<B.v; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m); tot=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				read(b[i][j]); mk[i][j]=ans[i][j]=0;
				d[++tot]=(node){b[i][j],i,j};
			}
		}
		sort(d+1,d+tot+1,cmp);
		for (int i=1;i<=m;i++) {
			ans[d[i].x][i]=d[i].v;
			mk[d[i].x][d[i].y]=1;
		}
		for (int i=1;i<=n;i++) {
			pos=1;
			for (int j=1;j<=m;j++) if (!mk[i][j]) {
				while (ans[i][pos]) pos++;
				ans[i][pos]=b[i][j];
			}
		}
		
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) printf("%d ",ans[i][j]);
			puts("");
		}
		
		
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