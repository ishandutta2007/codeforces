#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

long long sqr(long long x) {
	return x * x;
}

const int N = 250001;
int root, treapCount, children[N][2], weight[N], mass[N];
long long dis[N];
int key[N], minM[N];

int smallerM(int a, int b) {
	return mass[a] < mass[b] ? a : b;
}

void update(int x) {
	minM[x] = smallerM(key[x], smallerM(minM[children[x][0]], minM[children[x][1]]));
}

void rotate(int &x, int t) {
	int y = children[x][t];
	children[x][t] = children[y][1 ^ t];
	children[y][1 ^ t] = x;
	update(x);
	update(y);
	x = y;
}

void treapInsert(int &x, int k) {
	if (x) {
		int t = dis[key[x]] < dis[k] || dis[key[x]] == dis[k] && key[x] < k;
		treapInsert(children[x][t], k);
		if (weight[children[x][t]] < weight[x]) {
			rotate(x, t);
		}
	} else {
		x = treapCount++;
		key[x] = k;
		weight[x] = rand();
	}
	update(x);
}

void treapDelete(int &x, int k) {
	if (key[x] == k) {
		if (children[x][0] || children[x][1]) {
			int t = weight[children[x][0]] > weight[children[x][1]];
			rotate(x, t);
			treapDelete(x, k);
		} else {
			x = 0;
		}
	} else {
		int t = dis[key[x]] < dis[k] || dis[key[x]] == dis[k] && key[x] < k;
		treapDelete(children[x][t], k);
	}
	update(x);
}

int treapQuery(int &x, long long r) {
	if (!x) {
		return minM[x];
	}
	int ret;
	if (r >= dis[key[x]]) {
		ret = smallerM(key[x], smallerM(minM[children[x][0]], treapQuery(children[x][1], r)));
	} else {
		ret = treapQuery(children[x][0], r);
	}
	return ret;
}

int n, p[N], r[N];

int main() {
	root = 0;
	treapCount = 1;
	minM[0] = 0;
	weight[0] = INT_MAX;
	key[0] = 0;
	int sx, sy;
	scanf("%d%d%d%d%d", &sx, &sy, p, r, &n);
	mass[0] = INT_MAX;
	vector<int> q;
	q.push_back(0);	
	for (int i = 1; i <= n; ++i) {
		int x, y, m;
		scanf("%d%d%d%d%d", &x, &y, &m, p + i, r + i);	
		mass[i] = m;
		x -= sx, y -= sy;
		dis[i] = sqr(x) + sqr(y);
		treapInsert(root, i);
	}
	for (int _ = 0; _ < (int)q.size(); ++_) {
		int i = q[_];
		long long rad = r[i];
		int pow = p[i];
		rad *= rad;
		int ret = treapQuery(root, rad);
		while (mass[ret] <= pow) {
			treapDelete(root, ret);
			q.push_back(ret);
			ret = treapQuery(root, rad);
		}
	}
	printf("%d\n", (int)q.size() - 1);
	return 0;
}