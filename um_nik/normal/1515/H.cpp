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
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int P = 8, Q = 12;
struct Block {
	bitset<(1 << P)> a;
	int A, X, cnt;

	Block() : a(), A((1 << P) - 1), X(0), cnt(0) {}

	void push() {
		bitset<(1 << P)> nw;
		nw.reset();
		for (int x = 0; x < (1 << P); x++) {
			if (a[x]) {
				nw[(x & A) ^ X] = 1;
			}
		}
		a = nw;
		X ^= X & A;
		cnt = a.count();
	}

	void recalc() {
		A = (1 << P) - 1;
		X = 0;
		cnt = a.count();
	}

	void makeOp(int t, int x) {
		if (t == 3) {
			X ^= x;
			return;
		}
		if (t == 1) x ^= (1 << P) - 1;
		bool p = (A & x) != 0;
		X ^= X & x;
		A ^= A & x;
		if (t == 2) X ^= x;
		if (p) push();
	}
};
Block blocks[(1 << 14) + 55];
bitset<(1 << 14) + 55> usedBlock;
int curBlock;
int p[(1 << 12) + 5];
int np[(1 << 12) + 5];

void recalcFree() {
	usedBlock.reset();
	for (int i = 0; i < (1 << Q); i++)
		if (p[i] != -1)
			usedBlock[p[i]] = 1;
	curBlock = 0;
}

int getNewBlock() {
	while (usedBlock[curBlock]) curBlock++;
	usedBlock[curBlock] = 1;
	blocks[curBlock] = Block();
	return curBlock;
}

void mergeInto(int &v, int u) {
	if (v == -1) {
		v = u;
		return;
	}
	blocks[v].push();
	blocks[u].push();
	blocks[v].a |= blocks[u].a;
	blocks[v].recalc();
}

int getAns(int l, int r) {
	int lId = l >> P, rId = r >> P;
	l &= (1 << P) - 1;
	r &= (1 << P) - 1;
	int ans = 0;
	if (lId == rId) {
		if (p[lId] == -1) return ans;
		blocks[p[lId]].push();
		for (int x = l; x <= r; x++)
			ans += blocks[p[lId]].a[x];
		return ans;
	}
	if (p[lId] != -1) {
		blocks[p[lId]].push();
		for (int x = l; x < (1 << P); x++)
			ans += blocks[p[lId]].a[x];
	}
	if (p[rId] != -1) {
		blocks[p[rId]].push();
		for (int x = 0; x <= r; x++)
			ans += blocks[p[rId]].a[x];
	}
	for (int i = lId + 1; i < rId; i++)
		if (p[i] != -1)
			ans += blocks[p[i]].cnt;
	return ans;
}

void splitBlock(int &v, int &u, int l, int r) {
//	eprintf("splitting ");
	blocks[v].push();
//	for (int i = 0; i < (1 << P); i++)
//		eprintf("%d", (int)blocks[v].a[i]);
	u = getNewBlock();
	blocks[u] = blocks[v];
	/*
	eprintf(" -- ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[v].a[i]);
	eprintf(" ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[u].a[i]);
	*/
	for (int i = 0; i <= (1 << P) - 1; i++) {
		if (l <= i && i <= r) {
			blocks[u].a[i] = 0;
		} else {
			blocks[v].a[i] = 0;
		}
	}
	/*
	eprintf(" -- ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[v].a[i]);
	eprintf(" ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[u].a[i]);
	*/
	blocks[v].recalc();
	blocks[u].recalc();
	/*
	eprintf(" -- ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[v].a[i]);
	eprintf(" ");
	for (int i = 0; i < (1 << P); i++)
		eprintf("%d", (int)blocks[u].a[i]);
	eprintf("\n");
	*/
}

void makeOp(int t, int l, int r, int x) {
	int lId = l >> P, rId = r >> P;
	int y = x >> P;
	l &= (1 << P) - 1;
	r &= (1 << P) - 1;
	x &= (1 << P) - 1;
	for (int i = 0; i < (1 << Q); i++) {
		if (p[i] == -1) continue;
		int v = p[i];
		if (i < lId || i > rId) {
			mergeInto(np[i], v);
			continue;
		}
		if (i == lId || i == rId) {
			int L = 0, R = (1 << P) - 1;
			if (i == lId) L = l;
			if (i == rId) R = r;
			int u;
			splitBlock(v, u, L, R);
			mergeInto(np[i], u);
			blocks[v].makeOp(t, x);
			int j = i;
			if (t == 1) {
				j &= y;
			} else if (t == 2) {
				j |= y;
			} else {
				j ^= y;
			}
			mergeInto(np[j], v);
		} else {
			blocks[v].makeOp(t, x);
			int j = i;
			if (t == 1) {
				j &= y;
			} else if (t == 2) {
				j |= y;
			} else {
				j ^= y;
			}
			mergeInto(np[j], v);
		}
	}
}

void eprintAll() {
	for (int i = 0; i < (1 << Q); i++) {
		if (p[i] == -1) {
			for (int j = 0; j < (1 << P); j++)
				eprintf("0");
		} else {
			for (int j = 0; j < (1 << P); j++)
				eprintf("%d", (int)blocks[p[i]].a[j]);
		}
		eprintf("|");
	}
	eprintf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < (1 << Q); i++)
		p[i] = -1;
	while(n--) {
		int x;
		scanf("%d", &x);
		int v = x >> P;
		if (p[v] == -1) p[v] = getNewBlock();
		blocks[p[v]].a[x & ((1 << P) - 1)] = 1;
	}
	for (int i = 0; i < (1 << Q); i++)
		if (p[i] != -1)
			blocks[p[i]].recalc();
//	eprintf("! %d\n", blocks[p[0]].cnt);
	while(q--) {
		//eprintAll();
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 4) {
			printf("%d\n", getAns(l, r));
		} else {
			int x;
			scanf("%d", &x);
			for (int i = 0; i < (1 << Q); i++)
				np[i] = -1;
			recalcFree();
			makeOp(t, l, r, x);
			for (int i = 0; i < (1 << Q); i++)
				p[i] = np[i];
		}
		/*
		eprintf("! %d\n", blocks[p[0]].cnt);
		for (int i = 0; i < 8; i++)
			eprintf("%d", (int)blocks[p[0]].a[i]);
		eprintf("\n");
		*/
	}

	return 0;
}