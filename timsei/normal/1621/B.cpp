#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int l, r, Min1, Min2, n, a, b, c;

map < pair <int, int>, int> Map;

int main() {
	int t;
	for(cin >> t; t --;) {
		Min1 = Min2 = 1e9 + 5;
		l = 2e9, r = -2e9;
		cin >> n; Map.clear();
		for(int i = 1; i <= n; ++ i) {
			scanf("%d%d%d", &a, &b, &c);
			if(!Map.count(make_pair(a, b))) {
				Map[make_pair(a, b)] = c;
			} else Map[make_pair(a, b)] = min(Map[make_pair(a, b)], c);
			
			if(a < l) {
				l = a, Min1 = c;
			} else if(l == a) Min1 = min(Min1, c);
			if(b > r) {
				r = b, Min2 = c;
			} else if(r == b) Min2 = min(Min2, c);
			int ans = Min1 + Min2;
			if(Map.count(make_pair(l, r)))
			ans = min(ans, Map[make_pair(l, r)]);
			printf("%d\n", ans); 
		}
	}
}