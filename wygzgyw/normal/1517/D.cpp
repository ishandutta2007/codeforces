#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=0x7f7f7f7f;
const int maxn=(1e5)+10;
int n,m,K;
int dis[15][510][510],ans;
void update(int &x,int y) { if (x>y) x=y; }
int a[510][510],b[510][510],op;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(K);
	if (K&1) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) printf("-1 ");
			puts("");
		} return 0;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<m;j++) read(a[i][j]);
	for (int i=1;i<n;i++) for (int j=1;j<=m;j++) read(b[i][j]);
	K/=2;
	memset(dis,INF,sizeof(dis));
	for (int t=-1;t<K;t++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (t==-1) { dis[0][i][j]=0; continue; }
				if (i>1) update(dis[t+1][i-1][j],dis[t][i][j]+b[i-1][j]);
				if (j>1) update(dis[t+1][i][j-1],dis[t][i][j]+a[i][j-1]);
				if (i<n) update(dis[t+1][i+1][j],dis[t][i][j]+b[i][j]);
				if (j<m) update(dis[t+1][i][j+1],dis[t][i][j]+a[i][j]);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) printf("%d ",dis[K][i][j]*2);
		puts("");
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