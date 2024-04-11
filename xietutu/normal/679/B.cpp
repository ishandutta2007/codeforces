#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, LL> arr;
LL m;
arr solve(LL m) {
	if (m == 0) return arr(0, 0);
	if (m == 1) return arr(1, 1);
	LL a = 1;
	for (; a * a * a <= m; ++a) ;
	--a;
	LL a3 = a * a * a;
	arr ret = solve(m - a3);
	++ret.first;
	ret.second += a3;
	
	if (a > 1) {
		--a;
		arr tmp = solve(a3 - 1 - a * a * a);
		++tmp.first;
		tmp.second += a * a * a;
		
		ret = max(ret, tmp);
	}
	return ret;
}
int main() {
	cin >> m;
	arr ret = solve(m);
	cout << ret.first << " " << ret.second;
}