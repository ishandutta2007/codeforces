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
const int N = 112345;
int p[N];
int bit[N];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
void add(int i, int v) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += v;
}

int n;
//ll all(int k, vector<int> v) {
//	int i, j;
//	if(k == 0) {
//		for(i = 0; i < N; i++) bit[i] = 0;
//		ll tot = 0;
//		for(i = 0; i < n; i++) {
//			tot += get(n) - get(v[i]);
//			add(v[i], 1);
//		}
//		return tot;
//	}
//	ll mx = all(0, v);
//	for(i = 0; i < n; i++)
//		for(j = i + 1; j < n; j++) {
//			vector<int> v2 = v;
//			swap(v2[i], v2[j]);
//			mx = max(mx, all(k - 1, v2));
//		}
//	return mx;
//}

int main() {
	int i, k;
	scanf("%d %d", &n, &k);
	//vector<int> v;
	for(i = 0; i < n; i++) p[i] = i;//, v.pb(i);
	for(i = 0; i < k && i < n / 2; i++)
		swap(p[i], p[n - 1 - i]);
	ll tot = 0;
	for(i = 0; i < n; i++) {
		tot += get(n) - get(p[i]);
		add(p[i], 1);
	}
	printf("%I64d\n", tot);
}