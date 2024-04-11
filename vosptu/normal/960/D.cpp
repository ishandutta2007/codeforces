#include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>

using namespace std;

long long shift[100];

int level(long long x) {
	int cnt = 0;
	while (x) {
		cnt += 1;
		x /= 2;
	}
	return cnt - 1;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int T;
		long long X, K;
		scanf("%d", &T);
		if (T == 1) {
			scanf("%I64d%I64d", &X, &K);
			int l = level(X);
			shift[l] = ((shift[l] + K) % (1LL << l) + (1LL << l)) % (1LL << l);
		}else if (T == 2) {

			scanf("%I64d%I64d", &X, &K);
			int l = level(X);
			K %= (1LL << l);
			for (int i = l; i <= 60; i++) {
				shift[i] = ((shift[i] + K) % (1LL << i) + (1LL << i)) % (1LL << i);	
				K = K * 2;
			}
		}else {
			scanf("%I64d", &X);
			int l = level(X);
			X = ((X - (1LL << l)) + shift[l]) % (1LL << l) + (1LL << l);
			for (int i = l; i >= 0; i--) {
				printf("%I64d ", (((X - (1LL << i)) - shift[i]) % (1LL << i) + (1LL << i)) % (1LL << i) + (1LL << i));
				// cout << " ";
				X /= 2;
			}
			printf("\n");
		}
	}
}