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
#define maxn
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

int a[320];
int main(){
	int T, x; read(T);
	while (T--){
		long double r = 0, aver = 0; int mx = -200000;
		rep(i, 1, 250) read(a[i]), aver += a[i], mx = max(mx, a[i]); aver /= 250.0;
		rep(i, 1, 250) r += (a[i] - aver) * (a[i] - aver);  r /= 250.0, r = sqrt(r), r = mx / r;
		//cout << r << " ";
		if (r > 1.9) printf("poisson\n");
		else printf("uniform\n");
		
		/*
		srep(i, 0, 3020) s.insert(pii(num[i], i));
		int K = 10; it = s.rbegin();
		while (K--) lis[++cs] = it -> second, it++; 
		sort(lis + 1, lis + 1 + 10);
		int d = lis[10] - lis[1];
		if (d < 
		*/ 
	}
	return 0;
}