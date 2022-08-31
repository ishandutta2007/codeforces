#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair

const int N = 100;

ll binom[N][N];

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	
	for (int i = 0; i < N; i++) {
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1; j < i; j++) 
			binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
	}
	int n;
	cin >> n;
	vector<int> res(31);
	vector<int> ans;
	for (int i = 30; i > 0; i--) {
		res[i] = 0;
		while (binom[i][8] <= n && n > 0) {
			n -= binom[i][8];
			res[i]++;
			ans.push_back(1);
		}
		ans.push_back(0);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans) {
		if (i == 0)
			cout << 'a';
		else
			cout << 'b';
	}
	cout << " aaaaaaaab" << endl;
	return 0;
}