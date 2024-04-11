#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw

void solve() {
	int a[4];
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	
	sort(a, a + 4);

	LL res = (LL)a[0] * a[2];
	
	printf("%lld\n", res);
}
 
int main() {
	int t; scanf("%d", &t);
	
	while (t--) solve();
}