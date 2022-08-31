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

const int N = (1 << 17);
struct Node {
	int l, r;
	pii a[2];

	Node() : l(-1), r(-1), a() {}
	Node(int _l, int _r) : l(_l), r(_r), a() {}

	void setOp(int id) {
		if (id == -1) {
			a[0] = a[1] = mp(0, 0);
		} else if (id == -2) {
			a[0] = a[1] = mp(1, 0);
		} else {
			assert(1 <= id && id <= 7);
			a[0] = mp(0, id);
			a[1] = mp(1, 0);
		}
	}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

Node merge(Node L, Node R) {
	if (L.l == -1) return R;
	if (R.l == -1) return L;
	Node A = Node(L.l, R.r);
	for (int i = 0; i < 2; i++) {
		A.a[i] = R.a[L.a[i].first];
		if (A.a[i].second == 0) A.a[i].second = L.a[i].second;
	}
	return A;
}

void setV(int v, int id) {
	v += N;
	tree[v].setOp(id);
	while(v > 1) {
		v >>= 1;
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
}

Node getSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v];
	if (l >= tree[v].r || tree[v].l >= r) return Node();
	return merge(getSegm(2 * v, l, r), getSegm(2 * v + 1, l, r));
}

int readOp() {
	string s;
	cin >> s;
	if (s == "lock") return -2;
	if (s == "unlock") return -1;
	if (s == "red") return 1;
	if (s == "orange") return 2;
	if (s == "yellow") return 3;
	if (s == "green") return 4;
	if (s == "blue") return 5;
	if (s == "indigo") return 6;
	if (s == "violet") return 7;
	assert(false);
}

void printAns(Node A) {
	int c = A.a[0].second;
	if (c == 0) c = 5;
	if (c == 1) cout << "red\n";
	if (c == 2) cout << "orange\n";
	if (c == 3) cout << "yellow\n";
	if (c == 4) cout << "green\n";
	if (c == 5) cout << "blue\n";
	if (c == 6) cout << "indigo\n";
	if (c == 7) cout << "violet\n";
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	build();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		setV(i, readOp());
	}
	printAns(getSegm(1, 0, n));
	/*
	int q;
	cin >> q;
	while(q--) {
		int v;
		cin >> v;
		v--;
		setV(v, readOp());
		printAns(getSegm(1, 0, n));
	}
	*/

	return 0;
}