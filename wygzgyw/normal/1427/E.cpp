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
ll x;
ll b[62];
bitset<100000> from[62],now;
void insert(ll a) {
	now.reset();
	now.set(a/x);
	for (int i=61;i>=0;i--) if (a>>i&1) {
		if (b[i]) now^=from[i],a^=b[i];
		else if (a) { b[i]=a,from[i]=now; return; }
	}
}
bool check(ll a=1) {
	return b[0];
}

struct node {
	ll x,y; int op;
};
vector<node> A;
void clear() {
	memset(b,0,sizeof(b));
	A.clear();
}
int N=100000-100;
bool chk(ll x) { return x==(x&(-x)); }
void Insert(ll a) {
	for (int i=61;i>=0;i--) if (a>>i&1) {
		if (b[i]) a^=b[i];
		else if (a) { b[i]=a; return; }
	}
}
bool OK(ll x) {
	memset(b,0,sizeof(b));
	Insert(x);
	for (ll i=2;i<=N;i++) {
		Insert(x*i);
		if (check()) return 1;
	}
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(x);
	//cerr<<__builtin_popcount(x)<<endl;
	while (!OK(x)) {
		int B=4;
		for (int i=0;i<B;i++) {
			A.push_back((node){x<<i,x<<i,1});
		}
		A.push_back((node){x,x<<B,0});
		x^=x<<B;
	}
	memset(b,0,sizeof(b));
	insert(x);
	for (ll i=2;i<=N&&!check();i++) {
		A.push_back((node){x*(i-1),x,1});
		insert(x*i);
	//	printf("%d\n",i);
	}
	assert(check());
	ll w=0;
	for (int i=1;i<=N;i++) if (from[0].test(i)) {
		if (w) A.push_back((node){x*i,w,0});
		w^=x*i;
	}
	//cerr<<x<<endl;
	printf("%d\n",(int)A.size());
	for (node &B : A) {
		if (B.op==1) printf("%lld + %lld\n",B.x,B.y);
		else printf("%lld ^ %lld\n",B.x,B.y);
	}
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