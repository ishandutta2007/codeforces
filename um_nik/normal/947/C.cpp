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
#define mp make_pair

const int K = 30;
const int N = 300100;
const int S = (int)6e6 + 1110;
int go[S][2];
int cnt[S];
int m;
int n;
int a[N];

int newNode() {
	go[m][0] = go[m][1] = -1;
	return m++;
}

void addTrie(int x) {
	int v = 0;
	cnt[v]++;
	for (int i = K - 1; i >= 0; i--) {
		int y = (x >> i) & 1;
		if (go[v][y] == -1)
			go[v][y] = newNode();
		v = go[v][y];
		cnt[v]++;
	}
}
void delTrie(int x) {
	int v = 0;
	cnt[v]--;
	for (int i = K - 1; i >= 0; i--) {
		int y = (x >> i) & 1;
		if (go[v][y] == -1)
			go[v][y] = newNode();
		v = go[v][y];
		cnt[v]--;
	}
}

int getBest(int x) {
	int v = 0;
	int ans = 0;
	for (int i = K - 1; i >= 0; i--) {
		int y = (x >> i) & 1;
		while(true) {
			int u = go[v][y];
			if (u == -1 || cnt[u] == 0) {
				y ^= 1;
				ans ^= 1 << i;
				continue;
			}
			v = u;
			break;
		}
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	newNode();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		addTrie(x);
	}
	for (int i = 0; i < n; i++) {
		int x = getBest(a[i]);
		delTrie(a[i] ^ x);
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}