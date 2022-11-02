#include <cstdio>

const int MAXN = 1000000;

typedef long long ll;

double slope(int x1, ll y1, int x2, ll y2) {
	return 1.0 * (y2 - y1) / (x2 - x1);
}

ll s[MAXN + 5]; int n;

int a[MAXN + 5], stk[MAXN + 5], tp;

int get(int x, ll y) {
	int l = 1, r = tp;
	while( l < r ) {
		int mid = (l + r) >> 1;
		if( slope(x, y, stk[mid], s[stk[mid]]) >= slope(stk[mid], s[stk[mid]], stk[mid + 1], s[stk[mid + 1]]) )
			r = mid;
		else l = mid + 1;
	}
	return stk[l];
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		s[i] = s[i-1] + x;
	}
	stk[tp = 1] = n;
	for(int i=n-1;i>=0;i--) {
		a[i] = get(i, s[i]);
		while( tp >= 2 && slope(i, s[i], stk[tp], s[stk[tp]]) >= slope(stk[tp], s[stk[tp]], stk[tp-1], s[stk[tp-1]]) )
			tp--;
		stk[++tp] = i;
	}
	for(int i=1;i<=n;i++) {
		int p = a[i - 1];
		double k = 1.0*(s[p] - s[i-1])/(p - i + 1);
		for(int j=i;j<=p;j++)
			printf("%.10f\n", k);
		i = p;
	}
}