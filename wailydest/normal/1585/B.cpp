#include <cstdio>
#include <vector>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		std::vector<int> v;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			while (!v.empty() && v.back() <= x) v.pop_back();
			v.push_back(x);
		}
		printf("%d\n", (int)v.size() - 1);
	}
	return 0;
}