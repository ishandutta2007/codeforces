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

pii lis[maxn]; int cs = 0; char s[maxn]; int n;

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		n = strlen(s + 1); 
		rep(i, 1, n) {
			char now = s[i]; int _i = i;
			while (i <= n && s[i] == now) i++;
			lis[++cs] = pii(now - 'A', i - _i);
			i--; 
		}
		int res = 0, cnt = 0, fir = (lis[1].fi) ? (lis[1].se & 1) : 0;
		rep(i, 1, cs) {
			if (i == 1 && lis[1].fi) continue;
			if (!lis[i].fi) cnt += lis[i].se;
			else {
				//if (!cnt) {res += (lis[i].se & 1); continue;}
				if (lis[i].se <= cnt) cnt -= lis[i].se;
				else {
					if ((lis[i].se - cnt) & 1) {
						if (fir) cnt = fir = 0;
						else cnt = 1;
					}
					else cnt = 0;
				}
			}
		}
		res += cnt + fir;
		write(res);
		cs = 0;
	}
	return 0;
}