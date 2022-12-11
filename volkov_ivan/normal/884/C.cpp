#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int p[MAX_N + 1];
bool visited[MAX_N + 1];

int DFS(int u) {
	visited[u] = 1;
	if (!visited[p[u]]) {
		return DFS(p[u]) + 1;
	}
	return 1;
}

vector <long long> laps;

bool cmp(long long a, long long b) {
	return (a > b);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//cin >> p[i + 1];
		scanf("%d ", &p[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			laps.push_back(DFS(i));
		}
	}
	stable_sort(laps.begin(), laps.end(), cmp);
	if (laps.size() == 1) {
		cout << laps[0] * laps[0] << endl;
		return 0;
	}
	long long ans = (laps[0] + laps[1]) * (laps[0] + laps[1]);
	for (int i = 2; i < laps.size(); i++) {
		ans += laps[i] * laps[i];
	}
	cout << ans << endl;
	return 0;
}