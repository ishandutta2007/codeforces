#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 19;

char S[N];

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%s", S);
		int len = strlen(S);
		int ans = N;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				int no = (S[i] - '0') * 10 + (S[j] - '0');
				if (no % 25 == 0) {
					ans = min(ans, j - i - 1 + len - j - 1);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}