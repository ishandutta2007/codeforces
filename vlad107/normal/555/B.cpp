#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define pb push_back
#define mp make_pair
#define y0 y00000000
#define y1 y11111111
#define next nextttt
#define prev prevvvv
#define ll long long

using namespace std;

const int N = 4e5;
const string I64 = "%I64d";

pair<ll, ll> a[N];
pair<ll, int> b[N];
int ans[N];

bool cmp(pair<pair<ll,ll>,int> u, pair<pair<ll,ll>,int> v) {
	if (u.first.second != v.first.second) return u.first.second < v.first.second;
	return u.first.first < v.first.first;
}

int main() {
	// freopen("b.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf((I64 + I64).c_str(), &a[i].first, &a[i].second);
	vector< pair<pair<ll, ll>, int> > v;
	for (int i = 0; i + 1 < n; i++) {
		v.pb(mp(mp(a[i + 1].first - a[i].second, a[i + 1].second - a[i].first), i));
	}
	sort(v.begin(), v.end(), cmp);
	// for (int i = 0; i < v.size(); i++) cerr << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
	set< pair<ll, int> > b;
	for (int i = 0; i < m; i++) {
		ll x;
		scanf(I64.c_str(), &x);
		b.insert(mp(x,i));
	}
	// for (int i = 0; i < m; i++) cerr << b[i].first << endl;
	// cerr << "-" << endl;
	for (int i = 0; i < v.size(); i++) {
		set< pair<ll, int> >::iterator it = b.lower_bound(mp(v[i].first.first, -1));
		if (it == b.end()) {
			puts("No");
			return 0;
		}
		if (it -> first > v[i].first.second) {
			puts("No");
			return 0;
		}
		ans[v[i].second] = it->second;
		b.erase(it);
	}
	puts("Yes");
	for (int i = 0; i < n - 1; i++) printf("%d ", ans[i] + 1);
	puts("");
}