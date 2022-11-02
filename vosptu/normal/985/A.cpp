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

int a[1100];

int main() {
	int n, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n / 2 + 1);
	for (int i = 1; i <= n / 2; i++) {
		int x;
		x = a[i];
		sum1 += abs(x - 2 * i + 1);
		sum2 += abs(x - 2 * i);
	}
	printf("%d\n", min(sum1, sum2));
}