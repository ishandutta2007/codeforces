#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e5;
const int SQRT = 500;
int n, X, hd[MAXN + 5], nxt[MAXN + 5], to[MAXN + 5], ec = 0;
int deg[MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
vector<int> pts[MAXN + 5], cdep[MAXN + 5]; int dep[MAXN + 5], mx = 0;
void dfs(int x) {
	pts[dep[x]].pb(x); chkmax(mx, dep[x]);
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; dep[y] = dep[x] + 1; dfs(y);
	}
}
int key[SQRT + 5], keycnt = 0;
int dp[SQRT + 5][MAXN + 5];
int book[MAXN + 5];
void dump(int x, int s) {
//	printf("dump %d %d\n", x, s);
	if (!x) return assert(!s), void();
	for (int i = 0; i <= cdep[key[x]].size(); i++) {
		if(dp[x - 1][s - key[x] * i]) {
			book[key[x]] = i;
			dump(x - 1, s - key[x] * i);
			return;
		}
	} assert(0);
}
char res[MAXN + 5];
int main() {
	scanf("%d%d", &n, &X);
	for (int i = 2, fa; i <= n; i++) scanf("%d", &fa), adde(fa, i), deg[fa]++;
	dep[1] = 1; dfs(1);
	for (int i = 1; i <= n; i++) cdep[pts[i].size()].pb(i);
	for (int i = 1; i <= n; i++) if(!cdep[i].empty())
		key[++keycnt] = i;
	dp[0][0] = 1;
	for (int i = 1; i <= keycnt; i++) {
		int mul = (cdep[key[i]].size() + 1) * key[i];
		for (int j = 0; j < key[i]; j++) {
			int cnt = 0;
			for (int k = j; k <= n; k += key[i]) {
				cnt += dp[i - 1][k];
				if (k - mul >= 0)
					cnt -= dp[i - 1][k - mul];
				dp[i][k] = (!!cnt);
			}
		}
	}
	if(dp[keycnt][X]) {
//		puts("-1");
		printf("%d\n", mx); dump(keycnt, X);
		for (int i = 1; i <= n; i++) {
//			printf("%d %d\n", i, book[i]);
			for (int j = 0; j < book[i]; j++) {
				for (int pt : pts[cdep[i][j]]) res[pt] = 'a';
			}
		}
		for (int i = 1; i <= n; i++) if (!res[i]) res[i] = 'b';
		printf("%s\n", res + 1);
	} else {
		printf("%d\n", mx + 1);
		int A = X, B = n - X;
		for (int i = 1; i <= n; i++) {
			int lf = 0, tot = 0;
			for (int p : pts[i]) lf += (!deg[p]), tot++;
			if (A >= tot - lf) {
				for (int p : pts[i]) if (deg[p])
					res[p] = 'a';
				A -= (tot - lf);
				if (A >= lf) {
					for (int p : pts[i]) if (!deg[p])
						res[p] = 'a';
					A -= lf;
				} else {
					for (int p : pts[i]) if (!deg[p]) {
						if (A) res[p] = 'a', A--;
						else res[p] = 'b', B--;
					}
				}
			} else {
				for (int p : pts[i]) if (deg[p])
					res[p] = 'b';
				B -= (tot - lf);
				if (B >= lf) {
					for (int p : pts[i]) if (!deg[p])
						res[p] = 'b';
					B -= lf;
				} else {
					for (int p : pts[i]) if (!deg[p]) {
						if (B) res[p] = 'b', B--;
						else res[p] = 'a', A--;
					}
				}
			}
		} printf("%s\n", res + 1);
	}
	return 0;
}
/*
7 2
1 1 1 2 3 4
*/