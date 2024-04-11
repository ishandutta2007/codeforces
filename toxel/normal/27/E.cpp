#include<bits/stdc++.h>

const int N = 1010;
typedef long long ll;
const ll MAX = 1000000000000000000ll;

ll a[N];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int main(){
	memset(a, -1, sizeof(a));
	a[1] = 1;
	for (auto u : prime){
		for (int i = N - 1; i; -- i){
			if (a[i] == -1) continue;
			ll x = u, cnt = 1;
			while (true){
				if (i * (cnt + 1) >= N) break;
				if (1.0 * a[i] * x < 2e18 && a[i] * x <= MAX){
					if (!~a[i * (cnt + 1)] || a[i * (cnt + 1)] > a[i] * x){
						a[i * (cnt + 1)] = a[i] * x;
					}
				}
				if (1.0 * x * u >= 2e18 || x * u > MAX){
					break;
				}
				x *= u;
				++ cnt;
			}
		}
	}
	int n;
	scanf("%d", &n);
	printf("%I64d\n", a[n]);
	return 0;
}