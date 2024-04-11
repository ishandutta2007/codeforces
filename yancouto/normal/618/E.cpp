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
const int N = 300009;

struct comp {
	comp() {}
	comp(double x, double y) : a(x), b(y) {}
	double a, b;
	comp operator + (comp o) const {
		return comp(a + o.a, b + o.b);
	}
	comp operator - (comp o) const {
		return comp(a - o.a, b - o.b);
	}
	comp operator * (double d) const {
		return comp(a * d, b * d);
	}
	double len() const { return sqrt(a * a + b * b); }
	comp norm() const {
		return (*this) * (1. / len());
	}
	comp operator * (comp o) const {
		return comp(a * o.a - b * o.b, o.a * b + a * o.b);
	}
};
inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) + 1; }

comp tr[N];
comp la[N << 2], lb[N << 2]; // a * x + b
bool lazy[N << 2];
int n;

void unlaze(int i, int l, int r) {
	if(!lazy[i]) return;
	//printf("unlazing %d (%d, %d)\n", i, l, r);
	if(l == r) tr[l] = ((tr[l] * la[i]) + lb[i]);
	else for(int j = L(i); j <= R(i); j++) {
		lb[j] = (lb[j] * la[i]) + lb[i];
		la[j] = la[j] * la[i];
		lazy[j] = true;
	}
	la[i] = comp(1, 0);
	lb[i] = comp(0, 0);
	lazy[i] = false;
}

comp get(int x) {
	int i = 1, l = 0, r = n - 1;
	while(l < r) {
		//printf("looking at (%d, %d)\n", l, r);
		unlaze(i, l, r);
		int m = (l + r) / 2;
		if(x <= m) i = L(i), r = m;
		else l = m + 1, i = R(i);
		//printf(">looking at (%d, %d)\n", l, r);
	}
	unlaze(i, l, r);
	return tr[x];
}

void upd(int i, int l, int r, int ql, int qr, comp a, comp b) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		//printf("setting %d (%d, %d)\n", i, l, r);
		lazy[i] = true;
		la[i] = a; lb[i] = b;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(L(i), l, m, ql, qr, a, b);
	upd(R(i), m + 1, r, ql, qr, a, b);
}

void build(int i, int l, int r) {
	la[i] = comp(1, 0); lb[i] = comp(0, 0);
	if(l == r) return (void) (tr[l] = comp(l, 0));
	int m = (l + r) / 2;
	build(L(i), l, m);
	build(R(i), m + 1, r);
}

const double pi = acos(-1);
const double torad = pi / 180.;

int main() {
	int i, m, x, y, z;
	scanf("%d %d", &n, &m); n++;
	build(1, 0, n - 1);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		comp a = get(y - 1), b = get(y);
		if(x == 1) {
			upd(1, 0, n - 1, y, n - 1, comp(1, 0), (b - a).norm() * z);
		} else {
			double ang = 2.*pi - z * torad;
			upd(1, 0, n - 1, y, n - 1, comp(1, 0), (comp(0, 0) - a));
			upd(1, 0, n - 1, y, n - 1, comp(cos(ang), sin(ang)), a);
		}
		comp c = get(n - 1);
		printf("%.10f %.10f\n", c.a, c.b);
	}
}