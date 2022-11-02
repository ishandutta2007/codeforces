#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll a,b,c;
int T;
int mn(ll x) {
	int res=10;
	while (x) res=min(res,(int)(x%10)),x/=10;
	return res;
}
int mx(ll x) {
	int res=0;
	while (x) res=max(res,(int)(x%10)),x/=10;
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(a);
		read(b);
		while (1) {
			b--;
			c=mn(a)*mx(a);
			if (!c||!b) break;
			a+=c;
			//printf("%lld\n",a);
		}
		printf("%lld\n",a);
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