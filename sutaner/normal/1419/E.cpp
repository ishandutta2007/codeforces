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
#define maxn 200020
#define maxm
#define maxs
#define maxb 10
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}
int p[maxn], cp = 0, son[maxn]; bool visp[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!visp[i]) p[++cp] = i, son[i] = cp;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			visp[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
}

pii lis[maxn]; int cs = 0;

/*
bool vis[1 << maxb];
void dfs2(int S, int now) {
	if (!S) {
		prijntf("%d ", now);
		return;
	}
	
}

void dfs(int pos, int S){
	if (pos == cs + 1) { 
		if (vis[S]) return;
		vis[S] = 1;
		dfs2(S, 1);
	}
	dfs(pos + 1, S ^ (1 << (pos - 1)));
	dfs(pos + 1, S);
}
*/
set<int> s;
void dfs(int pos, int now){
	if (pos == cs + 1) { 
		if (s.count(now)) return;
		s.insert(now);
		printf("%d ", now);
		return;
	}
	rep(i, 0, lis[pos].se) {
		dfs(pos + 1, now);
		now *= lis[pos].fi;
	}
}

void play(int x) {
	cs = 0; s.clear(); 
	rep(i, 1, cp) {
		if (p[i] * p[i] > x) break;
		if (x % p[i] == 0) {
			int num = 0;
			while (x % p[i] == 0) x /= p[i], num++;
			lis[++cs] = pii(p[i], num);
		}
	}
	if (x > 1) lis[++cs] = pii(x, 1);
	
	if (cs == 1) {
		int now = 1;
		rep(i, 1, lis[1].se) {
			now *= lis[1].fi;
			printf("%d ", now);
		}
		printf("\n0\n"); 
		return;
	}
	if (cs == 2) {
		if (lis[1].se == 1 && lis[2].se == 1) {
			printf("%d %d %d\n1\n", lis[1].fi, lis[2].fi, lis[1].fi * lis[2].fi);
			return;
		}
		else {
			if (lis[1].se == 1) swap(lis[1], lis[2]);
			int now = 1;
			rep(i, 1, lis[1].se) {
				now *= lis[1].fi;
				printf("%d ", now);
			}
			printf("%d ", lis[1].fi * lis[2].fi);
			now = 1;
			rep(i, 1, lis[2].se) {
				now *= lis[2].fi;
				printf("%d ", now);
			} 
			rep(i, 1, lis[1].se) rep(j, 1, lis[2].se) {
				if (i == 1 && j == 1) continue;
				now = 1;
				rep(k, 1, i) now *= lis[1].fi;
				rep(k, 1, j) now *= lis[2].fi;
				printf("%d ", now);
			}
			printf("\n0\n"); 
			return;
		}
	}
	else {
		rep(i, 1, cs) s.insert(lis[i].fi);
		rep(i, 1, cs) s.insert(lis[i].fi * lis[(i == cs) ? 1 : (i + 1)].fi);
		rep(i, 1, cs) {
			printf("%d ", lis[i].fi);
			int now = 1;
			rep(j, 1, lis[i].se) now *= lis[i].fi, dfs(i + 1, now);
			printf("%d ", lis[i].fi * lis[(i == cs) ? 1 : (i + 1)].fi);
		}
		printf("\n0\n"); 
		return;
	} 
}
int main(){
	init();
	int x, T;
	read(T);
	while (T--){
		read(x), play(x);
	} 
	return 0;
}