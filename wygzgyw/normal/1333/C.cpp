#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,d[maxn];
ll a[maxn],s[maxn],ans;
map<ll,int> M;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	int x;
	for (int i=n;i>=1;i--) {
		if (!M[s[i]]) M[s[i]]=i;
		else M[s[i]]=min(M[s[i]],i);
		x=M[s[i-1]];
		if (!x) x=n; else x--;
		d[i]=x;
	}
	d[n+1]=n;
	for (int i=n;i>=1;i--) d[i]=min(d[i],d[i+1]);
	for (int i=1;i<=n;i++) ans+=d[i]-i+1;
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