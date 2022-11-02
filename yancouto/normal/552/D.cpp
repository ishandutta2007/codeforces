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
template<typename num> struct point {
	num x, y;
	point() {}
	point(num a, num b) : x(a), y(b) {}
	point operator + (point o) const { return point(x + o.x, y + o.y); }
	point operator - (point o) const { return point(x - o.x, y - o.y); }
	num operator * (point o) const { return x * o.x + y * o.y; }
	num operator ^ (point o) const { return x * o.y - y * o.x; }
	point operator * (num i) const { return point(x * i, y * i); }
	point operator / (num i) const { return point(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(point o) const { return (*this - o) * (*this - o); }
	bool operator < (point o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pointi;
int n;
pointi ps[2003];
pointi p;
bool cmp(pointi p1, pointi p2) {
	return ((p1 - p) ^ (p2 - p)) < 0;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &ps[i].x, &ps[i].y);
	ull tot = 0;
	while(n >= 3) {
		int a = 0;
		for(i = 1; i < n; i++)
			if(ps[i] < ps[a])
				a = i;
		swap(ps[--n], ps[a]);
		p = ps[n];
		sort(ps, ps + n, cmp);
		j = 0;
		while(j < n) {
			int sz = 1; j++;
			while(j < n && ((ps[j] - p) ^ (ps[j - 1] - p)) == 0) j++, sz++;
			tot += sz * (n - sz);
		}
	}
	printf("%d\n", int(tot / 2));
	return 0;
}