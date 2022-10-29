#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;
int nums[100];
ll f[100][100][2];
ll A, B;
ll dfs(int m, int now, int first, int e) {
	if (m == -1) return now == 1 ? 1 : 0;
	if (!e && f[m][now][first] != -1) return f[m][now][first];
	ll ret = 0;
	int u = e ? nums[m] : 1;
	for (int j = 0; j <= u; ++j) 
		ret += dfs(m - 1, now + (!first && j == 0), first && j == 0, e && j == u);
	return e ? ret : f[m][now][first] = ret;
}
ll calc(ll n) {
	memset(f, 255, sizeof(f));
	int m = 0;
	while (n) {
		nums[m++] = n % 2;
		n /= 2;
	}
	return dfs(m - 1, 0, 1, 1);
}
int main() {
	cin >> A >> B;
	cout << calc(B) - calc(A - 1) << endl;
}