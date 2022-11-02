#include<cstdio>
#include<algorithm>
using namespace std;

int a, b, n, t1, dp[100005][31];

int getans_dp(const int a, const int b, const int n) {
  if (dp[a][b]) return dp[a][b];
  long long a1 = a;
  if (a1 >= n) return dp[a][b] = 1;
  for (int i = 2; i <= b; ++i) {
	  a1 *= a;
	  if (a1 >= n) return dp[a][b] = 1;
	}  
  if (a * a >= n && b == 1) return dp[a][b] = (n - a) % 2 ? -1 : 1;
	if (getans_dp(a + 1, b, n) == -1 || getans_dp(a, b + 1, n) == -1) dp[a][b] = 1; else dp[a][b] = -1;
	return dp[a][b];
}

int getans(const int a, const int b, const int n) {
  if (a == 1) {
		for (int i = b; (1 << i) < n; ++i) {
		  if (getans_dp(a + 1, i, n) == -1) return (i - b) % 2 ? -1 : 1;
		} 
		return 0;
	} else {
  	return getans_dp(a, b, n);
	}
}

int main() {
  scanf("%d %d %d", &a, &b, &n);
  t1 = getans(a, b, n);
  if (t1 == 0) {
	  puts("Missing");
	} else if (t1 == 1) {
	  puts("Masha");
	} else {
	  puts("Stas");
	}
	return 0;
}