#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

const int N = 100005;
const int K = 200005;

int a[N] , k , n , m , dp[N];

int calc(int len) {
	if(dp[len]) return dp[len];
	if(len == 1) return 1;
	return dp[len] = calc(len / 2) + calc(len - len / 2) + 1;
}

void solve(int l , int r , int k) {
//	cerr<<l<<" "<<r<<" "<<k<<" "<< calc(r - l + 1) - 1 << endl;
	sort(a + l , a + r + 1);
	if(k == 0) {
		return;
	}
	if(k + 1 == calc(r - l + 1)) {
		reverse(a + l , a + r + 1);
		return;
	}
	int mid = (l + r) >> 1;
	if((r - l + 1) & 1) mid --;
	if(k % 2 == 1) {
		puts("-1");
		exit(0);
	}
	int len = r - mid , tot = l - 1;
	sort(a + l , a + r + 1);
	reverse(a + l , a + r + 1);
	k -= 2;
	int fir = calc(mid - l + 1) - 1;
//	cerr<<fir<<" "<<l<<" "<<mid<<endl;
	if(k <= fir) {
		solve(l , mid , k); solve(mid + 1 , r , 0);
	}
	else solve(l , mid , fir) , solve(mid + 1 , r , k - fir);
}

main(void) {
	scanf("%lld%lld",&n,&k);
	for(int i = 1;i <= n;i ++) a[i] = i;
	if(k <= 0 || k > calc(n) || k % 2 == 0) {
		puts("-1"); return 0;
	}
	k --;
	solve(1 , n , k);
	for(int i = 1;i <= n;i ++) printf("%lld ",a[i]);
}