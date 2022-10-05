//Created time: 2022/3/25 21:31:16
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN = 1e5;
const int MAXM = 50;
const int MOD = 1e9 + 7;
const int MAXP = 1 << 18;
int n, k, fac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = 1); i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % MOD;
}
struct edge {int x, y, w;} e[MAXM + 5];
int kx[MAXM + 5], ky[MAXM + 5], ux[MAXM + 5], uy[MAXM + 5], nx, ny;
struct graph {
	int hd[MAXM * 2 + 5], val[MAXM * 4 + 5], to[MAXM * 4 + 5], nxt[MAXM * 4 + 5], ec = 0;
	void init() {memset(hd, 0, sizeof(hd)); ec = 0;}
	void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
} G, T;
bool vis[MAXM * 2 + 5];
int dp[MAXM + 5][MAXM + 5], cmp_cnt = 0;
vector<int> pt; int M = 0;
void dfs(int x) {
	if (vis[x]) return; vis[x] = 1; pt.pb(x);
	for (int e = G.hd[x]; e; e = G.nxt[e]) {int y = G.to[e]; M++; dfs(y);}
}
namespace sub1 {
	int f[MAXM + 5][MAXP + 5];
	vector<int> solve1(vector<int> pt) {
		vector<int> lft, rit;
		for (int x : pt) {
			if (x <= nx) lft.pb(x);
			else rit.pb(x);
		}
		if (lft.size() > rit.size()) swap(lft, rit);
		static int id[MAXM * 2 + 5];
		for (int j = 0; j < lft.size(); j++) id[lft[j]] = j;
		for (int i = 0; i <= rit.size(); i++) for (int j = 0; j < (1 << lft.size()); j++) f[i][j] = 0;
		f[0][0] = 1;
		for (int i = 0; i < rit.size(); i++) for (int j = 0; j < (1 << lft.size()); j++)
			if (f[i][j]) {
				f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
				for (int e = G.hd[rit[i]]; e; e = G.nxt[e]) {
					int y = G.to[e], w = G.val[e];
					if (~j >> id[y] & 1)
						f[i + 1][j | (1 << id[y])] = (f[i + 1][j | (1 << id[y])]
						+ 1ll * f[i][j] * w) % MOD;
				}
			}
		vector<int> ret; ret.resize(lft.size() + 1);
		for (int j = 0; j < (1 << lft.size()); j++)
			ret[__builtin_popcount(j)] = (ret[__builtin_popcount(j)] + f[rit.size()][j]) % MOD;
	//	for (int x : ret) printf("%d ", x); printf("\n");
		return ret;
	}
}
using namespace sub1;
namespace sub2 {
	int dfn[MAXM * 2 + 5], tim;
	vector<tuple<int, int, int> > eT;
	void dfs_build(int x) {
		dfn[x] = ++tim;
		for (int e = G.hd[x]; e; e = G.nxt[e]) {
			int y = G.to[e], z = G.val[e];
			if (!dfn[y]) T.adde(x, y, z), T.adde(y, x, z), dfs_build(y);
			else if (dfn[y] > dfn[x]) eT.pb(mt(x, y, z));
		}
	}
	bool ban[MAXM * 2 + 5];
	int fp[MAXM * 2 + 5][MAXM + 5][2], siz[MAXN + 5];
	void dfsclc(int x, int f) {
		fp[x][0][0] = 1; siz[x] = 1;
		for (int e = T.hd[x]; e; e = T.nxt[e]) {
			int y = T.to[e], z = T.val[e]; if (y == f) continue;
			dfsclc(y, x); static int tmp[MAXM + 5][2];
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i < siz[x]; i++) for (int j = 0; j < siz[y]; j++) {
				tmp[i + j][0] = (tmp[i + j][0] + 1ll * fp[x][i][0] * (fp[y][j][0] + fp[y][j][1])) % MOD;
				if (!ban[x] && !ban[y]) tmp[i + j + 1][1] = (tmp[i + j + 1][1] + 1ll * fp[x][i][0] * fp[y][j][0] % MOD * z) % MOD;
				tmp[i + j][1] = (tmp[i + j][1] + 1ll * fp[x][i][1] * (fp[y][j][0] + fp[y][j][1])) % MOD;
			}
			siz[x] += siz[y];
			for (int i = 0; i < siz[x]; i++) fp[x][i][0] = tmp[i][0], fp[x][i][1] = tmp[i][1];
		}
	}
	vector<int> solve2(vector<int> pt) {
		T.init(); eT.clear(); memset(dfn, 0, sizeof(dfn)); tim = 0;
		int R = pt[0]; dfs_build(R);
		vector<int> ret; ret.resize(pt.size() + 1);
//		for (auto T : eT) printf("(%d, %d, %d)\n", get<0>(T), get<1>(T), get<2>(T));
		for (int i = 0; i < (1 << eT.size()); i++) {
			int prd = 1; bool flg = 1;
			memset(ban, 0, sizeof(ban));
			memset(fp, 0, sizeof(fp));
			for (int j = 0; j < eT.size(); j++) if (i >> j & 1) {
				if (ban[get<0>(eT[j])] || ban[get<1>(eT[j])]) {
					flg = 0; break;
				}
				prd = 1ll * prd * get<2>(eT[j]) % MOD;
				ban[get<0>(eT[j])] = ban[get<1>(eT[j])] = 1;
			}
			if (flg) {
				dfsclc(R, 0);
//				for (int j = 0; j < pt.size(); j++) printf("%d ", (fp[R][j][0] + fp[R][j][1]) % MOD);
//				printf("\n");
				for (int j = 0; j < pt.size(); j++) if (fp[R][j][0] || fp[R][j][1])
					ret[j + __builtin_popcount(i)] = (ret[j + __builtin_popcount(i)] +
					1ll * (fp[R][j][0] + fp[R][j][1]) * prd) % MOD;
			}
		}
		return ret;
	}
}
using namespace sub2;
int main(){
	scanf("%d%d", &n, &k); init_fac(MAXN);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
		e[i].w = (e[i].w - 1 + MOD) % MOD;
		kx[i] = e[i].x; ky[i] = e[i].y;
	}
	sort(kx + 1, kx + k + 1); sort(ky + 1, ky + k + 1);
	for (int i = 1; i <= k; i++) if (kx[i] != kx[i - 1]) ux[++nx] = kx[i];
	for (int i = 1; i <= k; i++) if (ky[i] != ky[i - 1]) uy[++ny] = ky[i];
	for (int i = 1; i <= k; i++) {
		e[i].x = lower_bound(ux + 1, ux + nx + 1, e[i].x) - ux;
		e[i].y = lower_bound(uy + 1, uy + ny + 1, e[i].y) - uy;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		G.adde(e[i].x, e[i].y + nx, e[i].w);
		G.adde(e[i].y + nx, e[i].x, e[i].w);
	}
	for (int i = 1; i <= nx + ny; i++) if (!vis[i]) {
		cmp_cnt++; pt.clear(); M = 0; dfs(i);
		M >>= 1; int N = pt.size();
		vector<int> way;
		if (M > 3 * N / 2) way = solve1(pt);
		else way = solve2(pt);
		for (int j = 0; j <= k; j++) if (dp[cmp_cnt - 1][j])
			for (int l = 0; l < way.size(); l++) if (way[l])
				dp[cmp_cnt][j + l] = (dp[cmp_cnt][j + l] + 1ll * dp[cmp_cnt - 1][j] * way[l]) % MOD;
	}
	int res = 0;
	for (int i = 0; i <= min(n, k); i++)
		res = (res + 1ll * fac[n - i] * dp[cmp_cnt][i]) % MOD;
	printf("%d\n", res);
	return 0;
}
/*
3 3
1 1 3
1 2 2
2 3 2
*/