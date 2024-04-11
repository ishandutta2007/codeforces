#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> children;
	for (int i = 0; i < n; ++i) {
		children.push_back(i + 1);
	}
	int pt = 0;
	for (int i = 0; i < k; ++i) {
		int a;
		scanf("%d", &a);
		pt = (pt + a) % children.size();
		int ans = children[pt];
		children.erase(children.begin() + pt);
		printf("%d%c", ans, i == k - 1 ? '\n' : ' ');
	}
	return 0;
}