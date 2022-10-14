#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000 * 1000 + 10;
bool mark[MAXN];
int ps[MAXN];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector <int> ans;
	for(int i = 2; i <= 1000 * 1000; i++) {
		if(!mark[i]) {
			ans.push_back(i);
			for(int j = i * 2; j <= 1000 * 1000; j += i)
				mark[j] = 1;
		}
	}
	int n;
	cin >> n;
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		int k = sqrt(a), kk;
		k = upper_bound(ans.begin(), ans.end(), k) - ans.begin();
		if(a < ans[ans.size() - 1])
			kk = upper_bound(ans.begin(), ans.end(), a) - ans.begin();
		else
			kk = ans.size();
		//cout << k << " " << kk << endl;
		cout << kk - k + 1 << "\n";
	}
	return 0;
}