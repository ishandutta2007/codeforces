#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
int n;
ll a[MAXN + 5], s1[MAXN + 5], s2[MAXN + 5];
ll c1(int i) {return s1[n] - a[i]*i + s2[i-1];}
ll c2(int i) {return s1[n] - a[i]*i + s2[i];}
ll k1(int i) {return -a[i];}
ll k2(int i) {return a[i];}
ll x1(int j) {return j;}
ll x2(int j) {return -j;}
ll y1(int j) {return -s2[j-1];}
ll y2(int j) {return -s2[j];}
int stk[MAXN + 5], tp;
double slope1(int p, int q) {return 1.0*(y1(p) - y1(q))/(x1(p) - x1(q));}
double slope2(int p, int q) {return 1.0*(y2(p) - y2(q))/(x2(p) - x2(q));}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++) {
		s1[i] = s1[i-1] + a[i]*i;
		s2[i] = s2[i-1] + a[i];
	}
	ll ans = -(1LL<<62); tp = 0;
	for(int i=1;i<=n;i++) {
		while( tp > 1 && slope1(stk[tp - 1], stk[tp]) <= slope1(stk[tp], i) )
			tp--;
		stk[++tp] = i;
		int le = 1, ri = tp;
		while( le < ri ) {
			int mid = (le + ri) >> 1;
			if( slope1(stk[mid], stk[mid+1]) <= k1(i) ) ri = mid;
			else le = mid + 1;
		}
		ans = max(ans, c1(i) + y1(stk[le]) - k1(i)*x1(stk[le]));
	}
	tp = 0;
	for(int i=n;i>=1;i--) {
		while( tp > 1 && slope2(stk[tp - 1], stk[tp]) <= slope2(stk[tp], i) )
			tp--;
		stk[++tp] = i;
		int le = 1, ri = tp;
		while( le < ri ) {
			int mid = (le + ri) >> 1;
			if( slope2(stk[mid], stk[mid+1]) <= k2(i) ) ri = mid;
			else le = mid + 1;
		}
		ans = max(ans, c2(i) + y2(stk[le]) - k2(i)*x2(stk[le]));
	}	
	printf("%lld\n", ans);
}