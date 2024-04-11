#include <cstdio>
#include <cstring>

const int md = 1000000007;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}
int po(int a, int b) 
{
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) 
{
	return po(a, md - 2);
}
inline int di(int a, int b) 
{
	return mul(a, inv(b));
}

const int N = 100000;
int t, n, m, x, y, x1, y1, p;
bool vis[N << 2];

inline int id(int x, int y, int dx, int dy) 
{
	return x * m + y << 2 | (dx + 1 >> 1) << 1 | (dy + 1 >> 1);
}

inline void f(int &x, int &y, int &dx, int &dy) 
{
	if (x + dx == n || x + dx < 0) dx *= -1;
	if (y + dy == m || y + dy < 0) dy *= -1;
	x += dx;
	y += dy;
}

bool good(int x, int y) 
{
	return x == x1 || y == y1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d%d", &n, &m, &x, &y, &x1, &y1, &p);
		--x;
		--y;
		--x1;
		--y1;
		memset(vis, 0, n * m << 2);
		p = di(p, 100);
		int dx = 1, dy = 1, amt = 0, ex = 0, pr = 0;
		do {
			if (good(x, y)) {
				ex = add(ex, mul(p, mul(amt, sub(1, pr))));
				pr = add(pr, mul(sub(1, pr), p));
			}
			++amt;
			vis[id(x, y, dx, dy)] = 1;
			f(x, y, dx, dy);
		} while (!vis[id(x, y, dx, dy)]);
		int len = amt;
		amt = 0;
		int start = id(x, y, dx, dy), pr_c = 0, ex_c = 0;
		do {
			if (good(x, y)) {
				ex_c = add(ex_c, mul(p, mul(amt, sub(1, pr_c))));
				pr_c = add(pr_c, mul(sub(1, pr_c), p));
			}
			++amt;
			f(x, y, dx, dy);
		} while (id(x, y, dx, dy) != start);
		printf("%d\n", add(ex, mul(sub(1, pr), add(len, di(add(ex_c, mul(sub(1, pr_c), amt)), pr_c)))));
	}
	return 0;
}