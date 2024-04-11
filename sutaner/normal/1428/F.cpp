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
#define maxn 600020
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

int n; char s[maxn]; ll res = 0;
pii sta[maxn]; int he = 0, bound = 0, cq = 0;
ll sta_sum = 0, que_sum = 0;

int main(){
	scanf("%d%s", &n, s + 1); 
	int zeros = 0;
	rep(i, 1, n) {
		if (s[i] == '0') {  
			per(i, cq, 1) {
				int last = bound + 1;
				while (he && sta[he].fi <= i) {
					sta_sum -= (last - sta[he].se) * 1ll * sta[he].fi;
					last = sta[he].se, he--;
				}
				sta[++he] = pii(i, last);
				sta_sum += (bound + 1 - last) * 1ll * i;
				
				if (i == cq) bound += zeros, sta_sum += 1ll * zeros * sta[he].fi;
				bound++, sta_sum += sta[he].fi;
			}
			if (i > 1 && s[i - 1] == '1') zeros = 0;
			zeros++;
			cq = 0, que_sum = 0;
		}
		else {
			cq++, que_sum += zeros + cq;
			if (he && sta[he].fi < cq) {
				sta_sum += bound - sta[he].se + 1, sta[he].fi++;
				if (he > 1 && sta[he - 1].fi == sta[he].fi) he--; 
			}
		}
		res += sta_sum + que_sum;
	}
	write(res);
	return 0;
}