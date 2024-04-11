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

int n, st, x;

pii Ask(int x) {
	if (x < 0) return {1e9 + 5, -1};
	printf("? %d\n", x + 1);
	fflush(stdout);
	pii ret;
	scanf("%d%d", &ret.fi, &ret.se);
	return ret;
}

void no() {
	printf("! -1");
	fflush(stdout);
	exit(0);
}

int main()
{
	scanf("%d%d%d", &n, &st, &x);
	int val = -1, ind = st - 1;
	for (int i = 0; i < 1000; i++) {
		int pos = (rng() + rng() + rng() + rng()) % n;
		pii Q = Ask(pos);
		if (Q.fi <= x && val <= Q.fi) {
			val = Q.fi;
			ind = Q.se - 1;
		}
	}
	if (val >= x) {
		printf("! %d", val);
		fflush(stdout);
		return 0;
	}
	int qq = 1000;
	while (qq + 1 < 2000 && val < x) {
		qq++;
		pii Q = Ask(ind);
		val = Q.fi;
		ind = Q.se - 1;
	}
	if (val >= x && val < 1e9 + 5) {
		printf("! %d", val);
		fflush(stdout);
		return 0;
	}
	no();
	return 0;
}