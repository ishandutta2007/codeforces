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
const ull modn = 1000000009;
inline ull mod(ull x) { return x % modn; }

map<int, int> sx[100009];
set<int> s;
int us[100009], x[100009], y[100009];
int num_hold(int g) {
	int ct = 0;
	for(int i = -1; i <= 1; i++)
		if(sx[y[g] - 1].count(x[g] + i))
			ct++;
	return ct;
}

bool safe(int g) {
	for(int i = -1; i <= 1; i++)
		if(sx[y[g] + 1].count(x[g] + i) && num_hold(sx[y[g] + 1][x[g] + i]) == 1)
			return false;
	return true;
}

int main() {
	int i, m;
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		sx[y[i]][x[i]] = i;
	}
	for(i = 0; i < m; i++) {
		if(safe(i))
			s.insert(i);
	}
	ull num = 0;
	bool mx = true;
	while(!s.empty()) {
		int a = (mx? *s.rbegin() : *s.begin()); 
		s.erase(a); sx[y[a]].erase(x[a]); us[a] = true;
		num = mod(num * ull(m) + a);
		mx = !mx;
		for(i = -2; i <= 2; i++) {
			if(!sx[y[a]].count(x[a] + i)) continue;
			int g = sx[y[a]][x[a] + i];
			if(!s.count(g)) continue;
			if(!safe(g)) s.erase(g);
		}
		if(y[a] == 0) continue;
		for(i = -1; i <= 1; i++) {
			if(!sx[y[a] - 1].count(x[a] + i)) continue;
			int g = sx[y[a] - 1][x[a] + i];
			if(s.count(g) || us[g]) continue;
			if(safe(g)) s.insert(g);
		}
	}
	printf("%I64u\n", num);
}