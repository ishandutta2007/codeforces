#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	
	int n, k;
	cin >> n >> k;
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a.begin(), a.end());
	ll res = 0;
	for (int i = 0; i < k; i++)
		res += a[i];
	cout << res << endl;
	return 0;
}