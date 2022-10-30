#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n, a[N];
bool used[N];

const long long MOD = 1000000007;
long long mem[N][N];

long long getans(const int a, const int b) {
	if (a < 0 || b < 0) {
		return 0;
	}
	if (mem[a][b] != -1) {
		return mem[a][b];
	}
	long long ret = 0;
	if (a == 0 && b == 0) {
		ret = 1;
	} else {
		if (a > 0) {
			ret = (a - 1) * getans(a - 2, b + 1) % MOD + 
				  b * getans(a - 1, b) % MOD;
		} else {
			ret = a * getans(a - 1, b) % MOD + 
				  b * getans(a, b - 1) % MOD; 
		}
		ret %= MOD;
	}
	return mem[a][b] = ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
		if (a[i] >= 0) {
			used[a[i]] = true;
		}
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (a[i] == -2) {
			++cnt1;
		} else {
			++cnt2;
		}
	}
	memset(mem, -1, sizeof(mem));
	cout << getans(cnt1, cnt2) << endl;
	return 0;
}