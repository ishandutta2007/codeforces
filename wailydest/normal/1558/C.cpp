#include <cstdio>
#include <utility>
#include <vector>

const int N = 2022;
int n, a[N];
std::vector<int> mv;

void apply(int l) 
{
	mv.push_back(l);
	for (int i = 0; i < l / 2; ++i) std::swap(a[i], a[l - i - 1]);
}

void testcase() 
{
	scanf("%d", &n);
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
		if ((a[i] ^ i) & 1) ok = false;
	}
	if (!ok) {
		printf("-1\n");
		return;
	}
	while (n > 1) {
		int p;
		for (int i = 0; i < n; ++i) if (a[i] == n - 1) p = i;
		apply(p + 1);
		for (int i = 0; i < n; ++i) if (a[i] == n - 2) p = i;
		apply(p);
		apply(p + 2);
		apply(3);
		apply(n);
		n -= 2;
	}
	printf("%d\n", (int)mv.size());
	for (int i = 0; i < (int)mv.size(); ++i) printf("%d ", mv[i]);
	printf("\n");
	mv.clear();
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}