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
#include <array>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 1 << 18;
int n, m;
pii f[N];
int cnt[N];
multiset<pii> setik;	

struct Node {
	int mx, l, r;

	Node(int _mx = 0, int _l = 0, int _r = 0) : mx(_mx), l(_l), r(_r) {}
} st[N << 1];

Node comb(Node a, Node b) {
	Node ret;
	ret.mx = max(a.mx, b.mx);
	ret.l = a.l;
	ret.r = b.r;
	return ret;
}
void build(int p, int l, int r) {
	if(l == r) {
		st[p] = Node(f[l].fi + f[l].se, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	st[p] = comb(st[p * 2], st[p * 2 + 1]);
}
int get(int p, int l, int r) {
	if(st[p].l > r || st[p].r < l) return 0;
	if(l <= st[p].l && st[p].r <= r) return st[p].mx;
	return max(get(p * 2, l, r), get(p * 2 + 1, l, r));
}
void modify(int p, int x) {
	if(st[p].l == st[p].r) {
		st[p].mx = f[x].fi + f[x].se;
		return;
	}
	int mid = (st[p].l + st[p].r) >> 1;
	if(x <= mid) modify(p * 2, x);
	else modify(p * 2 + 1, x);
	st[p] = comb(st[p * 2], st[p * 2 + 1]);
}

void update(int i) {
	while(1) {
		auto it = setik.lower_bound(mp(f[i].fi, -1));
		if(it != setik.end() && (*it).fi <= f[i].fi + f[i].se) {
			cnt[i]++;
			f[i].se += (*it).se;
			setik.erase(it);
		} else break;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &f[i].fi, &f[i].se);
	vector<int> order(n);
	iota(all(order), 0);
	sort(all(order), [&](int i, int j) {
		return f[i].fi < f[j].fi;
	});
	vector<int> toP(n);
	for(int i = 0; i < n; i++)
		toP[order[i]] = i;
	sort(f, f + n);
	build(1, 0, n - 1);
	while(m--) {
		int p, b;
		scanf("%d%d", &p, &b);
		if(f[0].fi > p) {
			setik.insert(mp(p, b));
			continue;
		}
		int l = 0, r = n - 1, who = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(f[mid].fi > p) r = mid - 1;
			else if(get(1, 0, mid) >= p) r = mid - 1, who = mid;
			else l = mid + 1;
		}
		if(who == -1 || f[who].fi + f[who].se < p) {
			setik.insert(mp(p, b));
			continue;
		}
		f[who].se += b;
		cnt[who]++;
		update(who);
		modify(1, who);
	}
	for(int i : toP)
		printf("%d %d\n", cnt[i], f[i].se);
	return 0; 
}