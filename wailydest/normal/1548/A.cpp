#include <cstdio>
#include <utility>

const int N = 200000;
int t, n, m, q, out[N], ans;

void add(int a, int b) 
{
	if (a > b) std::swap(a, b);
	ans -= !out[a];
	++out[a];
}

void remove(int a, int b) 
{
	if (a > b) std::swap(a, b);
	--out[a];
	ans += !out[a];
}

int main() 
{
	scanf("%d%d", &n, &m);
	ans = n;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a - 1, b - 1);
	}
	scanf("%d", &q);
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 3) printf("%d\n", ans);
		else {
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			if (type == 1) add(a, b);
			else remove(a, b);
		}
	}
	return 0;
}