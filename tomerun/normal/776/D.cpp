#include <iostream>
#include <vector>
#include <array>

using namespace std;
using ull = uint64_t;

int N, M;

int main() {
	cin >> N >> M;
	vector<int> R(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &R[i]);
	}
	vector<vector<int>> door;
	door.reserve(M);
	vector<array<int, 2>> sw(N);
	for (int i = 1; i <= M; i++) {
		int x;
		scanf("%d", &x);
		vector<int> xs(x);
		for (int j = 0; j < x; ++j) {
			scanf("%d", &xs[j]);
			xs[j]--;
			if (sw[xs[j]][0] == 0) {
				sw[xs[j]][0] = i - 1;
			} else {
				sw[xs[j]][1] = i - 1;
			}
		}
		door.push_back(move(xs));
	}

	vector<int> swColor(M);
	vector<int> q;
	for (int i = 0; i < N; i++) {
		if (swColor[sw[i][0]] != 0) continue;
		swColor[sw[i][0]] = 1;
		swColor[sw[i][1]] = R[i] == 0 ? -1 : 1;
		q.clear();
		q.push_back(sw[i][0]);
		q.push_back(sw[i][1]);
		for (int j = 0; j < q.size(); j++) {
			int s = q[j];
			for (int d : door[s]) {
				int o = sw[d][0] == s ? sw[d][1] : sw[d][0];
				int expect = swColor[s] * (R[d] == 0 ? -1 : 1);
				if (swColor[o] == 0) {
					swColor[o] = expect;
					q.push_back(o);
					continue;
				}
				if (swColor[o] != expect) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
}