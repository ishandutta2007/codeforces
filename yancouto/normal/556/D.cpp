#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAX = 200009;
typedef unsigned long long ull;

struct range {
	ull s, e;
	int i;
	bool operator < (const range &o) const {
		if(e < o.e) return true;
		if(e == o.e) return s < o.s;
		return false;
	}
};

void imp() {
	puts("No");
	exit(0);
}

int main() {
	int n, m, i;
	int b[MAX];
	scanf("%d %d", &n, &m);
	range rs[MAX];
	multimap<ull, int> bs;
	ull prevl, prevr, l, r;
	scanf("%I64u %I64u", &prevl, &prevr);
	for(i = 1; i < n; i++) {
		scanf("%I64u %I64u", &l, &r);
		rs[i - 1].s = l - prevr;
		rs[i - 1].e = r - prevl;
		rs[i - 1].i = i - 1;
		prevl = l; prevr = r;
	}
	sort(rs, rs + n - 1);

	for(i = 0; i < m; i++) {
		scanf("%I64u", &l);
		bs.insert(pair<ull, int>(l, i + 1));
	}

	for(i = 0; i < n - 1; i++) {
		multimap<ull, int>::iterator it = bs.lower_bound(rs[i].s);
		if(it == bs.end() || it->first > rs[i].e) imp();
		b[rs[i].i] = it->second;
		bs.erase(it);
	}

	puts("Yes");
	printf("%d", b[0]);
	for(i = 1; i < n - 1; i++)
		printf(" %d", b[i]);
	printf("\n");
	return 0;
}