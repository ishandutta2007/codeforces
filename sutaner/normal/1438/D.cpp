#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 300020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, a[maxn];
struct ele{
	int x, y, z;
	ele(int x, int y, int z) : x(x), y(y), z(z){}
	ele(){}
	void print(){
		printf("%d %d %d\n", x, y, z);
	}
}ans[maxn]; int cs = 0;
inline void play(int i, int j, int k) { 
	ans[++cs] = ele(i, j, k);
	a[i] = a[j] = a[k] = a[i] ^ a[j] ^ a[k];
}
int main(){
	int sum = 0; read(n); rep(i, 1, n) read(a[i]), sum ^= a[i];
	if (n & 1) {
		printf("YES\n");
		play(1, 2, 3);
		for (int i = 3; i <= n - 2; i += 2) play(i, i + 1, i + 2); 
		for (int i = n - 2; i >= 3; i -= 2) play(i - 2, i - 1, i);
		printf("%d\n", cs);
		rep(i, 1, cs) ans[i].print();
	}
	else {
		play(1, 2, 3), play(2, 3, 4);
		for (int i = 4; i <= n - 2; i += 2) play(i, i + 1, i + 2);  
		for (int i = n - 2; i >= 4; i -= 2) play(i - 2, i - 1, i);
		if (a[1] != a[2]) printf("NO\n");
		else {
			printf("YES\n");
			printf("%d\n", cs);
			rep(i, 1, cs) ans[i].print();
		} 
	} 
	return 0;
}