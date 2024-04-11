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
typedef __int128 big;
typedef long long ll;
const int mod=(1e9)+7;
int n;
map<pair<int,big>,int> M;
int p[7][7];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int bit[1<<7],P[7][1<<7];
vector<int> g[1<<7];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int dfs(int x,big st) {
	if (M.count(MP(x,st))) return M[MP(x,st)];
	if (x==n) {
		if (st>>((1<<n)-1)&1) return 1; return 0;
	}
	int res=0;
	for (int t=0;t<(1<<n);t++) {
		big nxt=0;
		for (int &s : g[x]) if (st>>s&1) {
			for (int i=0;i<n;i++) if ((t>>i&1)&&!(s>>i&1)) nxt|=(big)1<<(s^(1<<i));
		}
		update(res,(ll)dfs(x+1,nxt)*P[x][t]%mod);
	}
	M[MP(x,st)]=res;
	return res;
}
int main() {
	read(n);
	int iv=ksm(100,mod-2);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			read(p[i][j]);
			p[i][j]=(ll)p[i][j]*iv%mod;
		}
	}
	for (int t=0;t<(1<<7);t++) {
		if (t) bit[t]=bit[t-(t&(-t))]+1;
		g[bit[t]].push_back(t);
		for (int i=0;i<n;i++) {
			P[i][t]=1;
			for (int j=0;j<n;j++) if (t>>j&1) P[i][t]=(ll)P[i][t]*p[i][j]%mod;
			else P[i][t]=(ll)P[i][t]*(mod+1-p[i][j])%mod;
		}
	}
	printf("%d\n",dfs(0,1));
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