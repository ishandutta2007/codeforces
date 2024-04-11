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
const int MAXP = 1e6;
const int ALPHA = 26;
const int LOG_N = 20;
struct solver {
	int ch[MAXP + 5][ALPHA + 2], fail[MAXP + 5], ncnt;
	int tr[MAXP + 5][ALPHA + 2], occ[MAXP + 5], cnt[MAXP + 5];
	int rt[LOG_N + 2], siz[LOG_N + 2], ccnt;
	int merge(int x, int y) {
		if (!x || !y) return x + y; int z = ++ncnt; cnt[z] = cnt[x] + cnt[y];
		for (int i = 0; i < 26; i++) ch[z][i] = merge(ch[x][i], ch[y][i]);
		return z;
	}
	void getfail(int R) {
		queue<int> q;
		for (int i = 0; i < 26; i++) {
			if (ch[R][i]) tr[R][i] = ch[R][i], fail[tr[R][i]] = R, q.push(ch[R][i]);
			else tr[R][i] = R;
		}
		while (!q.empty()) {
			int x = q.front(); q.pop(); occ[x] = occ[fail[x]] + cnt[x];
			for (int i = 0; i < 26; i++) {
				if (ch[x][i]) {
					tr[x][i] = ch[x][i]; fail[ch[x][i]] = tr[fail[x]][i];
					q.push(ch[x][i]);
				} else tr[x][i] = tr[fail[x]][i];
			}
		}
	}
	void insert(string s) {
		rt[++ccnt] = ++ncnt; int cur = ncnt;
		for (int i = 0; i < s.size(); i++) {
			if (!ch[cur][s[i] - 'a']) ch[cur][s[i] - 'a'] = ++ncnt;
			cur = ch[cur][s[i] - 'a'];
		}
		cnt[cur]++; siz[ccnt] = 1; getfail(rt[ccnt]);
		while (ccnt > 1 && siz[ccnt - 1] == siz[ccnt]) {
			rt[ccnt - 1] = merge(rt[ccnt - 1], rt[ccnt]);
			siz[ccnt - 1] += siz[ccnt]; --ccnt;
		}
		getfail(rt[ccnt]);
	}
	int query(string s) {
		int res = 0;
		for (int i = 1; i <= ccnt; i++) {
			for (int j = 0, k = rt[i]; j < s.size(); j++) {
				k = tr[k][s[j] - 'a']; res += occ[k];
			}
		}
		return res;
	}
} s1, s2;
int main() {
	int qu; cin >> qu;
	while (qu--) {
		int opt; string s; cin >> opt >> s;
		if (opt == 1) s1.insert(s);
		else if (opt == 2) s2.insert(s);
		else cout << s1.query(s) - s2.query(s) << endl;
	}
	return 0;
}