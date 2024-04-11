#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())

const int MAX_N = 2e5 + 100;

int N, All;
vector<int> Ans[MAX_N];
map<int, int> Mp;
int main() {
	cin >> N;
	for(int i=1; i<=N; i++) {
		int x; scanf("%d", &x);
		auto it = Mp.lower_bound(x);
		if(it == Mp.begin()) {
			All++;
			Ans[All].push_back(x);
			Mp[x] = All;
		} else {
			it--;
			int p, ix; tie(p, ix) = *it;
			Ans[ix].push_back(x);
			Mp.erase(it);
			Mp[x] = ix;
		}
	}
	for(int i=1; i<=All; i++, puts("")) for(int x : Ans[i]) printf("%d ", x);
	return 0;
}