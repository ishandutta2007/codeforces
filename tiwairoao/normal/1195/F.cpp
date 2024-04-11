#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int B = 550;
const int N = 100000;
const int M = 300000;

struct query{
	int l, r, i;
	friend bool operator < (const query &a, const query &b) {
		return (a.l / B == b.l / B) ? (a.r < b.r) : (a.l < b.l);
	}
}qry[N + 5];

int ans[N + 5], cnt[M + 5], nwres;
void add(int x, int d) {
	if( (!cnt[x]) && d == 1 ) nwres++;
	cnt[x] += d;
	if( (!cnt[x]) && d == -1 ) nwres--;
}

struct point{
	ll x, y;
	
	friend point operator - (const point &a, const point &b) {return (point){a.x - b.x, a.y - b.y};}
	friend ll operator ^ (const point &a, const point &b) {return a.x*b.y - a.y*b.x;}
	friend bool operator < (const point &a, const point &b) {
		if( a.y >= 0 && b.y < 0 ) return false;
		else if( a.y < 0 && b.y >= 0 ) return true;
		else if( a.y == 0 && b.y == 0 ) return a.x > 0 && b.x < 0;
		else return (a ^ b) > 0;
	}
	friend bool operator == (const point &a, const point &b) {return (a ^ b) == 0;}
}p[M + 5], t[M + 5];

int a[M + 5], le[N + 5], ri[N + 5];
int main() {
	int n, q, s = 0; scanf("%d", &n);
	for(int i=1,m;i<=n;i++) {
		scanf("%d", &m), le[i] = s, ri[i] = s + m - 1;
		for(int j=0;j<m;j++) scanf("%lld%lld", &t[j].x, &t[j].y);
		for(int j=0;j<m;j++) p[s++] = (t[j] - t[(j + 1 == m) ? 0 : j + 1]);
	}
	for(int i=0;i<s;i++) t[i] = p[i];
	sort(p, p + s); int pcnt = unique(p, p + s) - p;
	for(int i=0;i<s;i++) a[i] = lower_bound(p, p + pcnt, t[i]) - p;
	
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		scanf("%d%d", &qry[i].l, &qry[i].r), qry[i].i = i;
		qry[i].l = le[qry[i].l], qry[i].r = ri[qry[i].r];
	}
	sort(qry + 1, qry + q + 1);
	for(int i=1,L=0,R=-1;i<=q;i++) {
		while( L > qry[i].l ) add(a[--L], 1); while( R < qry[i].r ) add(a[++R], 1);
		while( L < qry[i].l ) add(a[L++], -1); while( R > qry[i].r ) add(a[R--], -1);
		ans[qry[i].i] = nwres;
	}
	for(int i=1;i<=q;i++) printf("%d\n", ans[i]);
}