#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const int maxn = 100006; 
const int maxk = 1000006; 

const ll oo = 0x3f3f3f3f3f3f3f3fll; 

struct data {
	int d, f, t, c; 
}; 

bool cmp(data a, data b) {
	return a.d < b.d; 
}

int n, m, k, len; 
data a[maxn]; 
ll l[maxk], r[maxk]; 
ll c[maxn]; 

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= m; ++i) scanf( "%d%d%d%d", &a[i].d, &a[i].f, &a[i].t, &a[i].c ); 
	sort(a+1, a+m+1,cmp); 
	len = a[m].d;
	
	fill( c, c+n+1, oo / n ); 
	int pre = 0; 
	l[0] = oo / n * n; 
	for (int i = 1; i <= m; ++i) {
		for (int j = pre+1; j <= a[i].d; ++j) l[j] = l[j-1]; 
		pre = a[i].d; 
		if (a[i].t == 0 && a[i].c < c[a[i].f] ) {
			l[a[i].d] -= c[a[i].f]; 
			c[a[i].f] = a[i].c; 
			l[a[i].d] += c[a[i].f]; 
		}
	}
	
	fill( c, c+n+1, oo / n ); 
	pre = len+1; 
	r[len+1] = oo / n * n; 
	for (int i = m; i >= 1; --i) {
		for (int j = pre-1; j >= a[i].d; --j) r[j] = r[j+1]; 
		pre = a[i].d; 
		if (a[i].f == 0 && a[i].c < c[a[i].t] ) {
			r[a[i].d] -= c[a[i].t]; 
			c[a[i].t] = a[i].c; 
			r[a[i].d] += c[a[i].t]; 
		}
	}
	
	ll ans = oo; 
	for (int i = 1; i + k + 1 <= len; ++i) 
		ans = min(ans, l[i] + r[i+k+1] ); 
		
	if (ans > ll(n) * 2 * 1000001) puts ( "-1" ); 
	else cout<<ans<<endl; 
}