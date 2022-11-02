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
const int maxn=(1<<18)+5;
int n,a[maxn];
struct node {
	ll L,R,ans,sum;
	friend node operator + (node A,node B) {
		node res;
		res.L=max(A.L,B.L+A.sum);
		res.R=max(B.R,A.R+B.sum);
		res.ans=max(max(A.ans,B.ans),A.R+B.L);
		res.sum=A.sum+B.sum;
		return res;
	}
	void init(ll x) { L=R=ans=max(0LL,x),sum=x; }
};
vector<node> V[20];
ll ans[maxn];
void dfs(int x,vector<node> *V) {
	ans[x]=V[n][0].ans;
	for (int i=n-1;i>=0;i--) {
		if (x>>i&1) break;
		vector<node> V2[20];
		for (node &v : V[i]) V2[i].push_back(v);
		for (int j=0;j<V2[i].size();j+=2) swap(V2[i][j],V2[i][j+1]);
		for (int j=i+1;j<=n;j++) { V2[j].clear(); for (int k=0;k<V2[j-1].size();k+=2) V2[j].push_back(V2[j-1][k]+V2[j-1][k+1]); }
		dfs(x|(1<<i),V2);
	}
}
int main() {
	read(n);
	for (int i=0;i<(1<<n);i++) {
		read(a[i]);
		node A; A.init(a[i]);
		V[0].push_back(A);
	}
	for (int i=1;i<=n;i++) for (int j=0;j<V[i-1].size();j+=2) V[i].push_back(V[i-1][j]+V[i-1][j+1]);
	dfs(0,V);
	int rt,now=0,q; read(q);
	while (q--) {
		int x; read(x); now^=1<<x;
		printf("%lld\n",ans[now]);
	}
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