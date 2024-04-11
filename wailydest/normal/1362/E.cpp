#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int md = 1000000007;
 
inline int sum(int a, int b) 
{
	a += b;
	return a < md ? a : a - md;
}
inline int sub(int a, int b) 
{
	a -= b;
	if (a < 0) a += md;
	return a;
}
inline int mul(int a, int b) 
{
	return (int)((long long)a * b % md);
}
inline int po(int a, int b) 
{
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

const int N = 1000000;

int a[N];

void testcase() 
{
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	if (p == 1) printf("%d\n", n & 1);
	else {
		sort(a, a + n);
		vector<pair<int, int> > c = {make_pair(*a, 1)};
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[i - 1]) c.push_back(make_pair(a[i], 0));
			++c.back().second;
		}
		n = c.size();
		for (int i = n - 1; i >= 0; --i) {
			c[i].second &= 1;
			if (c[i].second && i) {
				int j = i - 1;
				int deg = c[i].first - 1;
				int to = p;
				bool suc = false;
				do {
					while (deg != c[j].first && to <= N) {
						if (to <= N / p + 1) to *= p;
						else to = N + 1;
						--deg;
					}
					if (to <= N) {
						if (c[j].second >= to) {
							c[j].second -= to;
							suc = true;
						}
						else to -= c[j].second;
						--j;
					}
				} while (to <= N && j >= 0 && !suc);
				if (suc) {
					++j;
					while (j < i) {
						++j;
						c[j].second = 0;
					}
				}
				else break;
			}
		}
		int i = n - 1;
		int an = 0;
		for (i = n - 1; i >= 0 && !c[i].second; --i);
		if (i != -1) {
			an = po(p, c[i].first);
			if (i) do {
				--i;
				an = sub(an, mul(po(p, c[i].first), c[i].second));
			} while (i > 0);
		}
		printf("%d\n", an);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		testcase();
	}
}