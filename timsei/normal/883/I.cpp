#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e5 + 5;

int S[N] , a[N] , n, ans , k , dp[N];

bool pd(int x) {
	memset(S , 0 , sizeof(S));
	memset(dp , 0 , sizeof(dp));
	dp[0] = 1; S[0] = 1;
	for(int i = 1;i <= k - 1;i ++) S[i] = S[i - 1] , dp[i] = 0;
	for(int i = k;i <= n;i ++) {
		int l = 1 , r = i , res = -1; 
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[i] - a[mid] <= x) {
				r = mid - 1; res = mid;
			}
			else l = mid + 1;
		}
		if(res == -1 || res > i - k + 1) {
			dp[i] = 0;
		}
		else {
			int ne = 0;
			if(res == 1) ne = 0; else ne = S[res - 2];
			if(S[i - k] - ne) dp[i] = 1;
			else dp[i] = 0;
		}
		S[i] = S[i - 1] + dp[i];
	}
	return (dp[n] == 1);
}

int main(void) {
	scanf("%d%d" , &n , &k);
	for(int i = 1;i <= n;i ++) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1);
	int l = 0 , r = 2e9 , res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n" , res);
}