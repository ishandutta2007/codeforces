#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int n,d[maxn],tot;
ll a[maxn],s[maxn];
double ans[maxn];
int nxt[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	for (int i=n;i>=0;i--) {
		while (tot>1&&(s[d[tot]]-s[i])*(d[tot-1]-d[tot])>(s[d[tot-1]]-s[d[tot]])*(d[tot]-i)) tot--;
		nxt[i]=d[tot];
		d[++tot]=i;
	}
	int pos=1;
	while (pos<=n) {
		for (int i=pos;i<=nxt[pos-1];i++)
			ans[i]=(double)(s[nxt[pos-1]]-s[pos-1])/(nxt[pos-1]-pos+1);
		pos=nxt[pos-1]+1;
	}
	for (int i=1;i<=n;i++) printf("%.10lf\n",ans[i]);
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