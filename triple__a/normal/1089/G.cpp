#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define pow qjwopjqpw
 
int t;

#define M 7

int n;
int a[10];

void solve() {
	scanf("%d", &n);	

	FOE(i, 1, M) scanf("%d", &a[i]);
	int sum = 0;
	FOE(i, 1, M) sum += a[i];
	
	LL ret = -1;
	int weeks = n / sum;
	
	if (n % sum == 0) weeks--;
	LL base = (LL)weeks * 7; 
	
	FOE(i, 1, M) {
		int cnt = (n % sum == 0 ? sum : n % sum), ptr = i, tot = 0;
		while (cnt) {
			cnt -= a[ptr];
			ptr = (ptr % 7) + 1;
			tot++;
		}
		
		if (ret == -1 || ret > tot) ret = tot;
	}
	
	printf("%lld\n", ret + base);
}
 
int main() {
	scanf("%d", &t);
	while (t--) solve();
	
}