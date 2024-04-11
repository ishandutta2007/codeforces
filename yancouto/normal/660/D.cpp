#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num dist_sqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pti;
const int N = 2123;

pti p[N];

int main() {
	int i, n, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p + n);
	map<pti, int> mp;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			mp[p[j] - p[i]]++;
	ll tot = 0;
	for(auto &it : mp)
		tot += (ll(it.snd) * ll(it.snd - 1)) / 2ll;
	printf("%I64d\n", tot / 2ll);
}