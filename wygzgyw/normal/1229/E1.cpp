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
typedef long long ll;
const int mod=(1e9)+7;
int n,p[10][10];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int f[1<<20];
struct node { int x,y,z; } d[30],e[30];
int t1,t2,ans,D[10][10];
int P[20],num[1<<6],bit[1<<6],rem[1000],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int m=n/2;
	int iv100=ksm(100,mod-2);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		read(p[i][j]),p[i][j]=(ll)p[i][j]*iv100%mod;
		if (i<=m) d[++t1]=(node){i,j,p[i][j]};
		else e[++t2]=(node){i,j,p[i][j]};
	}
	if (n==1) { printf("%d\n",p[1][1]); return 0; }
	for (int t=1;t<(1<<n);t++) {
		bit[t]=bit[t-(t&(-t))]+1;
		if (bit[t]==m) num[t]=++tot,rem[tot]=t;
	}
	int l=1,r=m;
	for (int t=0;t<(1<<t1);t++) {
		int tmp=1;
		for (int i=1;i<=t1;i++) if (t>>(i-1)&1) {
			D[d[i].x][d[i].y]=1; tmp=(ll)tmp*d[i].z%mod;
		} else tmp=(ll)tmp*(mod+1-d[i].z)%mod;
		int msk=0;
		for (int i=1;i<=tot;i++) {
			vector<int> V; int fd=0;
			for (int j=1;j<=n;j++) if (rem[i]>>(j-1)&1) V.push_back(j);
			for (int j=l;j<=r;j++) P[j]=j;
			do {
				int flag=1;
				for (int j=l,now=0;j<=r&&flag;j++) flag&=D[P[j]][V[now++]];
				if (flag) {
					fd=1; break;
				}
			} while (next_permutation(P+l,P+r+1));
			if (fd) msk|=(1<<(i-1));
		}
		for (int i=1;i<=t1;i++) if (t>>(i-1)&1) D[d[i].x][d[i].y]=0;
		update(f[msk],tmp);
		//printf("%d %d\n",t,msk);
	}
	for (int i=0;i<tot;i++)
	for (int j=0;j<(1<<tot);j++) if (j>>i&1) update(f[j],f[j-(1<<i)]);
	l=m+1,r=n;
	for (int t=0;t<(1<<t2);t++) {
		int tmp=1;
		for (int i=1;i<=t2;i++) if (t>>(i-1)&1) {
			D[e[i].x][e[i].y]=1; tmp=(ll)tmp*e[i].z%mod;
		} else tmp=(ll)tmp*(mod+1-e[i].z)%mod;
		int msk=0;
		for (int i=1;i<=tot;i++) {
			vector<int> V; int fd=0;
			for (int j=1;j<=n;j++) if (((1<<n)-1-rem[i])>>(j-1)&1) V.push_back(j);
			for (int j=l;j<=r;j++) P[j]=j;
			do {
				int flag=1;
				for (int j=l,now=0;j<=r&&flag;j++) flag&=D[P[j]][V[now++]];
				if (flag) {
					fd=1; break;
				}
			} while (next_permutation(P+l,P+r+1));
			if (fd) msk|=(1<<(i-1));
		}
		for (int i=1;i<=t2;i++) if (t>>(i-1)&1) D[e[i].x][e[i].y]=0;
		int tmp2=(f[(1<<tot)-1]-f[(1<<tot)-1-msk]+mod)%mod;
		update(ans,(ll)tmp2*tmp%mod);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/