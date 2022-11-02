#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int T,n,cnt;
int p[maxn],ans[maxn][maxn];
int G[maxn][maxn];
bool query(int x,int y) {
	//cnt++;
	//return G[x][y];
	x--,y--;
	printf("1 %d %d\n",x,y); fflush(stdout);
	int z; scanf("%d",&z);
	return z;
}
bool Query(int x,int y) {
	if (!y) return 0;
	printf("2 %d %d ",x-1,y);
	for (int i=1;i<=y;i++) printf("%d ",p[i]-1);
	puts("");
	fflush(stdout);
	int z; scanf("%d",&z);
	return z;
}
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		/*for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				if (rand()&1) G[i][j]=1,G[j][i]=0;
				else G[j][i]=1,G[i][j]=0;
			}
		}*/
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) ans[i][j]=1;
		if (query(1,2)) p[1]=1,p[2]=2;
		else p[1]=2,p[2]=1;
		for (int i=3;i<=n;i++) {
			int l=1,r=i-1,mid,res=0;
			while (l<=r) {
				mid=(l+r)>>1;
				if (query(p[mid],i)) res=mid,l=mid+1;
				else r=mid-1;
			}
			for (int j=i;j>=res+2;j--) p[j]=p[j-1];
			p[res+1]=i;
			//printf("%d\n",res);
			//for (int j=1;j<=n;j++) printf("%d ",p[j]-1); puts("");
		}
		//for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		//for (int i=1;i<n;i++) assert(G[p[i]][p[i+1]]);
		//printf("cnt=%d\n",cnt);
		int pos=n-1;
		for (int i=n;i>=1;i--) {
			if (pos==i) {
				for (int j=1;j<=i;j++) for (int k=i+1;k<=n;k++)
					ans[p[k]][p[j]]=0;
				pos--;
			}
			while (Query(p[i],pos)) pos--;
		}
		puts("3");
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++)
				if (ans[i][j]) putchar('1');
				else putchar('0');
			puts("");
		}
		fflush(stdout);
		int z; scanf("%d",&z);
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