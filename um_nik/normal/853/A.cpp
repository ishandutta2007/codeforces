#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 300300;
ll a[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	set<pli> setik;
	ll sum = 0;
	ll ANS = 0;
	for (int i = 0; i < k; i++) {
		ANS += (k - i) * a[i];
		sum += a[i];
		setik.insert(mp(-a[i], i));
	}
	for (int i = k; i < n; i++) {
		sum += a[i];
		setik.insert(mp(-a[i], i));
		sum += setik.begin()->first;
		ans[setik.begin()->second] = i;
		setik.erase(setik.begin());
		ANS += sum;
	}
	for (int i = n; i < n + k; i++) {
		sum += setik.begin()->first;
		ans[setik.begin()->second] = i;
		setik.erase(setik.begin());
		ANS += sum;
	}
	printf("%lld\n", ANS);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}