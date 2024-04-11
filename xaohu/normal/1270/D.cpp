#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, k;

pair<int, int> ask(vector<int> v) {
	cout << "? ";
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	int a, b;
	cin >> a >> b;
	return {a, b};
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	
	vector<int> v(k, 0);
	iota(v.begin(), v.end(), 1);
	
	auto [p, val] = ask(v);
	
	v[p - 1] = k + 1;
	int side = (val < ask(v).second);
	v[p - 1] = p;
	
	int res = 0;
	rep(i, 1, k + 1) {
		if (i == p) continue;
		v[i - 1] = k + 1;
		if (side == 0)
			res += ask(v).second == val;
		if (side == 1)
			res += ask(v).second != val;
		v[i - 1] = i;
	}
	cout << "! " << res + 1 << endl;
	return 0;
}