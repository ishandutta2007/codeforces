#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = -1;
const int C = -1;

int n, q;
vector<set< pair<long long, int> > > set_in;
vector<int> nxt, deg;
vector<long long> t, cost_in, self;
multiset<long long> all;

void rem_all(int x) {
	if (!set_in[x].empty()) {
		long long bb = t[x] / (set_in[x].size() + 2);
		all.erase(all.find(bb + set_in[x].begin()->first));
		if (set_in[x].size() > 1) all.erase(all.find(bb + set_in[x].rbegin()->first));
	}	
}

void add_all(int x) {
	if (!set_in[x].empty()) {
		long long bb = t[x] / (set_in[x].size() + 2);
		all.insert(bb + set_in[x].begin()->first);
		if (set_in[x].size() > 1) all.insert(bb + set_in[x].rbegin()->first);
	}	
}

void upd(int x, int y, long long oldcost, long long newcost) {
	rem_all(x);
	set_in[x].erase(mp(oldcost, y));	
	set_in[x].insert(mp(newcost, y));
	add_all(x);
}

void ins(int x, int y) {
	// cerr << "here 1" << endl;
	rem_all(x);
	// cerr << "here 2" << endl;
	long long oldcost = cost_in[x];
	long long oldself = self[x];
	cost_in[x] += t[y] / (deg[y] + 2);
	set_in[x].insert(mp(cost_in[y] + self[y], y));
	self[x] = t[x] - (deg[x] + 1) * (t[x] / (deg[x] + 2));
	upd(nxt[x], x, oldcost + oldself, cost_in[x] + self[x]);
	add_all(x);
}

void rem(int x, int y) {
	rem_all(x);
	long long oldcost = cost_in[x];
	long long oldself = self[x];
	cost_in[x] -= t[y] / ((int)set_in[y].size() + 2);
	set_in[x].erase(mp(cost_in[y] + self[y], y));
	self[x] = t[x] - ((int)set_in[x].size() + 1) * (t[x] / ((int)set_in[x].size() + 2));
	upd(nxt[x], x, oldcost + oldself, cost_in[x] + self[x]);
	add_all(x);
	deg[x] = set_in[x].size();
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	t.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &t[i]);
	}
	nxt.resize(n);
	deg.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nxt[i]);
		--nxt[i];
		++deg[nxt[i]];
	}
	cost_in.resize(n);
	self.resize(n);
	set_in.resize(n);
	for (int i = 0; i < n; i++) {
		self[i] = t[i] - (deg[i] + 1) * ((t[i] / (deg[i] + 2)));
	}
	for (int i = 0; i < n; i++) {
		ins(nxt[i], i);
	}
	while (q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			int nx = nxt[x];
			int nx2 = nxt[nx];
			int nx3 = nxt[nx2];
			long long newcost = cost_in[nx2] - t[nx] / ((int)set_in[nx].size() + 2) + t[nx] / ((int)set_in[nx].size() + 1);
			upd(nx3, nx2, self[nx2] + cost_in[nx2], self[nx2] + newcost);
			cost_in[nx2] = newcost;
			rem(nx, x);


			int ny = nxt[y];
			int ny2 = nxt[ny];
			newcost = cost_in[ny] - t[y] / ((int)set_in[y].size() + 2) + t[y] / ((int)set_in[y].size() + 3);
			upd(ny2, ny, self[ny] + cost_in[ny], self[ny] + newcost);
			cost_in[ny] = newcost;
			++deg[y];
			ins(y, x);
			nxt[x] = y;
			} else if (tp == 2) {
			int x;
			scanf("%d", &x);
			--x;
			int nx = nxt[x];
			long long bb = t[nx] / ((int)set_in[nx].size() + 2);
			printf("%I64d\n", cost_in[x] + self[x] + bb);
		} else if (tp == 3) {
			printf("%I64d %I64d\n", *all.begin(), *all.rbegin());
		}
	}
	return 0;
}