#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector <pair <long long, int> > prime_divs;
int cnt = 0;
vector <long long> all_divs;

void get_prime_divs(long long n) {
	long long i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			prime_divs.push_back(make_pair(i, 1));
			n /= i;
			while (n % i == 0) {
				n/= i;
				prime_divs[cnt].second++;
			}
			cnt++;
		}
		i++;
	}
	if (n != 1) {
		prime_divs.push_back(make_pair(n, 1));
		cnt++;
	}
}

void gen(int n, long long ans) {
	if (n == cnt) {
		all_divs.push_back(ans);
	} else {
		long long add = 1;
		for (int i = 0; i <= prime_divs[n].second; i++) {
			gen(n + 1, ans * add);
			add *= prime_divs[n].first;
		}
	}
}

int main() {
	long long n, k;
	scanf("%I64d %I64d", &n, &k);
	if (sqrt(2 * n) < k) {
		printf("-1\n");
		return 0;
	}
	long long c = k * (k + 1) / 2;
	get_prime_divs(n);
	gen(0, 1);
	sort(all_divs.begin(), all_divs.end());
	for (int i = 0; i < all_divs.size(); i++) {
		if (all_divs[i] < c) {
			continue;
		}
		long long now = 0, summ = 0, ans = n / all_divs[i];
		for (int j = 0; j < k; j++) {
			if (j == k - 1) {
				now = all_divs[i] - summ;
			} else {
				now++;
			}
			printf("%I64d ", now * ans);
			summ += now;
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}