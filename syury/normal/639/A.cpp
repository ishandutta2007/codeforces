#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

const int MAXN = 2e5;

int t[MAXN];

set <pair <int, int> > s;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n, k, q; scanf("%d%d%d", &n, &k, &q);
	
	for (int i = 0; i < n; i++)
		scanf("%d", t + i);
	
	for (int i = 0; i < q; i++) {
		int type, id; scanf("%d%d", &type, &id); id--;
		if (type == 1)
			s.insert({t[id], id});
		else {
			if (s.find({t[id], id}) != s.end())
				printf("YES\n");
			else
				printf("NO\n");
		}
		while (int(s.size()) > k)
			s.erase(s.begin());
	}
	
	return 0;
}