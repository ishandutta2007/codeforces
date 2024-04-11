#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;

int n , m  , x , y , b , d , a[N]  , S[N] , D[N];

vector <int> A , B;

bool pd(int x) {
	for(int i = 1;i <= n;++ i) D[i] = a[i];
	int p = 1;
	for(int i = x + 1;i <= n - x;++ i) {
		int aim = b , dist = min(i , n - i + 1);
		for(;aim;) {
			if(p == n + 1) return 0;
			if(!D[p] || dist * d < abs(i - p)) {
				++ p; continue;
			}
			int it = min(aim , D[p]);
			D[p] -= it; aim -= it;
		}
	}
	return 1;
}

main(void) {
	cin >> n >> d >> b;
	for(register int i = 1;i <= n;++ i) cin >> a[i];
	int l = 0 , r = n / 2 + 1 , res = n / 2 + 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
}