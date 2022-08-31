#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;
const ll inf = 1e18;

ll ans[maxn];
int a[maxn], b[maxn];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	if (k >= 2)
	{
		ll ans = accumulate(a, a + n, 0LL);
		ans -= *min_element(b, b + n - 1);
		ans = max(ans, (ll)a[n - 1] - b[n - 1]);
		ans = max(ans, 0LL);
		printf("%lld\n", ans);
		return 0;
	}
	ll cursum = 0;
	ans[n] = -inf;
	for (int i = n - 1; i >= 0; i--)
	{
		cursum += a[i];
		ans[i] = max(ans[i + 1], cursum - b[i]);
	}
	if (k == 0)
	{
		printf("%lld\n", max(0LL, ans[0]));
		return 0;
	}
	ll answer = max(0LL, ans[n - 1]);
	for (int i = 1; i < n - 1; i++)
	{
		answer = max(answer, cursum - b[0] - a[i]); // skip
		answer = max(answer, cursum - b[0] - b[i]); // skip and take after
		//cout << i << ' ' << answer << endl;
	}
	cursum = a[0];
	int curmin = b[0];
	for (int i = 1; i < n - 1; i++)
	{
		cursum += a[i];
		curmin = min(curmin, b[i]);
		answer = max(answer, ans[i]); // start from i
		ll anscycle = max(0LL, cursum - curmin);
		ll ansback = max(0LL, ans[i + 1]);
		//cout << anscycle << ' ' << ansback << endl;
		answer = max(answer, anscycle + ansback);
	}
	printf("%lld\n", answer);
    return 0;
}