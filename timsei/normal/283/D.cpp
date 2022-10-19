#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

#define int long long

int n , dp[N] , a[N] , b[N];

int get(int x) {
    int res = 0;
    while((x % 2 == 0)) {
	x /= 2; ++ res;
    }
    return res;
} 

bool py(int x , int y) {
    if(x == 0) return 1;
    if(a[x] % a[y] != 0) return 0;
    if(b[y] <= y - x - 1 || b[y] - b[x] == (y - x)) return 1;
    return 0;
}

main(void) {
    cin >> n;
    for(int i = 1;i <= n;++ i) cin >> a[i] , b[i] = get(a[i]) , a[i] /= (1 << b[i]);
    a[n + 1] = 1; b[n + 1] = 0;
    dp[1] = 0; dp[0] = 0;
    int ans = 0;
    for(int i = 1;i <= n;++ i) {
	for(int j = 0;j <= i - 1;++ j) if(py(j , i)) {
		dp[i] = max(dp[j] + 1  , dp[i]);
	}
	ans = max(ans , dp[i]);
    }
    cout << n - ans << endl;
}