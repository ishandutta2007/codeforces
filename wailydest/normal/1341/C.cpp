#include <cstdio>
#include <vector>
using namespace std;

bool solve() 
{
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) pos[p[i]] = i;
	for (int i = 0; i < n - 1; ++i) {
		if (pos[i] != n - 1 && p[pos[i] + 1] > i && p[pos[i] + 1] != i + 1) return false;
	}
	return true;
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		if (solve()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}