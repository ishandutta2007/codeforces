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
	vector<int> v, u, v11, v12;
	int i, j, n, x;
	scanf("%d", &n);
	bool h1 = false;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x == 0) continue;
		if(x == 1) h1 = true;
		if(h1) v12.pb(x);
		else v11.pb(x);
	}
	for(int x : v12) v.pb(x);
	for(int x : v11) v.pb(x);
	v11.clear(); v12.clear();
	h1 = false;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x == 0) continue;
		if(x == 1) h1 = true;
		if(h1) v12.pb(x);
		else v11.pb(x);
	}
	for(int x : v12) u.pb(x);
	for(int x : v11) u.pb(x);
	for(i = 0; i < n - 1; i++)
		if(v[i] != u[i])
			break;
	if(i < n - 1) puts("NO");
	else puts("YES");
}