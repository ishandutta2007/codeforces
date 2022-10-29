#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int maxn = 200010;
int n, now, a[maxn], f[maxn];
multiset<int> T;
vector<int> g[maxn];
inline void add(int x) {
	if (x == a[x]) return;
	g[a[x]].push_back(x);
	T.insert(f[x] + 1 + a[x]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	f[1] = 0; now = 1; 
	add(1);
	for (int i = 2; i <= n; ++i) {
		f[i] = i - now + f[now];
		for (unsigned int j = 0; j < g[i].size(); ++j) {
			f[i] = min(f[i], f[g[i][j]] + 1);
			T.erase(T.find(f[g[i][j]] + 1 + i));
		}
		if (T.size()) 
			f[i] = min(f[i], *T.begin() - i);
		add(i);
		if (f[i] - i < f[now] - now) now = i;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
}