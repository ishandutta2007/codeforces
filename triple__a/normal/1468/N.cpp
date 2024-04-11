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
	int c1, c2, c3;
	int a1, a2, a3, a4, a5;	
	
	scanf("%d%d%d", &c1, &c2, &c3);
	scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	
	c1 -= a1;
	c2 -= a2;
	c3 -= a3;
	
	if (c1 < 0 || c2 < 0 || c3 < 0) {
		puts("NO");
		return;	
	}
	
	a4 -= min(a4, c1);
	a5 -= min(a5, c2);
	
	if (c3 >= a4 + a5) {
		puts("YES");	
	} else {
		puts("NO");	
	}
}
 
int main() {
	int t; scanf("%d", &t);
	
	while (t--) solve();
}