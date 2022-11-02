#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
int n,m,k,ans,mx,l,r,x,y;
char s[25],t[25];
int p[25],f[2][1<<20],bit[1<<20];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(k);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (int i=1;i<=k;i++) p[i]=i;
	for (int i=0;i<(1<<k);i++) {
		f[0][i]=INF,f[1][i]=-INF;
		if (i) bit[i]=bit[i-(i&(-i))]+1;
	}
	int u=0,v=0;
	for (int i=1;i<=k;i++) {
		if (s[i]=='1') u+=(1<<(i-1));
		if (t[i]=='1') v+=(1<<(i-1));
	}
	ans=k-bit[u]-bit[v];
	f[0][u]=f[1][v]=0;
	for (int i=1;i<=n;i++) {
		read(x),read(y); swap(p[x],p[y]);
		u=v=0;
		for (int i=1;i<=k;i++) {
			if (s[i]=='1') u+=(1<<(p[i]-1));
			if (t[i]=='1') v+=(1<<(p[i]-1));
		}
		f[0][u]=min(f[0][u],i);
		f[1][v]=max(f[1][v],i);
		//printf("%d %d\n",u,v);
	}
	mx=-1;
	for (int i=(1<<k)-1;i>=0;i--) {
		for (int j=0;j<k;j++) if (i&(1<<j)) {
			f[0][i-(1<<j)]=min(f[0][i-(1<<j)],f[0][i]);
			f[1][i-(1<<j)]=max(f[1][i-(1<<j)],f[1][i]);
		}
		if (f[1][i]-f[0][i]>=m&&mx<bit[i]) {
			mx=bit[i],l=f[0][i]+1,r=f[1][i];
		}
	}
	printf("%d\n%d %d\n",2*mx+ans,l,r);
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