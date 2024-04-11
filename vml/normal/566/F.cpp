#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <cstdlib>
#include <memory.h>
#include <cassert>
#include <queue>
#include <ctime>

using namespace std;

const int maxn = (int)1e6 + 10;

int ans[maxn];
int v[maxn];

int main() {
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	int res = 1;
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j * v[i] < maxn; j++) {
			ans[v[i]] = max(ans[v[i]], ans[v[i] * j] + 1);
		}
		
		res = max(res, ans[v[i]]);
	}
	
	cout << res << endl;
	
	return 0;
}