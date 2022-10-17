#include <cstdio>
#include <map>
using namespace std;

const int md = 998244353;

inline int mul(int a, int b) 
{
	return (int)((long long)a * b % md);
}

const int N = 200000;
int a[N];
int b[N];
map<int, int> ps;

pair<int, int> seg[N];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		ps[a[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
		if (!ps.count(b[i])) {
			printf("0\n");
			return 0;
		}
	}
	int border = n - 1;
	for (int i = m - 1; i >= 0; --i) {
		seg[i].second = ps[b[i]];
		int j;
		for (j = border; j >= 0 && a[j] >= b[i]; --j);
		if (j > seg[i].second) {
			printf("0\n");
			return 0;
		}
		seg[i].first = j + 1;
		border = j;
	}
	if (border != -1) {
		printf("0\n");
		return 0;
	}
	int ans = 1;
	for (int i = 1; i < m; ++i) {
		ans = mul(ans, seg[i].second - seg[i].first + 1);
	}
	printf("%d\n", ans);
	return 0;
}