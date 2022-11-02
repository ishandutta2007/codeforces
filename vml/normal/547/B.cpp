//#pragma comment (linker, "/STACK:1000000000")
 
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
 
using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

int ans[maxn];
 
int main() {
	int n;

	scanf("%d", &n);

	set <pair <int, int> > s;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		s.insert(make_pair(v[i], i));
	}

	set <pair <int, int> > segm;
	segm.insert(make_pair(0, n - 1));
	multiset <int> l;
	l.insert(n);

	int now = n;

	for (int i = 0; i < n - 1; i++) {
		int f = (*s.begin()).second;
		s.erase(s.begin());

		set <pair <int, int> >::iterator it = segm.lower_bound(make_pair(f + 1, -1));
		it--;

		l.erase(l.find((it->second - it->first + 1)));
		if (f != it->first) {
			l.insert(f - it->first);
			segm.insert(make_pair(it->first, f - 1));
		}

		if (f != it->second) {
			l.insert(it->second - f);
			segm.insert(make_pair(f + 1, it->second));
		}

		segm.erase(it);

		int maxx = (*l.rbegin());

		while (now > maxx) {
			ans[now] = v[f];
			now--;
		}
	}

	ans[1] = (*s.begin()).first;

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}