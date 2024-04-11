#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(2e5)+10;
int T,n,k,ans,t;
int a[maxn],pos[maxn],vis[maxn],b[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(a[i]),pos[a[i]]=i,vis[i]=0;
		for (int i=1;i<=k;i++) read(b[i]),vis[pos[b[i]]]=1;
		ans=1;
		vis[0]=vis[n+1]=1;
		for (int i=1;i<=k;i++) {
			t=vis[pos[b[i]]-1]+vis[pos[b[i]]+1];
			if (t==2) { ans=0; break; }
			if (!t) ans=(ll)ans*2%mod;
			vis[pos[b[i]]]=0;
		}
		printf("%d\n",ans);
	}
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