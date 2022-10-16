#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N = 2e5+7;

int n;
vector<int> mv[N];
bool u[N];

bool has(int x, int y) {
	for(int p : mv[x])
		if(p == y) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		mv[i+1].push_back(b);
		mv[i+1].push_back(a);
	}

	if(!has(mv[1][0], mv[1][1])) {
		swap(mv[1][1], mv[1][0]);
	}

	vector<int> res(n);
	res[0] = 1; u[1] = 1;
	res[1] = mv[1][0]; u[mv[1][0]] = 1;
	res[2] = mv[1][1]; u[mv[1][1]] = 1;
	for(int i = 1; i < n-2; ++i) {
		for(int x : mv[res[i]]) {
			if(!u[x]) {
				u[x] = 1;
				res[i+2] = x;
				break;
			}
		}
	}

	for(int i = 0; i < n; ++i)
		cout << res[i] << ' ';
}