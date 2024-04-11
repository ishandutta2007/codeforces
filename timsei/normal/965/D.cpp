#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int A[N] , w , l;

main(void) {
	cin >> w >> l;
	-- w;
	for(int i = 1;i <= w;++ i)
	scanf("%lld" , &A[i]);
	for(int i = 1;i <= w;++ i)
	A[i] += A[i - 1];
	int ans = 2e9;
	for(int i = l;i <= w;++ i) {
		ans = min(ans , A[i] - A[i - l]);
	}
	cout << ans << endl;
}