#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int n, m, sum[2100];
char S[2100][2100];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", S[i] + 1);
		for (int j = 1; j <= m; j++)
			if (S[i][j] == '1')
				sum[j] += 1;
	}
	bool ok =false;
	for (int i = 1; i <= n; i++) {
		bool all = true;
		for (int j = 1; j <= m; j++)
			if (sum[j] == 1 && S[i][j] == '1')
				all = false;
		if (all)
			ok = true;
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
}