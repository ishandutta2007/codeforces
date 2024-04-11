#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)1e16;

const int N = 3030;
int n, m, k;
pii a[N];
bool used[N];
vector<int> b[N];
int hav;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 1)
			hav++;
		else
			a[k++] = mp(y, x - 1);
	}

	ll ans = INF;

	sort(a, a + k);
	for (int i = k - 1; i >= 0; i--)
		b[a[i].second].push_back(i);

	for (int w = 0; w <= n; w++) {
		for (int i = 0; i < k; i++)
			used[i] = false;
		int cnt = hav;
		ll cur = 0;
		for (int id = 1; id < m; id++) {
			for (int i = (int)b[id].size() - 1; i >= w; i--) {
				cur += a[b[id][i]].first;
				used[b[id][i]] = 1;
				cnt++;
			}
		}
		for (int i = 0; cnt <= w && i < k; i++) {
			if (used[i]) continue;
			cnt++;
			cur += a[i].first;
		}
		if (cnt > w)
			ans = min(ans, cur);
	}
	printf("%lld\n", ans);

	return 0;
}