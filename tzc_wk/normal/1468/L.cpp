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
		if (x<0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1000;
const int MAXV = 1e6;
int n, k; ll x[MAXN + 5], pp[MAXN + 5];
bool ok[MAXN + 5]; map<ll, int> cnt;
int prcnt, pr[MAXV / 6 + 5], vis[MAXV + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1;
		}
	}
}
vector<int> fac[MAXN + 5];
bool book[MAXN + 5];
int main() {
	scanf("%d%d", &n, &k); sieve(MAXV);
	map<ll, vector<int> > pos;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		bool flg = 1; ll tmp = x[i];
		for (int j = 1; j <= prcnt; j++) {
			if (x[i] % pr[j] == 0) {
				while (tmp % pr[j] == 0) tmp /= pr[j];
				if (tmp == 1) pp[i] = pr[j];
				else pp[i] = -1;
				break;
			}
		}
		pos[x[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) if (!pp[i]) {
		if (x[i] <= 1e9 && !pos[x[i] * x[i]].empty()) {
			for (int j : pos[x[i] * x[i]]) pp[j] = x[i];
			pp[i] = x[i];
		}
		else pp[i] = -1;
	}
	int num = 0;
//	for (int i = 1; i <= n; i++) printf("%lld%c", pp[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) if (~pp[i]) cnt[pp[i]]++;
	vector<ll> seq; ll mpos = -1;
	for (auto p : cnt) if (p.se >= 2) {
		seq.pb(p.fi);
		if (p.se >= 3) mpos = p.fi;
	}
//	printf("%d\n", seq.size());
	for (int i = 1; i <= n; i++) {
		if (!~pp[i]) {
			ll tmp = x[i]; vector<int> fc;
			for (int j : seq) if (tmp % j == 0) {
				fc.pb(j);
				while (tmp % j == 0) tmp /= j;
			}
			if (tmp == 1) fac[i] = fc, num++, ok[i] = 1;
		}
		else if (cnt[pp[i]] == 1) pp[i] = -1;
		else num++;
	}
	if (num < k || k == 1) return puts("0"), 0;
	if (~mpos) {
//		puts("-1");
		if (k <= seq.size() * 2) {
			for (int j = 1, lft = 2 + (k & 1); j <= n; j++)
				if (pp[j] == mpos && lft) {
					book[j] = 1; lft--; k--;
				}
			for (int i = 0; i < seq.size(); i++) if (mpos != seq[i]) {
				for (int j = 1, lft = 2; j <= n; j++)
					if (pp[j] == seq[i] && lft && k) {
						book[j] = 1; lft--; k--;
					}
			}
		} else {
			for (int i = 0; i < seq.size(); i++)
				for (int j = 1, lft = 2 + (seq[i] == mpos); j <= n; j++)
					if (pp[j] == seq[i] && lft) {
						book[j] = 1; lft--; k--;
					}
			for (int i = 1; i <= n; i++) if (!book[i] && (ok[i] || pp[i] != -1) && k)
				book[i] = 1, k--;
		}
	} else {
		pii mn = mp(seq.size(), 0);
		for (int i = 1; i <= n; i++) if (ok[i]) chkmin(mn, mp((int)fac[i].size(), i));
		if (k <= 2 * mn.fi && (k & 1)) return puts("0"), 0;
		if (k <= 2 * seq.size()) {
			if (k % 2 == 0) {
				for (int i = 0; i < seq.size(); i++)
					for (int j = 1; j <= n; j++)
						if (pp[j] == seq[i] && k) {
							book[j] = 1; k--;
						}
			} else {
				book[mn.se] = 1; k--;
				for (int f : fac[mn.se]) {
					for (int j = 1; j <= n; j++) if (pp[j] == f)
						book[j] = 1, k--;
				}
				for (int i = 0; i < seq.size(); i++)
					for (int j = 1; j <= n; j++)
						if (pp[j] == seq[i] && !book[j] && k) {
							book[j] = 1; k--;
						}
			}
		} else {
			for (int i = 1; i <= n; i++) if (~pp[i]) book[i] = 1, k--;
			for (int i = 1; i <= n; i++) if (ok[i] && k) book[i] = 1, k--;
		}
	}
	for (int i = 1; i <= n; i++) if (book[i])
		printf("%lld ", x[i]);
	return 0;
}
/*
5 3
2 4 9 27 6

7 5
2 4 9 27 5 25 10

7 6
2 4 9 27 5 25 10
*/