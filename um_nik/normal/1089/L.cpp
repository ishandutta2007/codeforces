#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
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

pair2<int> b[maxn];
int cnt[maxn];
int a[maxn];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i =0 ; i < n; i++) scanf("%d", &a[i]), a[i]--, cnt[a[i]]++;
	for (int i = 0; i < n; i++) scanf("%d", &b[i].first), b[i].se = i;
	sort(b, b + n);
	int ok = 0;
	for (int i = 0; i < k; i++) if (cnt[i] > 0) ok++;
	ll answer = 0;
	for (int i = 0; i < n && ok < k; i++)
	{
		int id = b[i].se;
		if (cnt[a[id]] > 1)
		{
			ok++;
			answer += b[i].fi;
			cnt[a[id]]--;
		}
	}
	assert(ok == k);
	cout << answer << endl;
    return 0;
}