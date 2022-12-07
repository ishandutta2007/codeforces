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
#define maxn 400020
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
int n; ll W, w[maxn];
int main(){
	int T; read(T);
	while (T--){
		read(n), read(W); rep(i, 1, n) read(w[i]);
		//sort(w + 1, w + 1 + n);
		ll sum = 0, mi = w[1], low = ((W + 1) >> 1), up = W;
		rep(i, 1, n) {
			if (w[i] > up) continue;
			sum += w[i], mi = min(mi, w[i]);
		}
		if (sum < low || mi > up) printf("-1\n");
		else {
			rep(i, 1, n) {
				if (low <= w[i] && w[i] <= up) {
					printf("1\n%d\n", i);
					goto done;
				}
			}
			sum = 0; int ct = 0;
			rep(i, 1, n) {
				if (sum >= ((W + 1) >> 1)) {
					printf("%d\n", ct); 
					srep(j, 1, i) {
						if (w[j] > up) continue;
						printf("%d ", j);
					}
					goto done;
				}
				if (w[i] > up) continue;
				sum += w[i], ct++;
			}
			int i = n + 1;
			if (sum >= ((W + 1) >> 1)) {
				printf("%d\n", ct); 
				srep(j, 1, i) {
					if (w[j] > up) continue;
					printf("%d ", j);
				}
				goto done;
			}
			else printf("-1\n");
		}
		done:;
	}
	return 0;
}