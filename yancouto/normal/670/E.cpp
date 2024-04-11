#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 512345;

char s[N], q[N];
int nx[N], pr[N], st[N], sn, o[N];
int main() {
	int i, j, n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	scanf("%s", s);
	for(i = 0; i < n; i++) {
		nx[i] = i + 1; pr[i] = i - 1;
		o[i] = i;
		if(s[i] == '(') st[sn++] = i;
		else swap(o[i], o[st[--sn]]);
	}
	nx[n - 1] = -1;
	scanf("%s", q); p--;
	for(i = 0; i < m; i++) {
		if(q[i] == 'R') p = nx[p];
		else if(q[i] == 'L') p = pr[p];
		else {
			int l = o[p], r = p;
			if(l > r) swap(l, r);
			if(nx[r] != -1) pr[nx[r]] = pr[l];
			if(pr[l] != -1) nx[pr[l]] = nx[r];
			if(nx[r] != -1) p = nx[r];
			else p = pr[l];
		}
	}
	while(pr[p] != -1) p = pr[p];
	for(; p != -1; p = nx[p]) putchar(s[p]);
	putchar('\n');
}