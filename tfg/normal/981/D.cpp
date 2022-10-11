#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

typedef long long ll;

const int ms = 55;

ll a[ms];
ll sum[ms][ms];
bool can[ms][ms];

int main() {
	srand(time(0));
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		//a[i] = (rand() ^ (rand() << 16)) ^ (((ll)rand() ^ (rand() << 16)) << 10);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			sum[i][j + 1] = sum[i][j] + a[j];
		}
	}
	ll ans = 0;
	for(int e = ms; e >= 0; e--) {
		memset(can, 0, sizeof can);
		can[0][0] = true;
		ll want = ans + (1LL << e);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {
				//std::cout << can[i][j] << (j + 1 == k ? '\n' : ' ');
				if(!can[i][j]) continue;
				for(int k = i + 1; k <= n; k++) {
					if((sum[i][k] & want) == want) {
						can[k][j + 1] = true; 
					}
				}
			}
		}
		if(can[n][k]) {
			ans = want;
		}
	}
	std::cout << ans << std::endl;
}