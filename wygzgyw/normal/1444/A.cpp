#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,q,m;
ll p,ans;
void solve(int x) {
	ll y=p;
	while (1) {
		if (y%q!=0) { ans=max(ans,y); return; }
		if (y%x==0) y/=x;
		else break;
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(p),read(q);
		m=q; ans=0;
		for (int z=2;z*z<=m;) {
			if (m%z==0) {
				solve(z);
				while (m%z==0) m/=z;
			}
			if (z==2) z++; else z+=2;
		}
		if (m>1) solve(m);
		printf("%lld\n",ans);
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