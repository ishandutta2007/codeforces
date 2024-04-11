#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 500000;
const int MAXM = 2*MAXN;

int z[MAXM + MAXN + 5];
char str[MAXM + MAXN + 5];

void getZ(int len) {
	int pos = 0, mxl = -1;
	for(int i=1;i<len;i++) {
		z[i] = (mxl >= i ? min(mxl - i + 1, z[i - pos]) : 0);
		while( str[z[i]] == str[i+z[i]] ) z[i]++;
		if( mxl < i + z[i] - 1 ) pos = i, mxl = i + z[i] - 1;
	}
}
void get(char *S, int lenS, char *T, int lenT, int *f) {
	for(int i=0;i<lenS;i++) str[i] = S[i];
	str[lenS] = 1;
	for(int i=0;i<lenT;i++) str[lenS+1+i] = T[i];
	getZ(lenS + lenT + 1);
	for(int i=0;i<lenT;i++) f[i] = z[lenS+1+i];
}

int n, m; ll T[2][MAXM + 5];
int lowbit(int x) {return (x & -x);}
void add(int x, ll d, int t) {
	for(int i=x;i<=m;i+=lowbit(i))
		T[t][i] += d;
}
void modify(int l, int r, ll d) {
	add(l, d, 0), add(l, d*l, 1);
	add(r + 1, -d, 0), add(r + 1, -d*(r + 1), 1);
}
ll sum(int x, int t) {
	ll ret = 0;
	for(int i=x;i;i-=lowbit(i))
		ret += T[t][i];
	return ret;
}
ll query(int l, int r) {
	ll A = l*sum(l - 1, 0) - sum(l - 1, 1);
	ll B = (r + 1)*sum(r, 0) - sum(r, 1);
	return B - A;
}

char a[MAXN + 5], b[MAXN + 5], s[MAXM + 5];
int af[MAXN + 5], bf[MAXN + 5];
int main() {
	scanf("%d%d%s%s%s", &n, &m, a, b, s);
	get(s, m, a, n, af);
	reverse(b, b + n), reverse(s, s + m);
	get(s, m, b, n, bf);
	reverse(bf, bf + n);
	ll ans = 0;
	for(int i=n-1;i>=0;i--) {
		modify(max(m - bf[i], 1), m - 1, 1);
		if( i + m - 1 < n )
			modify(max(m - bf[i + m - 1], 1), m - 1, -1);
		ans += query(1, af[i]);
	}
	printf("%lld\n", ans);
}
/*
(r1 - l1 + 1) + (r2 - l2 + 1) = m

(r2 - l1 + 1) + (r1 - l2 + 1) = m

r2 >= l1 && r1 >= l2

1 <= (r2 - l1 + 1) < m
*/