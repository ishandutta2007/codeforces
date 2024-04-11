#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

const int N = 212345;
int c[N], cn;

int oc[N], ct[N];
int ans[N], x[N], y[N], t[N], id[N], pr[N], a[N], p[N], m[N];

inline void add(int &x) {
	//printf("\nadd(%d) oc %d i %d\n", x, oc[x], (&x - a));
	//printf("ct[%d]-- = %d\n", oc[x], ct[oc[x]] - 1);
	ct[oc[x]]--;
	//printf("ct[%d]++ = %d\n", oc[x] + 1, ct[oc[x] + 1] + 1);
	ct[++oc[x]]++;
}

inline void rm(int &x) {
	//printf("\nrm(%d) oc %d i %d\n", x, oc[x], (&x - a));
	//printf("ct[%d]-- = %d\n", oc[x], ct[oc[x]] - 1);
	ct[oc[x]]--;
	//printf("ct[%d]++ = %d\n", oc[x] - 1, ct[oc[x] - 1] + 1);
	ct[--oc[x]]++;
}

int L, R, T;
inline void chg(int i, int x) {
	//printf("chg(%d, %d)\n", i, x);
	if(i >= L && i <= R)
		rm(a[i]);
	a[i] = x;
	if(i >= L && i <= R)
		add(a[i]);
}


int main() {
	int i, j;
	int n, q;
	rd(n); rd(q);
	for(i = 0; i < n; i++) rd(a[i]), c[cn++] = a[i];
	int cm = 0;
	for(i = 0; i < q; i++) {
		rd(t[i]); rd(x[i]); rd(y[i]); x[i]--;
		if(t[i] == 1) y[i]--, m[i] = cm;
		else {
			cm++;
			c[cn++] = y[i];
			pr[cm] = a[x[i]];
			a[x[i]] = y[i];
			id[cm] = i;
		}
	}
	for(i = cm; i > 0; i--)
		a[x[id[i]]] = pr[i];
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;
	for(i = 0; i < n; i++) a[i] = lower_bound(c, c + cn, a[i]) - c;
	//for(i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n -1]);
	int pn = 0;
	cm = 0;
	for(i = 0; i < q; i++) {
		if(t[i] == 2) {
			y[i] = lower_bound(c, c + cn, y[i]) - c;
			cm++;
			pr[cm] = lower_bound(c, c + cn, pr[cm]) - c;
		} else
			p[pn++] = i;
	}
	ct[0] = 1000000001;
	int sq = max<int>(1, int(pow(q, 2. / 3.)));
	sort(p, p + pn, [sq](int i, int j) { return make_tuple(m[i] / sq, x[i] / sq, y[i]) < make_tuple(m[j] / sq, x[j] / sq, y[j]); });
	L = 0, R = -1, T = 0;
	for(int i_ = 0; i_ < pn; i_++) {
		//for(int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n -1]);
		i = p[i_];
		//printf("(t %d, l %d, r %d)\n", m[i], x[i], y[i]);
		while(R < y[i]) add(a[++R]);
		while(L > x[i]) add(a[--L]);
		while(R > y[i]) rm(a[R--]);
		while(L < x[i]) rm(a[L++]);
		while(T < m[i]) { T++; chg(x[id[T]], y[id[T]]); }
		while(T > m[i]) { chg(x[id[T]], pr[T]); T--; }
		for(j = 1; ct[j]; j++);
		ans[i] = j;
	}
	for(i = 0; i < q; i++)
		if(t[i] == 1)
			printf("%d\n", ans[i]);
}