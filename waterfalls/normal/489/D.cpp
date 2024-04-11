#include <iostream>
#include <bitset>
#include <vector>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
	vector< bitset<3013> > roadsets(n + 1);
	vector< vector<int> > roads_to(n + 1);
 
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		roads_to[a].push_back(b);
		roadsets[a][b] = 1;
	}
 
	int total_cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int c = 1; c <= n; ++c) {
			if (c == i) continue;
			int num_overlap = 0;
			for (int b : roads_to[i]) {
				if (roadsets[b][c]) {
					num_overlap += 1;
				}
			}
			total_cnt += (num_overlap * (num_overlap - 1)) / 2;
		}
	}
	cout << total_cnt << "\n";
}