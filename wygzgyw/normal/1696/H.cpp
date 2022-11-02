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
const int maxn=610;
int n,k;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int mi[maxn],d[maxn],e[maxn],t1,t2,ans;
int A[maxn][maxn],B[maxn][maxn];
int C[maxn],D[maxn],E[maxn][maxn];
struct node {
	ll val; int op,x,y;
	friend bool operator < (node A,node B) { return A.val<B.val; }
};
vector<node> V;
int buc[maxn];
int main() {
	read(n),read(k);
	for (int i=1;i<=n;i++) {
		int x; read(x);
		if (x>=0) d[++t1]=x; else e[++t2]=x;
	}
	mi[0]=1; for (int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	sort(d+1,d+t1+1),reverse(d+1,d+t1+1),sort(e+1,e+t2+1);
	A[0][0]=1,B[0][0]=1;
	for (int i=1;i<=t1;i++) {
		for (int j=0;j<i;j++) update(A[i][j],A[i-1][j]),update(A[i][j+1],(ll)A[i-1][j]*d[i]%mod);
	}
	for (int i=1;i<=t2;i++) {
		for (int j=0;j<i;j++) update(B[i][j],B[i-1][j]),update(B[i][j+1],(ll)B[i-1][j]*(mod+e[i])%mod);
	}
	for (int x=1;x<k;x+=2) {
		update(ans,(ll)A[t1][k-x]*B[t2][x]%mod);
	}
	if (k&1) {
		E[0][0]=1;
		for (int i=1;i<=t2;i++) {
			for (int j=0;j<i;j++) update(E[i][j],E[i-1][j]),update(E[i][j+1],(ll)E[i-1][j]*(mod+e[t2-i+1])%mod);
		}
		for (int x=1;x<=t2;x++) {
			update(ans,(ll)E[x-1][k-1]*(mod+e[t2-x+1])%mod*mi[t2-x]%mod);
		}
	}
	C[0]=mi[t1],D[0]=mi[t2];
	for (int c=1;c<=t1;c++) for (int x=1;x<=t1;x++) {
		update(C[c],(ll)A[x-1][c-1]*d[x]%mod*mi[t1-x]%mod);
	}
	for (int c=1;c<=t2;c++) for (int x=1;x<=t2;x++) {
		update(D[c],(ll)B[x-1][c-1]*(mod+e[x])%mod*mi[t2-x]%mod);
	}
	for (int x=0;x<=k;x+=2) {
		update(ans,(ll)C[k-x]*D[x]%mod);
	}
	//printf("%d\n",ans);
	for (int x=1;x<=t1;x++) for (int y=x+1;y<=t1;y++)
		V.push_back((node){(ll)d[x]*d[y],0,x,y});
	for (int x=1;x<=t2;x++) for (int y=x+1;y<=t2;y++)
		V.push_back((node){(ll)e[x]*e[y],1,x,y});
	sort(V.begin(),V.end());
	for (node &tmp : V) {
		if (!tmp.op) {
			for (int x=0;x+2<=k;x+=2) {
				update(buc[x],(ll)tmp.val%mod*A[tmp.x-1][k-x-2]%mod*mi[t1-tmp.y]%mod);
			}
		} else {
			for (int x=0;x+2<=k;x+=2) {
				update(ans,mod-(ll)buc[x]*B[tmp.x-1][x]%mod*mi[t2-tmp.y]%mod);
			}
		}
	}
	memset(buc,0,sizeof(buc));
	for (node &tmp : V) {
		if (tmp.op) {
			for (int x=0;x+2<=k;x+=2) {
				update(buc[x],(ll)tmp.val%mod*B[tmp.x-1][x]%mod*mi[t2-tmp.y]%mod);
			}
		} else {
			for (int x=0;x+2<=k;x+=2) {
				update(ans,mod-(ll)buc[x]*A[tmp.x-1][k-x-2]%mod*mi[t1-tmp.y]%mod);
			}
		}
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