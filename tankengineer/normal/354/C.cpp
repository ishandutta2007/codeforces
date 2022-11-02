#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int N = 1000001;
int n, k;
int sum[N];

bool check(int x) {
	int cnt = 0;
	for (int i = x; i < N && cnt < n; i += x) {
		cnt += sum[min(N - 1, i + k)] - sum[i - 1];	
	}
	return cnt == n;
}

int main() {
	scanf("%d%d", &n, &k);
	int mins = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++sum[a];
		mins = min(mins, a);
	}
	for (int i = 1; i < N; ++i) {
		sum[i] += sum[i - 1];
	}
	if (mins <= k + 1) {
		printf("%d\n", mins);
		return 0;
	}
	for (int i = mins; i >= k + 1; --i) {
		if (check(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}