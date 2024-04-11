#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=5010;
int n;
bool vis[maxn];
ll x[maxn],y[maxn],mx,tmp;
ll sqr(ll A) { return A*A; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	int now=1,pos;
	printf("1 "); vis[1]=1;
	for (int i=2;i<=n;i++) {
		mx=0;
		for (int j=1;j<=n;j++) if (!vis[j]) {
			tmp=sqr(x[j]-x[now])+sqr(y[j]-y[now]);
			if (tmp>=mx) mx=tmp,pos=j;
		}
		now=pos;
		printf("%d ",pos);
		vis[pos]=1;
	}
	puts("");
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