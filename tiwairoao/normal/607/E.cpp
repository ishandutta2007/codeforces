#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define double long double

const int MAXN = 100000;
const double EPS = 1E-16;
const double PI = acos(-1);

int dcmp(double x) {
	return (fabs(x) <= EPS ? 0 : (x < 0 ? -1 : 1));
}

int n, m; double K[MAXN + 5], B[MAXN + 5];

double t[MAXN + 5]; int cnt;
bool cmp(double a, double b) {return dcmp(a - b) < 0;}
bool cmp2(double a, double b) {return dcmp(a - b) == 0;}

int tree[MAXN + 5], le[MAXN + 5], ri[MAXN + 5];
int lowbit(int x) {
	return x & -x;
}
int sum(int x) {
	int ret = 0;
	for(int i=x;i;i-=lowbit(i))
		ret += tree[i];
	return ret;
}
void update(int x, int k) {
	for(int i=x;i<=cnt;i+=lowbit(i))
		tree[i] += k;
}

int tmp[MAXN + 5];
vector<int>v1[MAXN + 5], v2[MAXN + 5];
bool check(double r) {
	cnt = 0;
	for(int i=1;i<=n;i++) {
		double del = K[i]*K[i]*r*r + r*r - B[i]*B[i];
		if( dcmp(del) >= 0 ) {
			double frac = K[i]*K[i] + 1; del = sqrt(del);
			double x1 = -(del + B[i]*K[i])/frac, y1 = -(K[i]*del - B[i])/frac;
			t[++cnt] = atan2(y1, x1);
			double x2 = -(-del + B[i]*K[i])/frac, y2 = (K[i]*del + B[i])/frac;
			t[++cnt] = atan2(y2, x2);
		}
	}
	sort(t + 1, t + cnt + 1, cmp);
	cnt = unique(t + 1, t + cnt + 1, cmp2) - t - 1;
	for(int i=1;i<=cnt;i++)
		tree[i] = tmp[i] = 0, v1[i].clear(), v2[i].clear();
	for(int i=1;i<=n;i++) {
		double del = K[i]*K[i]*r*r + r*r - B[i]*B[i];
		if( dcmp(del) >= 0 ) {
			double frac = K[i]*K[i] + 1; del = sqrt(del);
			double x1 = -(del + B[i]*K[i])/frac, y1 = -(K[i]*del - B[i])/frac;
			int p = lower_bound(t + 1, t + cnt + 1, atan2(y1, x1), cmp) - t;
			double x2 = -(-del + B[i]*K[i])/frac, y2 = (K[i]*del + B[i])/frac;
			int q = lower_bound(t + 1, t + cnt + 1, atan2(y2, x2), cmp) - t;
			le[i] = min(p, q), ri[i] = max(p, q);
			v1[le[i]].push_back(i), v2[ri[i]].push_back(i);
			tmp[le[i]]++;
			if( le[i] != ri[i] ) tmp[ri[i]]++;
		}
	}
	int tot = 0;
	for(int i=1;i<=cnt;i++) {
		for(int j=0;j<v1[i].size();j++) update(i, 1);
		for(int j=0;j<v2[i].size();j++)
			update(le[v2[i][j]], -1), tot += sum(i-1) - sum(le[v2[i][j]]);
		tot += 1LL*tmp[i]*(tmp[i] - 1)/2;
	}
	return tot >= m;
}

struct node{
	int le, ri, id;
	friend bool operator < (node a, node b) {return a.ri < b.ri;}
}b[MAXN + 5], c[MAXN + 5];
double ans; int nw;

double intersect(int i, int j) {
	double x = (B[j] - B[i]) / (K[i] - K[j]);
	double y = K[i] * x + B[i];
	return sqrt(x*x + y*y);
}

void solve(int le, int ri) {
	if( le == ri ) return ;
	int m = (le + ri) >> 1;
	solve(le, m), solve(m + 1, ri);
	
	int p = le, q = m + 1, t = le;
	while( p <= m && q <= ri ) {
		if( b[p].le < b[q].le ) {
			for(int i=q;i<=ri;i++) {
				if( b[i].le >= b[p].ri ) break;
				if( b[p].ri < b[i].ri ) nw++, ans += intersect(b[p].id, b[i].id);
			}
			c[t++] = b[p++];
		}
		else c[t++] = b[q++];
	}
	while( p <= m ) c[t++] = b[p++];
	while( q <= ri ) c[t++] = b[q++];
	for(int i=le;i<=ri;i++) b[i] = c[i];
}

double get(double r) {
	cnt = 0;
	for(int i=1;i<=n;i++) {
		double del = K[i]*K[i]*r*r + r*r - B[i]*B[i];
		if( dcmp(del) >= 0 ) {
			double frac = K[i]*K[i] + 1; del = sqrt(del);
			double x1 = -(del + B[i]*K[i])/frac, y1 = -(K[i]*del - B[i])/frac;
			t[++cnt] = atan2(y1, x1);
			double x2 = -(-del + B[i]*K[i])/frac, y2 = (K[i]*del + B[i])/frac;
			t[++cnt] = atan2(y2, x2);
		}
	}
	sort(t + 1, t + cnt + 1, cmp);
	cnt = unique(t + 1, t + cnt + 1, cmp2) - t - 1;
	int tot = 0;
	for(int i=1;i<=n;i++) {
		double del = K[i]*K[i]*r*r + r*r - B[i]*B[i];
		if( dcmp(del) >= 0 ) {
			double frac = K[i]*K[i] + 1; del = sqrt(del);
			double x1 = -(del + B[i]*K[i])/frac, y1 = -(K[i]*del - B[i])/frac;
			int p = lower_bound(t + 1, t + cnt + 1, atan2(y1, x1), cmp) - t;
			double x2 = -(-del + B[i]*K[i])/frac, y2 = (K[i]*del + B[i])/frac;
			int q = lower_bound(t + 1, t + cnt + 1, atan2(y2, x2), cmp) - t;
			tot++, b[tot].le = min(p, q), b[tot].ri = max(p, q), b[tot].id = i;
		}
	}
	sort(b + 1, b + tot + 1), solve(1, tot);
	return ans + 1.0*(m - nw)*r;
}

int read() {
	int x = 0, f = 1; char ch = getchar();
	while( (ch != '-') && (ch > '9' || ch < '0') ) ch = getchar();
	if( ch == '-' ) f = -1, ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10*x + ch - '0', ch = getchar();
	return x * f;
}

int main() {
	double x, y;
	n = read(), x = 1.0*read()/1000, y = 1.0*read()/1000, m = read();
	for(int i=1;i<=n;i++) {
		K[i] = 1.0*read()/1000, B[i] = 1.0*read()/1000;
		B[i] = K[i]*x + B[i] - y;
	}
/*
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++)
			printf("%d %d : ", i, j), cout << dist(intersect(l[i], l[j]), pnt)  << endl;
		cout << i << " " << (pnt - a[i]) * l[i].ab << endl;
	}
*/
	double le = 0, ri = 2E9 + 5000;
	for(int i=0;i<=50;i++) {
		double mid = (le + ri) / 2;
		if( check(mid) ) ri = mid;
		else le = mid;
	}
	cout << fixed << setprecision(9) << get(le) << endl;
}