#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int INF = 2e9;

int n, res = INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1; i*i <= n; ++i) 
		res = min(res, i + (n+i-1)/i);

	cout << res;
}