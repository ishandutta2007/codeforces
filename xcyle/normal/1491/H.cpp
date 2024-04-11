#include <iostream>
#include <cstdio>
#define maxn 110005
#define B 505
#define jump(x) max(1, (nxt[x] + tag[x / B]))
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x;
}
int n, q, a[maxn], tag[maxn], cnt[maxn], tp, l, r, x, u, v;
int nxt[maxn];
inline void work(int id)
{
	for (int i = id * B; i < (id + 1) * B; i++) nxt[i] = ((a[i] < id * B) ? a[i] : nxt[a[i]]);
}
int main()
{
	n = read(), q = read();
	for (int i = 2; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i += B) work(i / B);
	work(n / B);
	while(q--)
	{
		tp = read();
		if(tp == 1)
		{
			l = read(), r = read(), x = read();
			if(l / B == r / B)
			{
				for (int i = l; i <= r; i++) a[i] = max(a[i] - x, 1);
				work(l / B);
			}
			else
			{
				for (int i = l; i < (l / B + 1) * B; i++) a[i] = max(a[i] - x, 1);
				work(l / B);
				for (int i = l / B + 1; i < r / B; i++)
				{
					if(cnt[i] > B + 5) tag[i] -= x, tag[i] = max(-n, tag[i]);
					else
					{
						cnt[i] += x;
						for (int j = i * B; j < (i + 1) * B; j++) a[j] = max(a[j] - x, 1);
						work(i);
					}
				}
				for (int i = (r / B) * B; i <= r; i++) a[i] = max(a[i] - x, 1);
				work(r / B);
			}
		}
		else
		{
			int u = read(), v = read();
			while(u != v && (u > B || v > B))
			{
				if(u / B < v / B) swap(u, v);
				if(u / B > v / B) u = jump(u);
				else
				{
					if(jump(u) == jump(v)) break;
					u = jump(u), v = jump(v);
				}
			}
			while(u != v)
			{
				if(u < v) swap(u, v);
				u = max(1, a[u] + tag[u / B]);
			}
			printf("%d\n", u);
		}
	}
	return 0;
}