#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,s[maxn],x,pos[maxn*2],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n*2;i++) {
			read(x);
			if (x==2) x=-1;
			s[i]=s[i-1]+x;
		}
		if (s[n*2]==0) { printf("0\n"); continue; }
		for (int i=-n*2;i<=n*2;i++) pos[i+n*2]=-1;
		for (int i=0;i<n;i++) {
			pos[s[i]+n*2]=max(pos[s[i]+n*2],i+1);
		}
		int r=n,l=pos[s[r]-s[n*2]+n*2];
		if (l>-1) ans=r-l+1;
		else ans=n*2;
		pos[s[n]+n*2]=max(pos[s[n]+n*2],n+1);
		for (int r=n+1;r<=n*2;r++) {
			l=pos[s[r]-s[n*2]+n*2];
			if (l>-1) ans=min(ans,r-l+1);
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