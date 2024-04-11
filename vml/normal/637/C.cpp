#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cstdio>
#include <cassert>
#include <climits>
#include <ctime>

using namespace std;

#define ll long long
#define mp make_pair

int n, ans = 6;
vector<string> v;
string s;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int tk = 0;
			for (int z = 0; z < v[i].length(); z++) {
				if (v[i][z] != v[j][z])
					tk++;
			}
			ans = min(ans, tk / 2 - (tk % 2 == 0 ? 1 : 0));
		}
	}
	cout << ans;

	return 0;
}