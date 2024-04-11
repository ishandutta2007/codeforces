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

const int maxn = 1005;

int p[2 * maxn], q[2 * maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < 2 * n; i++) q[i] = p[i];
	int answer = 10 * n;
	for (int IT = 0; IT < 2; IT++)
	{
		int t = IT;
		for (int i = 0; i < 2 * n; i++) p[i] = q[i];
		for (int i = 0; i < 10 * n; i++)
		{
			bool ok = true;
			for (int j = 0; j < 2 * n; j++) ok &= (p[j] == j + 1);
			if (ok)
			{
				answer = min(answer, i);
				break;
			}
			if (t == 0)
			{
				for (int j = 0; j < 2 * n; j += 2) swap(p[j], p[j + 1]);
			} else
			{
				for (int j = 0; j < n; j++) swap(p[j], p[n + j]);
			}
			t ^= 1;
		}
	}
	if (answer == 10 * n) answer = -1;
	cout << answer << endl;
    return 0;
}