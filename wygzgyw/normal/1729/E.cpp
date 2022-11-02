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

bool flag;
ll n;

ll query(ll x,ll y) {
	printf("? %lld %lld\n",x,y); fflush(stdout);
	if (!flag) { if (max(x,y)>n) return -1; if (rand()&1) return abs(y-x); return n-abs(y-x); }
	scanf("%lld",&x); return x;
}

int main() {
flag=1;
	
	if (!flag) read(n),srand(time(0));
	
	for (int i=2;;i++) {
		ll x=query(1,i);
		if (x==-1) { printf("! %d\n",i-1); fflush(stdout); return 0; }
		ll y=query(i,1);
		if (x!=y) { printf("! %lld\n",x+y); fflush(stdout); return 0; }
	}
		
	return 0;
}