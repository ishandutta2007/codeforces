#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 100019
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;


char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, k, q;
int a[13][maxn];

vector<pii> s;
bitset<4096> f[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("878D.in", "r", stdin);
	#endif
	read(n), read(k), read(q);
	rep(i, 1, k) rep(j, 1, n) read(a[i][j]); 
	int t, x, y;
	rep(i, 1, k) rep(j, 0, 4095) if (j & (1 << i - 1)) f[i][j] = 1; else f[i][j] = 0;
	int _k = k;
	rep(T, 1, q){
		read(t), read(x), read(y);
		if (t == 1) f[++_k] = f[x] | f[y]; 
		else if (t == 2) f[++_k] = f[x] & f[y];
		else {	
			s.clear();
			rep(i, 1, k) s.pb(pii(a[i][y], i));
			sort(s.begin(), s.end());
			int now = 0;
			per(i, k - 1, 0) {
				now |= (1 << s[i].se - 1);
				if (f[x][now]) {
					printf("%d\n", s[i].fi);
					break;
				}
			}
		}
	}
	return 0;
}