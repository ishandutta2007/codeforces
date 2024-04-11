#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

map<int, int> mp;
vector<int> rm[400009], ad[400009];
int x[200009], r[200009];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &r[i]);
		mp[x[i] - r[i]] = mp[x[i] + r[i]] = 0;
	}
	i = 0;
	for(auto &e : mp)
		e.snd = i++;
	for(i = 0; i < n; i++) {
		rm[mp[x[i] + r[i]]].pb(i);
		ad[mp[x[i] - r[i]]].pb(i);
	}
	set<int> cur;
	int sz = 0;
	for(i = 0; i < 400009; i++) {
		bool a = false;
		for(int v : rm[i])
			if(cur.count(v)) {
				a = true;
				break;
			}
		if(a) { cur.clear(); sz++; }
		for(int v : ad[i])
			cur.insert(v);
	}
	printf("%d\n", sz);
}