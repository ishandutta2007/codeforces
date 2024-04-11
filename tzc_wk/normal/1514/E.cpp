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
const int MAXN = 100;
int n; char res[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5];
bool ask(int u, int v) {
	u--; v--;
	printf("1 %d %d\n", u, v); fflush(stdout);
	int x; scanf("%d", &x); assert(~x);
	return !!x;
}
bool query(int u, vector<int> &vec) {
	u--;
	printf("2 %d %u", u, vec.size());
	for (int x : vec) printf(" %d", x - 1);
	printf("\n"); fflush(stdout);
	int x; scanf("%d", &x); assert(~x);
	return !!x;
}
void solve() {
	scanf("%d", &n); vector<int> chn; chn.pb(1);
	for (int i = 2; i <= n; i++) {
		int l = 0, r = chn.size() - 1, pl = ask(i, chn[l]), pr = ask(i, chn[r]), pos = -1;
		if (pl) pos = 0;
		else if (!pr) pos = chn.size();
		else {
			while (l <= r) {
				int mid = l + r >> 1, pmid = ask(i, chn[mid]);
				if (pmid) pos = mid, r = mid - 1;
				else l = mid + 1;
			}
		}
		chn.pb(i);
		for (int j = (int)(chn.size()) - 2; j >= pos; j--)
			swap(chn[j], chn[j + 1]);
	}
	vector<vector<int> > cur_cmps, cmps;
//	for (int x : chn) printf("%d ", x); printf("\n");
	for (int x : chn) cur_cmps.pb({x});
	memset(vis, 0, sizeof(vis));
	while (!cur_cmps.empty()) {
		if (cur_cmps.size() == 1) {
			cmps.pb(cur_cmps[0]);
			cur_cmps.ppb();
			continue;
		}
		vector<int> vec; bool flg = 0;
		for (int pt : cur_cmps.back()) if (!vis[pt]) {
			int pos = 0;
			for (int i = cur_cmps.size() - 2; ~i; i--) {
				vector<int> vec;
				for (int j = 0; j <= i; j++) for (int x : cur_cmps[j]) vec.pb(x);
				if (!query(pt, vec)) {pos = i + 1; break;}
			}
			vector<int> nw;
			while(cur_cmps.size() > pos) {
				for (int x : cur_cmps.back()) nw.pb(x);
				cur_cmps.ppb();
			}
			cur_cmps.pb(nw); vis[pt] = 1; flg = 1;
			break;
		}
		if (!flg) {
			cmps.pb(cur_cmps.back());
			cur_cmps.ppb();
		}
	}
	reverse(cmps.begin(), cmps.end());
	memset(res, 0, sizeof(res));
	for (int i = 0; i < cmps.size(); i++) {
		for (int x : cmps[i]) for (int y : cmps[i]) res[x][y] = '1';
		for (int j = i + 1; j < cmps.size(); j++)
			for (int x : cmps[i]) for (int y : cmps[j])
				res[x][y] = '1';
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (!res[i][j]) res[i][j] = '0';
	printf("3\n");
	for (int i = 1; i <= n; i++) printf("%s\n", res[i] + 1);
	fflush(stdout);
	scanf("%*d");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}