#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m,tot,ans;
int d[13][2010];
int dp[15][1<<13];
int g[1<<13][15][15],G[1<<13][15];
int f[15],mx[2010];
struct node { int x,y; } e[2010];
bool cmp(node a,node b) { return a.x>b.x; }
void update(int &x,int y) {
	if (x<=y) x=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	read(T);
	while (T--) {
		read(n); read(m); tot=ans=0;
		memset(mx,0,sizeof(mx));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			read(d[i][j]),update(mx[j],d[i][j]);
		for (int j=1;j<=m;j++) e[j]=(node){mx[j],j};
		sort(e+1,e+m+1,cmp);
		memset(dp,0,sizeof(dp));
		int msk,tmp;
		for (int t=0;t<(1<<n);t++)
		for (int J=0;J<min(n,m);J++) {
			G[t][J]=0;
			for (int i=0;i<n;i++) {
				int j=e[J+1].y;
				for (int k=1;k<=n;k++)
					if (k+i>n) f[k+i-n]=d[k][j];
					else f[k+i]=d[k][j];
				g[t][J][i]=0;
				for (int k=1;k<=n;k++)
					if (t&(1<<(k-1))) g[t][J][i]+=f[k];
				update(G[t][J],g[t][J][i]);
			}
		}
		for (int J=0;J<min(n,m);J++)
		for (int t=0;t<(1<<n);t++) {
			//for (int i=0;i<n;i++) {
				int j=e[J+1].y;
				/*for (int k=1;k<=n;k++)
					if (k+i>n) f[k+i-n]=d[k][j];
					else f[k+i]=d[k][j];*/
				msk=(1<<n)-1-t;
				for (int s=msk;;s=(s-1)&msk) {
					tmp=0;
					//for (int k=1;k<=n;k++)
					//if (s&(1<<(k-1))) tmp+=f[k];
					update(dp[J+1][t+s],dp[J][t]+G[s][J]);
					if (!s) break;
				}
			//}
		}
		printf("%d\n",dp[min(n,m)][(1<<n)-1]);
	}
	return 0;
}