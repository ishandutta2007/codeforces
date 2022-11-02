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
const int N = 1000009;
pii ps[N]; int pn;

int main() {
	int i, n, k, a, b;
	scanf("%d %d", &n, &k);
	map<int, int> mp;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		mp[2*a]++;
		mp[2*b + 1]--;
	}
	int lst = INT_MIN;
	int cur = 0;
	for(auto p : mp) {
		cur += p.snd;
		if(lst != INT_MIN && cur < k) {
			ps[pn++] = pii(lst/2, (p.fst - 1) / 2);
			lst = INT_MIN;
		} else if(lst == INT_MIN && cur >= k)
			lst = p.fst;
	}
	printf("%d\n", pn);
	for(i = 0; i < pn; i++)
		printf("%d %d\n", ps[i].fst, ps[i].snd);
}