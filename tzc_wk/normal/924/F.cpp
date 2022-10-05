// Created time: 2022/7/11 8:36:30
#include <bits/stdc++.h>
#define FASTIO
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
typedef __int128_t i128;
const int MAXC = 3.3e4;
const int MAXQ = 5e4;
int qu; struct qry {ll l, r; int k;} q[MAXQ + 5];
vector<pair<ll, int> > states;
unordered_map<ll, int> id; int idcnt; ll rid[MAXC + 5];
int trs[MAXC + 5][10];
ll dp[22][MAXC + 2][11], res[MAXQ + 5];
int calc(i128 dpv, int sum) {for (int i = sum / 2; ; i--) if (dpv >> i & 1) return sum - i * 2;}
void dfs(int x, int pre, ll val, i128 dpv, int sum) {
	if (x == 19) {
		int num = calc(dpv, sum); 
		if (num >= 2) states.pb(mp(val, num));
		return;
	}
	for (int i = pre; i <= 9; i++) dfs(x + 1, i, val * 10 + i, dpv | (dpv << i), sum + i);
}
void init_states() {
	dfs(1, 0, 0, 1, 0); queue<ll> q;
	for (auto p : states) id[p.fi] = ++idcnt, rid[idcnt] = p.fi, q.push(p.fi);
	while (!q.empty()) {
		ll x = q.front(); q.pop(); multiset<int> st;
		for (ll tmp = x, d = 0; d < 19; d++, tmp /= 10) st.insert(tmp % 10);
		st.insert(0);
		for (int d = 0; d < 10; d++) {
			if (st.find(d) == st.end()) {trs[id[x]][d] = -1; continue;}
			st.erase(st.find(d)); ll nval = 0;
			for (int dd : st) nval = nval * 10 + dd;
			if (!id[nval]) id[nval] = ++idcnt, rid[idcnt] = nval, q.push(nval);
			trs[id[x]][d] = id[nval]; st.insert(d);
		}
	}
}
vector<tuple<int, int, int, int, int> > qv[22];
int d[MAXQ * 2 + 5][22], len[MAXQ * 2 + 5], id_pre[MAXQ * 2 + 5][22];
void deal_bits(int t, ll x) {
	while (x) d[t][len[t]++] = x % 10, x /= 10;
	vector<int> vec;
	for (int i = len[t]; ~i; i--) {
		if (i != len[t]) vec.pb(d[t][i]);
		sort(vec.begin(), vec.end()); ll val = 0;
		for (int dig : vec) val = val * 10 + dig;
		id_pre[t][i] = id[val];
	}
}
ll solve_odd(ll id) {
	static ll dp0[22][2][2]; memset(dp0, 0, sizeof(dp0));
	dp0[len[id]][1][0] = 1;
	for (int i = len[id]; i; i--) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
		int up = (j) ? d[id][i - 1] : 9;
		for (int t = 0; t <= up; t++) dp0[i - 1][j && (t == up)][k ^ (t & 1)] += dp0[i][j][k];
	}
	return dp0[0][0][1] + dp0[0][1][1];
}
ll solve(int id) {
	ll ans = 0;
	for (int i = len[id] - 1; ~i; i--) ans += dp[i + 1][id_pre[id][i + 1]][d[id][i]];
	ans += dp[0][id_pre[id][0]][10];
	return ans;
}
void calc_dp(int num) {
	memset(dp, 0, sizeof(dp));
	int pre = 0, cur = 1;
	for (pair<ll, int> p : states) if (p.se == num) dp[0][id[p.fi]][10] = 1;
	for (int i = 0; i < 19; i++) {
		for (int k = 1; k <= idcnt; k++) {
			for (int d = 1; d <= 10; d++) dp[i][k][d] += dp[i][k][d - 1];
			if (dp[i][k][10]) {
				for (int d = 0; d < 10; d++) {
					if (!~trs[k][d]) continue;
					dp[i + 1][trs[k][d]][d + 1] += dp[i][k][10];
				}
			}
		}
	}
}
int main() {
	init_states(); read(qu);
	for (int i = 1; i <= qu; i++) {
		read(q[i].l); read(q[i].r); read(q[i].k); res[i] = q[i].r - q[i].l + 1;
		if (q[i].r == 1000000000000000000ll) res[i] -= (q[i].k == 0), q[i].r--;
		deal_bits(i, q[i].r); deal_bits(i + qu, q[i].l - 1);
		if (q[i].k == 0) res[i] -= solve_odd(i) - solve_odd(i + qu);
	}
	for (int k = 2; k <= 9; k++) {
		calc_dp(k);
		for (int i = 1; i <= qu; i++) {
			if (q[i].k == 0 && (k % 2 == 0)) res[i] -= solve(i) - solve(i + qu);
			else if (q[i].k && k > q[i].k) res[i] -= solve(i) - solve(i + qu);
		}
	}
	for (int i = 1; i <= qu; i++) print(res[i], '\n');
	print_final();
	return 0;
}