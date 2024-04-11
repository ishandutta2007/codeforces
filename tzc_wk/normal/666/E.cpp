#define FASTIO
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
using namespace fastio;
#endif
const int MAXL = 6e5;
const int LOG_N = 20;
const int SQRT_L = 775;
const int SQRT_M = 225;
const int MAXM = 5e4;
const int MAXQ = 5e5;
int n, m, qu, hib[MAXL + 5];
int col[MAXL + 5], s[MAXL + 5], len, sgm = 126; char buf[MAXL + 5];
int rk[MAXL + 5], sa[MAXL + 5], ht[MAXL + 5], seq[MAXL + 5], buc[MAXL + 150];
void getsa() {
	static pii x[MAXL + 5]; int vmax = sgm, gr = 0;
	for (int i = 1; i <= len; i++) buc[s[i]]++;
	for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
	for (int i = len; i; i--) sa[buc[s[i]]--] = i;
	for (int i = 1; i <= len; i++) {
		if (s[sa[i]] != s[sa[i - 1]]) ++gr;
		rk[sa[i]] = gr;
	}
	vmax = gr;
	for (int k = 1; k <= len; k <<= 1) {
		for (int i = 1; i <= len; i++) {
			if (i + k <= len) x[i] = mp(rk[i], rk[i + k]);
			else x[i] = mp(rk[i], 0);
		}
		memset(buc, 0, sizeof(buc)); int num = 0; gr = 0;
		for (int i = 1; i <= len; i++) if (sa[i] > k) seq[++num] = sa[i] - k;
		for (int i = len - k + 1; i <= len; i++) seq[++num] = i;
		for (int i = 1; i <= len; i++) buc[x[i].fi]++;
		for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
		for (int i = len; i; i--) sa[buc[x[seq[i]].fi]--] = seq[i];
		for (int i = 1; i <= len; i++) {
			if (x[sa[i]] != x[sa[i - 1]]) ++gr;
			rk[sa[i]] = gr;
		}
		vmax = gr; if (vmax == len) break;
	}
}
void getht() {
	int k = 0;
	for (int i = 1; i <= len; i++) {
		if (rk[i] == 1) continue; if (k) --k; int j = sa[rk[i] - 1];
		while (i + k <= len && j + k <= len && s[i + k] == s[j + k]) ++k;
		ht[rk[i]] = k;
	}
}
int st[LOG_N + 2][MAXL + 5];
void buildst() {
	for (int i = 2; i <= len; i++) st[0][i] = ht[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= len; j++)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
}
int queryst(int l, int r) {
	int k = hib[r - l + 1];
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}
pii get_itvl(int x, int k) {
	x = rk[x]; int L = 1, R = x - 1, l = x, r = x;
	while (L <= R) {
		int mid = L + R >> 1;
		if (queryst(mid + 1, x) >= k) l = mid, R = mid - 1;
		else L = mid + 1;
	}
	L = x + 1; R = len;
	while (L <= R) {
		int mid = L + R >> 1;
		if (queryst(x + 1, mid) >= k) r = mid, L = mid + 1;
		else R = mid - 1;
	}
	return mp(l, r);
}
struct BlockIniter {
	int blk_sz, blk_cnt, bel[MAXL + 5], L[SQRT_L + 5], R[SQRT_L + 5];
	void init(int LEN) {
		blk_sz = sqrt(LEN); blk_cnt = (LEN - 1) / blk_sz + 1;
		for (int i = 1; i <= blk_cnt; i++) {
			L[i] = (i - 1) * blk_sz + 1; R[i] = min(i * blk_sz, LEN);
			for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
		}
	}
	int operator [](int id) {return bel[id];}
} B1, B2;
struct qry {
	int l1, r1, l2, r2, id;
	bool operator < (const qry &rhs) {
		if (B1[l1] != B1[rhs.l1]) return B1[l1] < B1[rhs.l1];
		else if (B1[l1] & 1) return r1 < rhs.r1;
		else return r1 > rhs.r1;
	}
} q[MAXQ + 5];
int occ[SQRT_M + 5][MAXM + 5], MX[SQRT_M + 5], cnt[MAXM + 5];
void push(int x) {
	x = sa[x];
	if (col[x]) {
		register int c = col[x];
		occ[B2[c]][cnt[c]]--; cnt[c]++;
		occ[B2[c]][cnt[c]]++; chkmax(MX[B2[c]], cnt[c]);
	}
}
void pop(int x) {
	x = sa[x];
	if (col[x]) {
		register int c = col[x];
		occ[B2[c]][cnt[c]]--; cnt[c]--;
		occ[B2[c]][cnt[c]]++;
		while (!occ[B2[c]][MX[B2[c]]]) --MX[B2[c]];
	}
}
pii res[MAXQ + 5];
pii query(int l, int r) {
	if (B2[l] == B2[r]) {
		pii mx = mp(-1, -1);
		for (int i = l; i <= r; i++) chkmax(mx, mp(cnt[i], -i));
		return mx;
	} else {
		pii mx_blk = mp(-1, 0), mx = mp(-1, -1);
		for (int i = l; i <= B2.R[B2[l]]; i++) chkmax(mx, mp(cnt[i], -i));
		for (int i = B2.L[B2[r]]; i <= r; i++) chkmax(mx, mp(cnt[i], -i));
		for (int i = B2[l] + 1; i < B2[r]; i++) chkmax(mx_blk, mp(MX[i], -i));
		if (mx_blk.se != 0) {
			for (int i = B2.L[-mx_blk.se]; i <= B2.R[-mx_blk.se]; i++)
				chkmax(mx, mp(cnt[i], -i));
		}
		return mx;
	}
}
int main() {
	for (int i = 2; i <= MAXL; i++) hib[i] = hib[i >> 1] + 1;
	readstr(buf + 1); n = strlen(buf + 1);
	for (int i = 1; i <= n; i++) s[++len] = buf[i];
	read(m);
	for (int i = 1; i <= m; i++) {
		readstr(buf + 1); int L = strlen(buf + 1); s[++len] = ++sgm;
		for (int j = 1; j <= L; j++) s[++len] = buf[j], col[len] = i;
	}
	getsa(); getht(); buildst(); B1.init(len); B2.init(m);
	read(qu);
	for (int i = 1; i <= qu; i++) {
		read(q[i].l2); read(q[i].r2); read(q[i].l1); read(q[i].r1);
		pii pp = get_itvl(q[i].l1, q[i].r1 - q[i].l1 + 1);
		q[i].l1 = pp.fi; q[i].r1 = pp.se; q[i].id = i;
	}
	sort(q + 1, q + qu + 1); int cl = 1, cr = 0;
	for (int i = 1; i <= B2.blk_cnt; i++) occ[i][0] = B2.R[i] - B2.L[i] + 1;
	for (int i = 1; i <= qu; i++) {
		while (cr < q[i].r1) push(++cr);
		while (cl > q[i].l1) push(--cl);
		while (cl < q[i].l1) pop(cl++);
		while (cr > q[i].r1) pop(cr--);
		res[q[i].id] = query(q[i].l2, q[i].r2);
	}
	for (int i = 1; i <= qu; i++) print(-res[i].se, ' '), print(res[i].fi, '\n');
	print_final();
	return 0;
}