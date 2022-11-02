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

int main() {
	int i, j, n;
	scanf("%d", &n);
	vector<int> v;
	for(i = 0; i < n; i++) {
		int val = 1;
		while(!v.empty() && v.back() == val) val++, v.pop_back();
		v.pb(val);
	}
	for(int val : v)
		printf("%d ", val);
	putchar('\n');
}