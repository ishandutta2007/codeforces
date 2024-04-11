// 
#include <cstdio>
#include <algorithm>
#include <vector>

static const int MAXN = 1e5 + 3;
static const int INF32 = 0x7fffffff;
typedef long long int64;

static int n, l, w;
static int x[MAXN], v[MAXN];
static std::vector<int> pos, neg;

inline int div_floor(int64 a, int b)
{
	if (b == 0) return (a > 0 ? +INF32 : -INF32);
	if (a % b < 0) a -= (b + a % b);
	return a / b;
}

int main()
{
	scanf("%d%d%d", &n, &l, &w);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &v[i]);
		(v[i] == +1 ? pos : neg).push_back(x[i]);
	}
	std::sort(pos.begin(), pos.end());
	std::sort(neg.begin(), neg.end());
	
	int64 ans = 0;
	for (int v : neg) {
		auto barrier = std::lower_bound(pos.begin(), pos.end(), -v - l);
		int u_max_0 = div_floor((int64)(v + l) * (w + 1) - 1, w - 1),
		u_max_1 = div_floor((int64)(v + l) * (w - 1) - 1, w + 1);
		ans +=
		(std::upper_bound(pos.begin(), barrier, u_max_0) - pos.begin()) +
		(std::upper_bound(barrier, pos.end(), std::min(v, u_max_1)) - barrier);
	}
	
	printf("%lld\n", ans);
	return 0;
}