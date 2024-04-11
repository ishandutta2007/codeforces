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

const ll INF = (ll)1e17;

const int N = 100100;
map<string, int> mapchik;
int n, m, k;
ll a[N];
ll b[N];
ll c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mapchik[s] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++) {
		c[i] = INF;
		int z;
		cin >> z;
		while(z--) {
			int p;
			cin >> p;
			p--;
			b[p] = i;
			c[i] = min(c[i], a[p]);
		}
	}
	ll ans = 0;
	while(m--) {
		string s;
		cin >> s;
		int x = mapchik[s];
		ans += c[b[x]];
	}
	cout << ans << endl;

	return 0;
}