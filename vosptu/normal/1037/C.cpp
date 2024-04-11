#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

int n;
char A[1100000], B[1100000];

int main() {
	scanf("%d%s%s", &n, A, B);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (A[i] != B[i])
			ans++;
	for (int i = 0; i < n - 1; i++)
		if ((A[i] != B[i]) && (A[i + 1] != B[i + 1]) && (A[i] == B[i + 1]) && (A[i + 1] == B[i])) {
			ans--;
			i++;
		}
	printf("%d\n", ans);
}