#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int main(void) {
	int n , k , x , ans = 2e9;
	cin >> n >> k;
	for(int i = 1;i <= n;++ i) {
		cin >> x;
		if(k % x == 0) ans = min(ans , k / x);
	}
	cout << ans;
}