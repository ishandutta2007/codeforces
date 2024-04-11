#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll val[200009];
int d[200009];

int main() {
	int i, n, b, t;
	scanf("%d %d", &n, &b);
	set<pii> s;
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &t, &d[i]);
		s.insert(pii(t, i));
	}
	queue<int> q;
	bool used = false;
	while(!s.empty()) {
		pii ev = *s.begin(); s.erase(s.begin());
		if(ev.snd < 0) {
			val[-ev.snd] = ev.fst;
			if(q.empty()) used = false;
			else s.insert(pii(ev.fst + d[q.front()], -q.front())), q.pop();
		} else {
			if(!used) used = true, s.insert(pii(ev.fst + d[ev.snd], -ev.snd));
			else if(q.size() < b) q.push(ev.snd);
			else val[ev.snd] = -1;
		}
	}
	for(i = 1; i <= n; i++)
		printf("%I64d ", val[i]);
	putchar('\n');
}