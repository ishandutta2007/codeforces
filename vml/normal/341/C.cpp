#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <time.h>
#include <cstdlib>

using namespace std;

const int MAXN = 2010;
long long inf = 1000000007;
int v[MAXN];
long long ans[MAXN][MAXN];
bool used_pos[MAXN];
bool used_elem[MAXN];
long long fact[MAXN];
long long reverse_fact[MAXN];

long long res(int numb, int k) {
	if (ans[numb][k] == -1) {
		if (numb == k) {
			ans[numb][k] = reverse_fact[numb];
		} else if (k == 0) {
			ans[numb][k] = fact[numb];
		} else {
			ans[numb][k] = (k * res(numb - 1, k - 1) + (numb - k) * res(numb - 1, k)) % inf;
		}
	}
	return ans[numb][k];
}

int main() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			ans[i][j] = -1;
		}
	}
	fact[1] = 1;
	reverse_fact[1] = 0;
	for (int i = 2; i < MAXN; i++) {
		fact[i] = (fact[i - 1] * i) % inf;
		if (i % 2 == 0) {
			reverse_fact[i] = (reverse_fact[i - 1] * i + 1) % inf;
		} else {
			reverse_fact[i] = ((reverse_fact[i - 1] * i - 1) % inf + inf) % inf;
		}
	}
	int n;
	scanf("%d", &n);
	int numb = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		if (v[i] != -1) {
			used_pos[i] = true;
			used_elem[v[i]] = true;
		} else {
			numb++;
		}
	}
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (!used_pos[i] && !used_elem[i]) {
			k++;
		}
	}
	printf("%I64d", res(numb, k));
	return 0;
}