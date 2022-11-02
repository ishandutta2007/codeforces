#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;

int p[N];

vector<int> prime;

int find_factor(int x) {
	if (x < N) {
		return p[x] == 0 ? x : p[x];
	}
	for (int i = 0; i < (int)prime.size() && (long long)prime[i] * prime[i] <= x; ++i) {
		if (x % prime[i] == 0) {
			return prime[i];
		}
	}
	return x;
}

bool is_prime(int x) {
	return find_factor(x) == x;
}

int main() {
	for (int i = 2; i < N; ++i) {
		if (!p[i]) {
			prime.push_back(i);
			if ((long long)i * i < N) {
				for (int j = i * i; j < N; j += i) {
					if (!p[j]) {
						p[j] = i;
					}
				}
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, d;
		scanf("%d%d", &x, &d);
		int k = 0;
		while (x % d == 0) {
			x /= d;
			++k;
		}
		if (k == 1) {
			printf("NO\n");
		} else if (x != 1 && !is_prime(x)) {
				printf("YES\n");
		} else if (k == 2) {
			printf("NO\n");
		} else {
			// k > 2 && (x == 1 || is_prime(x))
			if (is_prime(d)) {
				printf("NO\n");
			} else {
				if (k > 3) {
					printf("YES\n");
				} else {
					if (d == (long long)x * x) {
						printf("NO\n");
					} else {
						printf("YES\n");
					}
				}
			}
		}
	}
	return 0;
}