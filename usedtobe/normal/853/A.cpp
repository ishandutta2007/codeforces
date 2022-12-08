#include<bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef long long ll;
const int N = 633333;
int n, k, a[N], res[N];
set<pair<int, int> > S;
set<pair<int, int> >::iterator it;
ll ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= k; ++i) S.insert(mp(a[i], i));
	for (int i = k + 1; i <= k + n; ++i) {
		if (i <= n) S.insert(mp(a[i], i));
		it = S.end();
		it--;
		ans += 1ll * it->X * (i - it->Y);
		res[it->Y] = i;
		S.erase(it);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) printf("%d ", res[i]);
	puts("");
	return 0;
}