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

vector<int> C[N];
int ok[N], cn;
int main() {
	set<pii> e;
	int i, n, m, k, a, b;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		e.insert(pii(a - 1, b - 1));
	}
	deque<int> v;
	for(i = 1; i < n; i++) v.pb(i);
	for(i = 1; i < n; i++)
		if(!v.empty() && v.front() == i) {
			vector<int> &c = C[cn++];
			c.pb(i);
			vector<int> q;
			q.pb(i);
			v.pop_front();
			while(!q.empty()) {
				int u = q.back(); q.pop_back();
				deque<int> v2;
				for(int w : v) {
					a = w; b = u;
					if(a > b) swap(a, b);
					if(!e.count(pii(a, b))) q.pb(w), c.pb(w);
					else v2.pb(w);
				}
				v2.swap(v);
			}
		}
	if(cn > k) { puts("impossible"); return 0; }
	int con = 0;
	for(i = 1; i < n; i++)
		if(!e.count(pii(0, i)))
			ok[i] = 1, con++;
	if(con < k) { puts("impossible"); return 0; }
	for(i = 0; i < cn; i++) {
		bool any = false;
		for(int u : C[i])
			any |= ok[u];
		if(!any) { puts("impossible"); return 0; }
	}
	puts("possible");
}