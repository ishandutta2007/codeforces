#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}

int T,n,m,tot,a[110][110],b[3][3],N,M;
char s[110];
struct node { int x1,y1,x2,y2,x3,y3; } ans[10010];
void solve(node A) {
	a[A.x1][A.y1]^=1,a[A.x2][A.y2]^=1,a[A.x3][A.y3]^=1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m); tot=0;
		N=n,M=m;
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for (int j=1;j<=m;j++) a[i][j]=s[j]-'0';
		}
		while (n>2) {
			for (int j=1;j<=m;j++)
				if (a[n][j]) {
					ans[++tot]=(node){n,j,n-1,j,n-1,(j==1?j+1:j-1)};
					solve(ans[tot]);
				}
			n--;
		}
		while (m>2) {
			for (int j=1;j<=n;j++)
				if (a[j][m]) {
					ans[++tot]=(node){j,m,j,m-1,(j==1?j+1:j-1),m-1};
					solve(ans[tot]);
				}
			m--;
		}
		for (int t=0;t<(1<<4);t++) {
			for (int i=1;i<=2;i++) for (int j=1;j<=2;j++) b[i][j]=a[i][j];
			for (int i=0;i<4;i++) if (t&(1<<i)) {
				for (int j=1;j<=2;j++) for (int k=1;k<=2;k++)
					if ((j-1)*2+k-1!=i) b[j][k]^=1;
			}
			int flag=1;
			for (int i=1;i<=2&&flag;i++) for (int j=1;j<=2;j++) if (b[i][j]) { flag=0; break; }
			if (flag) {
				for (int i=0;i<4;i++) if (t&(1<<i)) {
					tot++; ans[tot].x1=ans[tot].y1=ans[tot].x2=ans[tot].y2=ans[tot].x3=ans[tot].y3=0;
					for (int j=1;j<=2;j++) for (int k=1;k<=2;k++)
						if ((j-1)*2+k-1!=i) {
							if (ans[tot].x2) ans[tot].x3=j,ans[tot].y3=k;
							else if (ans[tot].x1) ans[tot].x2=j,ans[tot].y2=k;
							else ans[tot].x1=j,ans[tot].y1=k;
						}
					solve(ans[tot]);
				}
				break;
			}
		}
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++) printf("%d %d %d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2,ans[i].x3,ans[i].y3);
		for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) assert(a[i][j]==0);
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