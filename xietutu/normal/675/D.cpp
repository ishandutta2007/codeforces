#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map> 
using namespace std;
const int maxn = 100010;
typedef pair<int, int> pii;
map<pii, int> M;
int n, a[maxn], v[maxn];
int main() {
    scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		v[i] = a[i];
	}
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(v + 1, v + n + 1, a[i]) - v;
	
	int st = 1, ed = a[1] - 1;
	if (st <= ed) M[make_pair(st, ed)] = a[1];
	st = a[1] + 1; ed = n;
	if (st <= ed) M[make_pair(st, ed)] = a[1];
	for (int i = 2; i <= n; ++i) {
		int x = a[i];
		map<pii, int>::iterator it = M.upper_bound(make_pair(x, n));
		--it;
		int l = it->first.first, r = it->first.second;
		printf("%d ", v[it->second]);
		M.erase(it);
		if (l <= x - 1) M.insert(make_pair(make_pair(l, x - 1), x));
		if (x + 1 <= r) M.insert(make_pair(make_pair(x + 1, r), x));
	}
}