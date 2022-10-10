#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	map< pair<int, int>, int> M;
	map<int, int> occ;
	for(int i = 0; i < N-2; i++) {
		int a[3];
		for(int j = 0; j < 3; j++) {
			cin >> a[j];
			occ[a[j]]++;
		}
		sort(a, a+3);
		M[{a[0], a[1]}]++;
		M[{a[0], a[2]}]++;
		M[{a[1], a[2]}]++;
	}
	vector<int> sum_adj(N+1, 0);
	for(auto p : M) if(p.second == 2) {
		sum_adj[p.first.first] += p.first.second;
		sum_adj[p.first.second] += p.first.first;
	}
	int f = 1, s;
	while(occ[f] > 1) f++;
	for(auto p : M) if(p.first.first == f || p.first.second == f) {
		int x = p.first.first + p.first.second - f;
		if(occ[x] == 2) s = x;
	}
	cout << f << " " << s;
	occ.erase(f);
	sum_adj[s] += f;
	for(int i = 0; i < N-3; i++) {
		int n = sum_adj[s] - f;
		f = s;
		s = n;
		cout << " " << s;
	}
	for(auto p : occ) if(p.second == 1) cout << " " << p.first << "\n";
}