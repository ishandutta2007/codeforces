#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n;
vector<pair<int, int>> res;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	cin >> n;
	rep(i, 0, n) 
		rep(j, -1, 2)
			res.emplace_back(i, i + j);
	res.emplace_back(-1, 0);
	res.emplace_back(-1, -1);
	res.emplace_back(n, n - 1);
	res.emplace_back(n, n);
	cout << sz(res) << "\n";
	for (auto [a, b] : res)
		cout << a << " " << b << endl;
	return 0;
}