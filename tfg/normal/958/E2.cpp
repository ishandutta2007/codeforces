#include <bits/stdc++.h>
using namespace std;

int N, K, tot;
set<pair<int, int>> S;
set<pair<int, int>> L;
int T[500005];
int l, x;

int main() {
	scanf("%d%d", &K, &N);

	for (int i = 0; i < N; ++i) scanf("%d", T+i);

	sort(T, T+N);
	for (int i = 0; i < N; ++i) {
		x = T[i];
		if (i) S.insert({x - l, i}), L.insert({i, x - l});
		l = x;
	}

	while (--K) {
		auto P = *S.begin(); S.erase(P); L.erase({P.second, P.first});
		tot += P.first;

		auto N = L.lower_bound({P.second, -2e9});
		if (N == L.begin()) {
			if (N != L.end()) {
				S.erase({N->second, N->first});
				L.erase(N);
			}
			continue;
		}

		auto B = prev(N);
		if (N == L.end()) {
			S.erase({B->second, B->first});
			L.erase(B);
			continue;
		}

		P.first = N->second + B->second - P.first;
		P.second = B->first;
		S.erase({N->second, N->first}); S.erase({B->second, B->first});
		L.erase(N); L.erase(B);

		S.insert(P); L.insert({P.second, P.first});
	}

	auto P = *S.begin(); S.erase(P); L.erase({P.second, P.first});
	tot += P.first;

	printf("%d\n", tot);
}