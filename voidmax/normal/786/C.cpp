// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;
const int INF = 1e9;
const int MAXN = 1e5 + 1;
const string FILENAME = "input";

typedef pair <long long, long long> point;

struct node {
	int sum;
	int L, R;
	int son[2];
	node() {
		L = R = son[0] = son[1] = -1;
		sum = 0;
	}
};

int id = 0;
node arr[5000000];
int root[100001];

int init(int L, int R) {
	int i = id++;
	arr[i].L = L, arr[i].R = R;
	if (R - L > 1) {
		int M = (L + R) >> 1;
		arr[i].son[0] = init(L, M);
		arr[i].son[1] = init(M, R);
	}
	return i;
}

int clone(int j) {
	int i = id++;
	arr[i].L = arr[j].L;
	arr[i].R = arr[j].R;
	arr[i].sum = arr[j].sum;
	arr[i].son[0] = arr[j].son[0];
	arr[i].son[1] = arr[j].son[1];
	return i;
}

int update(int i, int L, int d) {
	if (arr[i].R <= L || (L + 1) <= arr[i].L) 
		return i;
	int j = clone(i);
	if (L <= arr[i].L && arr[i].R <= (L + 1)) {
		arr[j].sum += d;
		return j;
	}
	arr[j].son[0] = update(arr[i].son[0], L, d);
	arr[j].son[1] = update(arr[i].son[1], L, d);
	arr[j].sum += d;
	return j;
}

int get(int i, int len) {
	if (arr[i].R - arr[i].L == 1)
		return arr[i].L;
	if (arr[arr[i].son[0]].sum > len) {
		return get(arr[i].son[0], len);
	}
	return get(arr[i].son[1], len - arr[arr[i].son[0]].sum);
}

int n;
map <int, int> used;
int a[100001];

int check(int k) {
	int L = 0, cnt = 0;
	while (L < n) {
		L = get(root[L], k);
		++cnt;
	}
	return cnt;
}

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	root[n] = init(0, n + 2);
	for (int i = n; i--;) {
		root[i] = root[i + 1];
		if (used.count(a[i])) {
			root[i] = update(root[i], used[a[i]], -1);
		}
		used[a[i]] = i;
		root[i] = update(root[i], i, 1);
	}
	for (int i = 1; i <= n; ++i) {
		cout << check(i) << ' ';
	}
	cout << endl;
} 

/*
10 5 4 3 2 2 2 2 2 2 1
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10  8
1 2 - 3 4 - 5 6 - 7 8 - 9 10
1 2 3 - 4 5 6 - 7 8 9 - 10
1 2 3 4 - 5 6 7 8 - 9 10
1 2 3 4 5 - 6 7 8 9 10
1 2 3 4 5 6 7 8 -
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8

*/