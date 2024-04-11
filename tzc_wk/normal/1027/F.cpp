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
using namespace fastio;
const int MAXN = 1e6;
int n, a[MAXN + 5], b[MAXN + 5], key[MAXN * 2 + 5], uni[MAXN * 2 + 5], num = 0;
int f[MAXN * 3 + 5], dep[MAXN * 3 + 5], val[MAXN * 3 + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
//	printf("merge %d %d\n", x, y);
	x = find(x); y = find(y); if (x == y) return;
	if (dep[x] < dep[y]) swap(x, y); f[y] = x;
	val[x] += val[y]; dep[x] += (dep[x] == dep[y]);
}
bool check(int mid) {
	memset(f, 0, sizeof(f)); memset(dep, 0, sizeof(dep));
	for (int i = 1; i <= n; i++) val[i] = -1;
	for (int i = 1; i <= num; i++) val[i + n] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= mid) merge(i, a[i] + n);
		if (b[i] <= mid) merge(i, b[i] + n);
	}
	for (int i = 1; i <= n + mid; i++)
		if (find(i) == i && val[i] < 0)
			return 0;
	return 1;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]); read(b[i]);
		key[i * 2 - 1] = a[i]; key[i * 2] = b[i];
	}
	sort(key + 1, key + n * 2 + 1);
	for (int i = 1; i <= n * 2; i++) if (key[i] != key[i - 1])
		uni[++num] = key[i];
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(uni + 1, uni + num + 1, a[i]) - uni;
		b[i] = lower_bound(uni + 1, uni + num + 1, b[i]) - uni;
	}
	uni[0] = -1; int l = 1, r = num, p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", uni[p]);
	return 0;
}