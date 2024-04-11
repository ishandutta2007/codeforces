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

const int AND = 0;
const int OR = 1;
const int NAND = 2;
const int NOR = 3;

const int N = 111;

int n, m, k;
string s;
int a[N][3];
int b[N][3];
vector<int> g[N];
bool st[N];
int ord[N];
int ordSz;
int col[N];
int C;
bool used[N];
bool oldUsed[N];
ll G[N];

int readType() {
	cin >> s;
	if (s == "and") return AND;
	if (s == "or") return OR;
	if (s == "nand") return NAND;
	if (s == "nor") return NOR;
	throw;
}

void read() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		a[i][0] = readType();
		cin >> s;
		int p = 1;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'x') {
				a[i][p++] = j;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		b[i][0] = readType();
		cin >> s;
		int p = 1;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'x') {
				b[i][p++] = j;
			}
		}
	}
}

void addEdge(int v, int u) {
	g[v ^ 1].push_back(u);
	g[u ^ 1].push_back(v);
}

void addGraph(int v, int tp) {
	tp = a[v][0] ^ (tp << 1);
	if (tp == 0) {
		st[2 * a[v][1] + 1] = 1;
		st[2 * a[v][2] + 1] = 1;
	} else if (tp == 1) {
		addEdge(2 * a[v][1] + 1, 2 * a[v][2] + 1);
	} else if (tp == 2) {
		addEdge(2 * a[v][1], 2 * a[v][2]);
	} else if (tp == 3) {
		st[2 * a[v][1]] = 1;
		st[2 * a[v][2]] = 1;
	}
}

void dfsMark(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (!used[u])
			dfsMark(u);
	}
}

bool checkUsed() {
	for (int i = 0; i < n; i++)
		if (used[2 * i] && used[2 * i + 1])
			return false;
	return true;
}
bool checkSAT(ll MASK) {
	for (int i = 0; i < 2 * n; i++) {
		g[i].clear();
		st[i] = 0;
		used[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		if (((MASK >> i) & 1) == 0) continue;
		for (int j = 1; j < 3; j++)
			addGraph(b[i][j], (int)(b[i][0] < 2));
	}
	for (int i = 0; i < 2 * n; i++)
		if (st[i])
			dfsMark(i);
	if (!checkUsed()) return false;
	for (int i = 0; i < n; i++) {
		if (used[2 * i] || used[2 * i + 1]) continue;
		for (int j = 0; j < 2 * n; j++)
			oldUsed[j] = used[j];
		dfsMark(2 * i);
		if (checkUsed()) continue;
		for (int j = 0; j < 2 * n; j++)
			used[j] = oldUsed[j];
		dfsMark(2 * i + 1);
		if (!checkUsed()) return false;
	}
	return checkUsed();
}

int intVar[10];
int cntVar;

bool oper(int t, bool v1, bool v2) {
	bool res = 0;
	if (t >= 2) {
		t ^= 2;
		res ^= 1;
	}
	if (t == AND)
		return res ^ (v1 && v2);
	else
		return res ^ (v1 || v2);
}
bool getValConst(int v, int MASK) {
	for (int i = 0; i < cntVar; i++) {
		if (intVar[i] == v) {
			return (MASK >> i) & 1;
		}
	}
	throw;
}
bool getValA1(int v, int MASK) {
	return oper(a[v][0], getValConst(a[v][1], MASK), getValConst(a[v][2], MASK));
}
bool getValA2(int v, int MASK) {
	return oper(a[v][0] ^ 2, getValConst(a[v][1], MASK), getValConst(a[v][2], MASK));
}
bool getValB1(int v, int MASK) {
	return oper(b[v][0], getValA1(b[v][1], MASK), getValA1(b[v][2], MASK));
}
bool getValB2(int v, int MASK) {
	return oper(b[v][0] ^ 2, getValA2(b[v][1], MASK), getValA2(b[v][2], MASK));
}

bool solve(int id1, int id2) {
//	cerr << "SOLVE " << id1 << " " << id2 << endl;
	cntVar = 0;
	for (int i = 1; i < 3; i++)
		for (int j = 1; j < 3; j++) {
			intVar[cntVar++] = a[b[id1][i]][j];
			intVar[cntVar++] = a[b[id2][i]][j];
		}
	sort(intVar, intVar + cntVar);
	cntVar = unique(intVar, intVar + cntVar) - intVar;
	/*
	for (int i = 0; i < cntVar; i++)
		cerr << intVar[i] << " ";
	cerr << endl;
	*/
	for (int MASK = 0; MASK < (1 << cntVar); MASK++) {
//		cerr << MASK << " " << getValB1(id1, MASK) << " " << getValB2(id2, MASK) << endl;
		if (getValB1(id1, MASK) && getValB2(id2, MASK))
			return true;
	}
	return false;
}

bool isGoodMask(ll MASK) {
	return !checkSAT(MASK);
}

void eraseFromG(int v, int u) {
	if ((G[v] >> u) & 1)
		G[v] ^= 1LL << u;
}

int ANS = 0;

void brute(int curAns, ll curMask, ll cand, ll already) {
	if (cand == 0) {
		if (isGoodMask(curMask))
			ANS = max(ANS, curAns);
		return;
	}
	bool ok = true;
	for (int i = 0; ok && i < k; i++) {
		if (((already >> i) & 1) == 0) continue;
		if ((G[i] & cand) == cand) ok = false;
	}
	if (!ok) return;
	for (int v = 0; (1LL << v) <= cand; v++) {
		if (((cand >> v) & 1) == 0) continue;
		brute(curAns + 1, curMask | (1LL << v), (cand & G[v]) ^ (1LL << v), already & G[v]);
		already |= 1LL << v;
		cand ^= 1LL << v;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
/*
	for (int i = 0; i < m; i++) {
		cerr << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
	}
	for (int i = 0; i < k; i++) {
		cerr << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;
	}

	cerr << "read OK" << endl;

	if (checkSAT()) {
		cout << -1 << endl;
		return 0;
	}

	cerr << "SAT OK" << endl;
*/
	for (int i = 0; i < k; i++)
		G[i] = (1LL << k) - 1;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			if (solve(i, j)) {
//				cerr << "erase " << i << " " << j << endl;
				eraseFromG(i, j);
				eraseFromG(j, i);
			}
		}
	ll all = 0;
	for (int i = 0; i < k; i++) {
		if (((G[i] >> i) & 1) == 0) continue;
		all |= 1LL << i;
	}
	brute(0, 0, all, 0);
	if (ANS == 0)
		cout << -1 << endl;
	else
		cout << k - ANS << endl;

	return 0;
}