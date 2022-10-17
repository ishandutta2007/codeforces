#include <cstdio>
#include <vector>

int t, n, k, l;

inline int add(int a, int b) 
{
	a += b;
	if (a >= k) a -= k;
	return a;
}

inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += k;
	return a;
}

std::vector<int> operator+(std::vector<int> &a, std::vector<int> &b) 
{
	std::vector<int> r(l);
	for (int i = 0; i < l; ++i) r[i] = add(a[i], b[i]);
	return r;
}

std::vector<int> operator-(std::vector<int> &a, std::vector<int> &b) 
{
	std::vector<int> r(l);
	for (int i = 0; i < l; ++i) r[i] = sub(a[i], b[i]);
	return r;
}

void testcase() 
{
	scanf("%d%d", &n, &k);
	int e = 1;
	for (l = 0; e < n; e *= k, ++l);
	std::vector<int> cur(l), inc(l);
	for (int i = 0; i < n; ++i) {
		std::vector<int> q;
		if (i & 1) q = inc - cur;
		else q = inc + cur;
		int qq = 0;
		for (int j = l - 1; j >= 0; --j) {
			qq *= k;
			qq += q[j];
		}
		printf("%d\n", qq);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		if (r) return;
		inc = q - inc;
		int j;
		for (j = 0; j < l; ++j) {
			++cur[j];
			if (cur[j] != k) break;
			cur[j] = 0;
		}
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}