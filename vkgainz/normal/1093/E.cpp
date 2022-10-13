#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;

int n, m;
int a[N], b[N], pos[N];

vector<int> f[N];
vector<int> vals[N];

void addupd(int x, int y){
	for (int i = x; i < N; i |= i + 1)
		vals[i].push_back(y);
}

void addget(int x, int y){
	if (x < 0 || y < 0) return;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		vals[i].push_back(y);
}

void upd(int x, int y, int val){
	for (int i = x; i < N; i |= i + 1)
		for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j < int(f[i].size()); j |= j + 1)
			f[i][j] += val;
}

int get(int x, int y){
	if (x < 0 || y < 0) return 0;
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0; j = (j & (j + 1)) - 1)
			res += f[i][j];
	return res;
}

struct query{
	int t, la, ra, lb, rb;
	query(){};
};

query q[N];

int main() {
	scanf("%d%d", &n, &m);
	
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
		pos[a[i]] = i;
	}
	
	forn(i, n){
		scanf("%d", &b[i]);
		--b[i];
		b[i] = pos[b[i]];
	}
	
	forn(i, m){
		scanf("%d", &q[i].t);
		if (q[i].t == 1){
			scanf("%d%d%d%d", &q[i].la, &q[i].ra, &q[i].lb, &q[i].rb);
			--q[i].la, --q[i].ra, --q[i].lb, --q[i].rb;
		}
		else{
			scanf("%d%d", &q[i].lb, &q[i].rb);
			--q[i].lb, --q[i].rb;
		}
	}
	
	vector<int> tmp(b, b + n);
	
	forn(i, n) addupd(i, b[i]);
	forn(i, m){
		if (q[i].t == 1){
			addget(q[i].rb, q[i].ra);
			addget(q[i].lb - 1, q[i].ra);
			addget(q[i].rb, q[i].la - 1);
			addget(q[i].lb - 1, q[i].la - 1);
		}
		else{
			addupd(q[i].lb, b[q[i].lb]);
			addupd(q[i].rb, b[q[i].rb]);
			swap(b[q[i].lb], b[q[i].rb]);
			addupd(q[i].lb, b[q[i].lb]);
			addupd(q[i].rb, b[q[i].rb]);
		}
	}
	
	forn(i, n) b[i] = tmp[i];
	
	forn(i, N){
		sort(vals[i].begin(), vals[i].end());
		vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
		f[i].resize(vals[i].size(), 0);
	}
	
	forn(i, n)
		upd(i, b[i], 1);
	
	forn(i, m){
		if (q[i].t == 1){
			int res = 0;
			res += get(q[i].rb, q[i].ra);
			res -= get(q[i].lb - 1, q[i].ra);
			res -= get(q[i].rb, q[i].la - 1);
			res += get(q[i].lb - 1, q[i].la - 1);
			printf("%d\n", res);
		}
		else{
			upd(q[i].lb, b[q[i].lb], -1);
			upd(q[i].rb, b[q[i].rb], -1);
			swap(b[q[i].lb], b[q[i].rb]);
			upd(q[i].lb, b[q[i].lb], 1);
			upd(q[i].rb, b[q[i].rb], 1);
		}
	}
	return 0;
}