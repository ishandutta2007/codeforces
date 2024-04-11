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
#define maxn 400020
#define maxm
#define maxs
#define maxb
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

const int inf = 2000000000;

int n, a[maxn];
int up[maxn], cu = 0, down[maxn], cd = 0, dp[maxn];

namespace UP{
int mi[maxn << 2], qx, qy, qd;
inline void pu(int o) {
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
void init(int l, int r, int o) {
	mi[o] = inf;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void mod(int l, int r, int o) {
	if (l == r) {mi[o] = qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	if (qx <= l && r <= qy) return mi[o];
	int mid = ((r - l) >> 1) + l, ans = inf;
	if (qx <= mid) ans = min(ans, get(l, mid, o << 1));
	if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}
}
namespace DOWN{
int mi[maxn << 2], qx, qy, qd;
inline void pu(int o) {
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
void init(int l, int r, int o) {
	mi[o] = inf;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void mod(int l, int r, int o) {
	if (l == r) {mi[o] = qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	if (qx <= l && r <= qy) return mi[o];
	int mid = ((r - l) >> 1) + l, ans = inf;
	if (qx <= mid) ans = min(ans, get(l, mid, o << 1));
	if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}
}

bool cmp(int x, int y){
	return x > y;
}

int main(){
	scanf("%d", &n); rep(i, 1, n) scanf("%d", a + i); 
	dp[n] = 0;
	per(i, n, 1) {
		int x = a[i];
		if (i != n) { 
			if (x == a[i + 1]) dp[i] = dp[i + 1] + 1;
			else if (x > a[i + 1]){ 
				int pos = lower_bound(down + 1, down + 1 + cd, x, cmp) - down;  
				DOWN :: qx = pos, DOWN :: qy = cd;
				if (DOWN :: qx > 1 && down[DOWN :: qx] != x) DOWN :: qx--;
				if (DOWN :: qx <= DOWN :: qy) dp[i] = DOWN :: get(1, n, 1) + 1;
				else dp[i] = dp[i + 1] + 1;
			}
			else {
				int pos = lower_bound(up + 1, up + 1 + cu, x) - up; 
				UP :: qx = pos, UP :: qy = cu;
				if (UP :: qx > 1 && up[UP :: qx] != x) UP :: qx--;
				if (UP :: qx <= UP :: qy) dp[i] = UP :: get(1, n, 1) + 1;
				else dp[i] = dp[i + 1] + 1;
			} 
		} 
		
		
		
		while (cu && x <= up[cu]) {
			UP :: qx = cu, UP :: qd = inf;
			UP :: mod(1, n, 1);
			cu--; 
		}
		up[++cu] = x;
		UP :: qx = cu, UP :: qd = dp[i];
		UP :: mod(1, n, 1);
		
		
		
		while (cd && x >= down[cd]) {
			DOWN :: qx = cd, DOWN :: qd = inf;
			DOWN :: mod(1, n, 1);
			cd--; 
		}
		down[++cd] = x; 
		DOWN :: qx = cd, DOWN :: qd = dp[i];
		DOWN :: mod(1, n, 1);
		
	}
	
	//cout << "dp: "; rep(i, 1, n) cout << dp[i] << ' '; cout << endl;
	
	printf("%d\n", dp[1]);
	return 0;
}