#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 200005;
int n, l[N], r[N], d[N];

int main() 
{
	scanf("%d", &n);
	memset(l, -1, n << 2);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		if (l[x] == -1) l[x] = i;
		r[x] = i;
	}
	std::vector<std::pair<int, int> > vec;
	for (int i = 0; i < n; ++i) if (l[i] != -1) vec.push_back(std::make_pair(l[i], r[i]));
	std::sort(vec.begin(), vec.end());
	std::vector<std::pair<int, int> > a;
	int total = 0;
	for (int i = 0; i < (int)vec.size(); ++i) if (a.empty() || vec[i].second > a.back().second) {
		a.push_back(vec[i]);
		total += (vec[i].first != vec[i].second) + 1;
	}
	for (int i = 1, j = 0; i < (int)a.size(); ++i) {
		while (a[j].second < a[i].first) ++j;
		if (j == i) d[i] = d[i - 1];
		else d[i] = 1 + 2 * (i - j - 1) + d[j];
	}
	printf("%d\n", n - total + d[(int)a.size() - 1]);
	return 0;
}