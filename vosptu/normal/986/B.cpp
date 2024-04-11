#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;

int a[1100000];
bool used[1100000];
int cc[1100000];
int tmp;

void dfs(int x) {
	if (used[x])
		return ;
	tmp += 1;
	used[x] = true;
	dfs(a[x]);
}

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (i == x)
			cnt += 1;
	}
	if (n == 5 || abs(cnt - n * pow(1 - 1.0 / n, 6 * n)) < abs(cnt - n * pow(1 - 1.0 / n, 14 * n)))
		printf("Petr\n");
	else
		printf("Um_nik\n");

	// srand(time(0));
	// int n = 1000;
	// for (int i = 1; i <= n; i++)
	// 	a[i] = i;
	// for (int i = 1; i <= 7 * n + 1; i++)
	// 	swap(a[rand() % n + 1], a[rand() % n + 1]);
	// int cnt = 0;

	// for (int i = 1; i <= n; i++)
	// 	if (!used[i]) {
	// 		// cnt += 1;
	// 		tmp = 0;
	// 		dfs(i);
	// 		cc[tmp] += 1;
	// 	}
	// // printf("%d\n", cnt);
	// // for (int i = 1; i <= n; i++)
	// // 	if (cc[i])
	// // 		printf("%d %d\n", i, cc[i]);
	// // cnt = 0;
	// for (int i = 1; i <= n; i++)
	// 	// if (a[i] < a[i + 1])
	// 	// 	cnt += 1;
	// 	if (a[i] == i)
	// 		cnt += 1;

	// // printf("%lf\n", n * pow(1 - 1.0 / n, 6 * n));
	//  if (abs(cnt - n * pow(1 - 1.0 / n, 6 * n)) < abs(cnt - n * pow(1 - 1.0 / n, 14 * n)))
	// 	printf("Petr\n");
	// else
	// 	printf("Um_nik\n");
	// // for (int i = 1; i <= n; i++)
	// // 	for (int j = 1; j < i; j++)
	// // 		if (a[i] > a[j])
	// // 			cnt += 1;
	// printf("%d\n", cnt);
				// printf("%d\n", );
}