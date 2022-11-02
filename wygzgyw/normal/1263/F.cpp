#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=2010;
int n,dp[maxn];
struct Tree {
	int a,fa[maxn],cnt[maxn][maxn];
	int dy[maxn],son[maxn];
	void init() {
		read(a); int x;
		for (int i=2;i<=a;i++) read(fa[i]);
		for (int i=1;i<=n;i++) read(dy[i]);
		for (int l=1;l<=n;l++) {
			memset(son,0,sizeof(son));
			for (int i=1;i<=a;i++) son[fa[i]]++;
			for (int r=l;r<=n;r++) {
				x=dy[r];
				cnt[l][r]=cnt[l][r-1];
				while (x!=1&&!son[x]) {
					x=fa[x]; son[x]--;
					cnt[l][r]++;
				}
			//	printf("%d %d %d\n",l,r,cnt[l][r]);
			}
		}
	}
} A,B;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	A.init();
	B.init();
	for (int i=1;i<=n;i++)
	for (int j=0;j<i;j++)
		dp[i]=max(dp[i],dp[j]+max(A.cnt[j+1][i],B.cnt[j+1][i]));
	printf("%d\n",dp[n]);
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