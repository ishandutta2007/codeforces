#include <cstdio>
#include <utility>
#include <vector>

const int md = 998244353;

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

const int N = 200005;
int n, s[N], ws[N];

int eval(int l, int r) 
{
	if (l < 0) return ws[r];
	if ((l ^ r) & 1) return add(ws[r], ws[l]);
	return sub(ws[r], ws[l]);
}

int main() 
{
	scanf("%d", &n);
	std::vector<std::pair<int, int> > v;
	v.push_back(std::pair<int, int>());
	s[0] = 1;
	ws[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		s[i] = s[i - 1];
		while (x < v.back().first) {
			s[i] = sub(s[i], mul(eval(v.back().second, i - 2), v.back().first - std::max(v[(int)v.size() - 2].first, x)));
			if (x <= v[(int)v.size() - 2].first) v.pop_back();
			else v.back().first = x;
		}
		if (x != v.back().first) v.push_back(std::make_pair(x, i - 2));
		s[i] = sub(mul(s[i - 1], x), i == 1 ? 0 : s[i]);
		ws[i] = sub(s[i], ws[i - 1]);
	}
	printf("%d\n", s[n]);
	return 0;
}