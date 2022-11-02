#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(1e5)+10;
int n,a[maxn],s[maxn],ans;
int solve(int l,int r) { return s[r]^s[l-1]; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),s[i]=(s[i-1]^a[i]);
	if (n>70) { printf("1\n"); return 0; }
	ans=INF;
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
		for (int k=i;k<j;k++)
			if (solve(i,k)>solve(k+1,j)) ans=min(ans,j-i-1);
	if (ans==INF) ans=-1;
    printf("%d\n",ans);
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