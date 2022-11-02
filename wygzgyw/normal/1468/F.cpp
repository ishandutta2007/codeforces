#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int T,n;
ll cnt;
map<pair<int,int>,int> ans;
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
struct node { int x,y; } p[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	int a,b,c,d,x,y,z;
	read(T);
	while (T--) {
		read(n); ans.clear();
		for (int i=1;i<=n;i++) {
			read(a),read(b),read(c),read(d);
			x=c-a,y=d-b;
			z=gcd(abs(x),abs(y)),x/=z,y/=z;
			p[i]=(node){x,y};
			ans[make_pair(x,y)]++;
		}
		cnt=0;
		for (int i=1;i<=n;i++) cnt+=ans[make_pair(-p[i].x,-p[i].y)];
		printf("%lld\n",cnt/2);
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