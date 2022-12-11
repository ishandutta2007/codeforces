#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
int p[MAX_N], s[MAX_N], c[MAX_N];
bool strong[MAX_N];
vector <int> kek[MAX_N];

bool cmp(int a, int b) {
	return (p[a] < p[b]);
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) strong[i] = 0;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		kek[s[i]].push_back(i);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		strong[c[i]] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		sort(kek[i].begin(), kek[i].end(), cmp);
		for (int j = 0; j < ((int) kek[i].size()) - 1; j++) if (strong[kek[i][j]]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}