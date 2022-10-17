#include <cstdio>

const int N = 1000;
int t, n, l[N], r[N];

void run(int ll, int rr) 
{
	if (ll > rr) return;
	for (int i = ll; i <= rr; ++i) {
		bool ok = i == ll, ok1 = i == rr;
		for (int j = 0; j < n; ++j) {
			if (l[j] == ll && r[j] == i - 1) ok = 1;
			if (l[j] == i + 1 && r[j] == rr) ok1 = 1;
		}
		if (ok && ok1) {
			printf("%d %d %d\n", ll, rr, i);
			run(ll, i - 1);
			run(i + 1, rr);
		}
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d%d", l + i, r + i);
		run(1, n);
	}
}