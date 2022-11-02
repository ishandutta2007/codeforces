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
typedef list<pii>::iterator lit;

lit its[1000009];
int st[1000009], sn;
list<pii> l;
int a[1000009];

void pop_s() {
	int i = st[--sn];
	lit it = its[i];
	a[next(it)->snd] = -a[next(it)->snd];
	bool fst = it == l.begin();
	lit p = fst? it : prev(it);
	if(!fst && sn && st[sn - 1] == p->snd) sn--;
	it = l.erase(l.erase(it));
	if(fst || it == l.end()) return;
	if(p->fst != it->fst) return;
	st[sn++] = p->snd;
}

int main() {
	int i, n, x, t;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		scanf("%d", &x);
		a[x - 1] = -a[x - 1];
	}
	for(i = 0; i < n; i++) {
		if(a[i] > 0) {
			if(!l.empty() && prev(l.end())->fst == a[i]) st[sn++] = prev(l.end())->snd;
			l.pb(pii(a[i], i));
			its[i] = prev(l.end());
		} else {
			while(!l.empty() && prev(l.end())->fst != -a[i] && sn) pop_s();
			if(l.empty() || prev(l.end())->fst != -a[i]) { puts("NO"); return 0; }
			if(sn && st[sn - 1] == prev(l.end())->snd) sn--;
			l.pop_back();
			if(sn && st[sn - 1] == prev(l.end())->snd) sn--;
		}
	}
	while(!l.empty() && sn) pop_s();
	if(!l.empty()) { puts("NO"); return 0; }
	puts("YES");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}