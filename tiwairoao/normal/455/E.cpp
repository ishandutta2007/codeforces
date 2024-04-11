#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define lch (x<<1)
#define rch (x<<1|1)
typedef long long ll;
const int MAXN = 100000;
struct point{
	ll x, y;
	point(ll _x=0, ll _y=0):x(_x), y(_y) {}
	friend bool operator < (point a, point b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
	}
};
long double slope(point a, point b) {
	return ((long double)(b.y - a.y)) / (b.x - a.x);
}
int s[MAXN + 5], a[MAXN + 5], n, m;
int le[4*MAXN + 5], ri[4*MAXN + 5];
vector<point>A[4*MAXN + 5], tmp;
void build(int x, int l, int r) {
	le[x] = l, ri[x] = r; tmp.clear();
	for(int i=l;i<=r;i++)
		tmp.push_back(point(a[i], -s[i-1] + (i-1)*a[i]));
	sort(tmp.begin(), tmp.end());
	for(int i=0;i<tmp.size();i++) {
		if( !A[x].size() ) A[x].push_back(tmp[i]);
		else {
			if( tmp[i].x != A[x][A[x].size() - 1].x ) {
				while( A[x].size() >= 2 ) {
					int m = A[x].size();
					if( slope(A[x][m-2], A[x][m-1]) >= slope(A[x][m-1], tmp[i]) ) A[x].pop_back();
					else break;
				}
				A[x].push_back(tmp[i]);
			}
		}
	}
	if( l == r ) return ;
	int mid = (l + r) >> 1;
	build(lch, l, mid), build(rch, mid + 1, r);
}
ll query(point a, int k) {return a.y - k*a.x;}
ll query(const vector<point>&v, int k) {
	int l = 0, r = v.size() - 1;
	while( l < r ) {
		int mid = (l + r) >> 1;
		if( slope(v[mid], v[mid + 1]) >= k ) r = mid;
		else l = mid + 1;
	}
	return query(v[r], k);
}
ll query(int x, int l, int r, int k) {
	if( l <= le[x] && ri[x] <= r )
		return query(A[x], k);
	int mid = (le[x] + ri[x]) >> 1;
	if( r <= mid ) return query(lch, l, r, k);
	else if( l > mid ) return query(rch, l, r, k);
	else return min(query(lch, l, r, k), query(rch, l, r, k));
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]), s[i] = s[i-1] + a[i];
	build(1, 1, n);
	scanf("%d", &m);
	for(int i=1;i<=m;i++) {
		int x, y; scanf("%d%d", &x, &y);
		/*int ans = inf;
		for(int j=y;j>=y-x+1;j--)
			ans = min(ans, int(Y(j) - (y-x)*X(j))); // b = y - kx, y = kx + b.
		printf("%d\n", ans + s[y]);*/
		printf("%lld\n", query(1, y-x+1, y, y-x) + s[y]);
	}
}