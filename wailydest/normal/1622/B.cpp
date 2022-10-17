#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 200000;
int t, n, p[N], pos[N];
char s[N + 1];

bool cmp(int i, int j) 
{
	return p[i] < p[j];
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			--p[i];
			pos[p[i]] = i;
		}
		scanf("%s", s);
		std::vector<int> a[2];
		for (int i = 0; i < n; ++i) a[s[i] - '0'].push_back(i);
		int amt = 0;
		for (int i = 0; i < 2; ++i) {
			std::sort(a[i].begin(), a[i].end(), cmp);
			for (int j = 0; j < (int)a[i].size(); ++j) p[a[i][j]] = amt++;
		}
		for (int i = 0; i < n; ++i) printf("%d ", p[i] + 1);
		printf("\n");
	}
	return 0;
}