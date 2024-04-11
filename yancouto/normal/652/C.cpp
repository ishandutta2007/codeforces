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
const int N = 312345;
int pos[N];
vector<int> st[N];

int main() {
	int i, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &a); a--;
		pos[a] = i;
	}
	multiset<int> s;
	s.insert(n);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(pos[a] > pos[b]) swap(a, b);
		st[pos[a]].pb(pos[b]);
		s.insert(pos[b]);
	}
	ll tot = 0;
	for(i = 0; i < n; i++) {
		tot += (*s.begin()) - i;
		for(int x : st[i])
			s.erase(s.find(x));		
	}
	printf("%I64d\n", tot);
}