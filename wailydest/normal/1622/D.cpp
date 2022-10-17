#include <cstdio>
#include <vector>
#include <algorithm>

const int md = 998244353;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}

const int N = 5005;
int n, k, nCr[N][N];
char s[N];

int main() 
{
	for (int i = 0; i < N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) nCr[i][j] = add(nCr[i - 1][j], nCr[i - 1][j - 1]);
	}
	scanf("%d%d%s", &n, &k, s);
	std::vector<int> a;
	a.push_back(0);
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '1') a.push_back(0);
		else ++a.back();
	}
	int s = 0, ans = 1;
	if (a.size() - 1 >= k) for (int i = 0; i < (int)a.size(); ++i) {
		s += a[i];
		if (i) for (int j = 0; j <= s; ++j) if (j != a[i]) ans = add(ans, nCr[std::min(i, k) + s - j - 1][s - j]);
		if (i >= k) s -= a[i - k];
	}
	printf("%d\n", ans);
	return 0;
}