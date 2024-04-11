#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 201000;
int n, m, a[maxn];
map<int, int> M;
pair<pair<int, int>, int> d[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		++M[a[i]];
	}
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) 
		d[i].second = i;
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		d[i].first.first = M[x];
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		d[i].first.second = M[x];
	}
	sort(d + 1, d + m + 1);
	printf("%d\n", d[m].second);
}