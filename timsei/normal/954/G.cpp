#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1111111;

int n , m , x , y , A[N] , r , k , S[N] , L[N] , R[N];

int S2[N];

void add(int l , int r , int v) {
	S[l] += v;
	S[r + 1] -= v;
}

bool pd(int x) {
	int K = k;
	memset(S2 , 0 , sizeof(S2));
	int it = 0;
	for(int i = 1;i <= n;++ i) {
		it += S2[i];
		if(S[i] + it >= x)
		continue;
		int now = x - S[i] - it;
		int wh = min(i + r , n);
		K -= now;
		if(K < 0) return 0;
		it += now;
		S2[min(wh + r , n) + 1] -= now;
	}
	if(K < 0) return 0;
	return 1;
}

main(void) {
	cin >> n >> r >> k;
	for(int i = 1;i <= n;++ i) {
		L[i] = max(i - r , 0ll);
		R[i] = min(i + r , n);
		cin >> x;
		add(L[i] , R[i] , x);
	}
	for(int i = 1;i <= n;++ i) S[i] += S[i - 1];
	int ll = 0 , rr = 2e18 + 1e15 , res = 0;
	while(ll <= rr) {
		long long mid = ((long long)ll + (long long)rr) / (int)2;
		if(pd(mid)) {
			res = mid; ll = mid + 1;
		}
		else rr = mid - 1;
	}
	cout << res;
}