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
const int maxn=(8e5)+10;
int n,x,y; ll lazy,ans,L,R;
struct node { int x,y; } a[maxn];
bool cmp(node A,node B) { if (A.x==B.x) return A.y<B.y; return A.x<B.x; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x),read(y);
		a[i]=(node){x+y,x};
	}
	sort(a+1,a+n+1,cmp);
	multiset<ll> s1,s2; multiset<ll> :: iterator it1,it2;
	for (int i=1;i<=n+10;i++) s1.insert(0),s2.insert(0);
	for (int i=1;i<=n;i++) {
		lazy+=a[i].x-a[i-1].x;
		int x=a[i].y;
		it1=s1.end(); it1--; L=(*it1);
		it2=s2.begin(); R=(*it2)+lazy;
		if (x<=L) {
			ans+=L-x;
			s1.insert(x),s1.insert(x);
			it1=s1.end(); it1--; s2.insert((*it1)-lazy); s1.erase(it1);
		} else if (x>=R) {
			ans+=x-R;
			s2.insert(x-lazy),s2.insert(x-lazy);
			it2=s2.begin(); s1.insert((*it2)+lazy); s2.erase(it2);
		} else s1.insert(x),s2.insert(x-lazy);
	}
	printf("%lld\n",ans);
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