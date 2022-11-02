#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int n,m,pre[60],k;
ll a[60],b[60],c[60],f[60][60][60][4][4];
int in(ll t,int i) { return (t>>i)&1; }
void update(ll &x,ll y) { if (x>y) x=y; }
int get(int i,int p) {
	if (p==0) return in(a[i],k);
	if (p==1) return in(a[i],k)^1;
	if (p==2) return in(b[i],k);
	if (p==3) return in(b[i],k)^1;
}
ll cost(int l,int r,int k1,int k2) {
	if (l<1||r>n) return 0;
	//printf("%d %d %d %d %d %d\n",l,r,k1,k2,get(l,k1),get(r,k2));
	return c[k]*(get(l,k1)!=get(r,k2));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	memset(pre,-1,sizeof(pre));
	for (int i=1;i<=n;i++) {
		read(a[i]),read(b[i]);
		for (int j=m-1;j>=0;j--)
			if ((a[i]>>j)<(b[i]>>j)) { pre[i]=j; break; }
	}
	for (int i=0;i<m;i++) read(c[i]);
	
	for (int i=0;i<=m+1;i++)
	for (int j=0;j<=n+1;j++)
	for (int k=0;k<=n+1;k++)
	for (int k1=0;k1<=3;k1++)
	for (int k2=0;k2<=3;k2++) f[i][j][k][k1][k2]=INF;
	
	for (int i=0;i<=n;i++)
	for (int j=0;j<=2;j+=2)
	for (int k=0;k<=2;k+=2) f[m][i][i+1][j][k]=0;
	
	for (k=m-1;k>=0;k--) {
		for (int i=0;i<=n;i++) for (int j=i+1;j<=n+1;j++)
		for (int k1=0;k1<=2;k1+=2) for (int k2=0;k2<=2;k2+=2) if (f[k+1][i][j][k1][k2]<INF) {
			for (int k3=0;k3<2;k3++) if (!k3||k<pre[i]) {
				if (k3&&k1==0&&in(a[i],k)) continue;
				if (k3&&k1==2&&!in(b[i],k)) continue;
				for (int k4=0;k4<2;k4++) if (!k4||k<pre[j]) {
					if (k4&&k2==0&&in(a[j],k)) continue;
					if (k4&&k2==2&&!in(b[j],k)) continue;
					update(f[k][i][j][k1+k3][k2+k4],f[k+1][i][j][k1][k2]+cost(i,j,k1+k3,k2+k4));
				//	printf("HI %lld %d %d %d\n",f[k][i][j][k1+k3][k2+k4],k,i,j);
				}
			}
		}
		for (int len=2;len<=n+1;len++) for (int i=0,j;i+len<=n+1;i++) {
			j=i+len;
			if (k) {
				for (int mid=i+1;mid<j;mid++) for (int k1=0;k1<4;k1++) for (int k2=0;k2<4;k2++)
					for (int t=1;t<=3;t+=2) {
						update(f[k][i][j][k1][k2],f[k][i][mid][k1][t]+f[k][mid][j][t][k2]);
					}
			} else {
				for (int mid=i+1;mid<j;mid++) for (int k1=0;k1<4;k1++) for (int k2=0;k2<4;k2++)
					for (int t=0;t<4;t++) {
						update(f[k][i][j][k1][k2],f[k][i][mid][k1][t]+f[k][mid][j][t][k2]);
					}
			}
		}
	}
	ll ans=INF;
	for (int i=0;i<4;i++) for (int j=0;j<4;j++)
		update(ans,f[0][0][n+1][i][j]);
	printf("%lld\n",ans);
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