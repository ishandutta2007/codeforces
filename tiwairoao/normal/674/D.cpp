#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100000;
const ll INF = ll(1E15);

struct heap{
	priority_queue<ll>q1, q2;
	
	void maintain() {
		while( !q1.empty() && !q2.empty() && q1.top() == q2.top() )
			q1.pop(), q2.pop();
	}
	bool empty() {maintain(); return q1.empty();}
	ll top() {maintain(); return q1.top();}
	void pop(ll k) {q2.push(k); maintain();}
	void push(ll k) {q1.push(k); maintain();}
	
}h1[MAXN + 5], h2[MAXN + 5], h3, h4;

ll a[MAXN + 5], tg[MAXN + 5];

ll t[MAXN + 5]; int d[MAXN + 5], f[MAXN + 5], n, q;
ll func(int x) {return t[x] / (d[x] + 2);}
ll func2(int x) {return t[x] - t[x] / (d[x] + 2) * (d[x] + 1);}
void pop(int x) {
	if( !h1[x].empty() ) h3.pop(h1[x].top() - tg[x]);
	if( !h2[x].empty() ) h4.pop(h2[x].top() + tg[x]);
}
void push(int x) {
	if( !h1[x].empty() ) h3.push(h1[x].top() - tg[x]);
	if( !h2[x].empty() ) h4.push(h2[x].top() + tg[x]);
}
void pop(int x, ll k) {pop(x), h1[x].pop(-k), h2[x].pop(k), push(x);}
void push(int x, ll k) {pop(x), h1[x].push(-k), h2[x].push(k), push(x);}
void add(int x, ll k) {pop(f[x], a[x]), push(f[x], a[x] += k);}
void update(int x, int k) {
	ll p1 = func(x), p2 = func2(x);
	pop(x), d[x] += k, tg[x] = func(x);
	add(f[x], tg[x] - p1), add(x, func2(x) - p2);
	push(x);
}
void debug() {
	puts("debug : ");
	for(int i=1;i<=n;i++)
		printf("%lld ", a[i] + tg[f[i]]);
	puts("");
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%lld", &t[i]);
	for(int i=1;i<=n;i++) scanf("%d", &f[i]), d[f[i]]++;
	for(int i=1;i<=n;i++) a[f[i]] += func(i), a[i] += func2(i), tg[i] = func(i);
	for(int i=1;i<=n;i++) push(f[i], a[i]);
	for(int i=1;i<=q;i++) {
		int type; scanf("%d", &type);
		if( type == 1 ) {
			int x, y; scanf("%d%d", &x, &y);
			add(f[x], -func(x)), update(f[x], -1), pop(f[x], a[x]);
			push(f[x] = y, a[x]), update(f[x], 1), add(f[x], func(x));
		} else if( type == 2 ) {
			int x; scanf("%d", &x);
			printf("%lld\n", a[x] + tg[f[x]]);
		} else printf("%lld %lld\n", -h3.top(), h4.top());
//		debug();
	}
}