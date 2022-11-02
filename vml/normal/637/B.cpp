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

int n;
vector<string> v;
set<string> ss;
string s;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (!ss.count(v[i])) {
			cout << v[i] << endl;
			ss.insert(v[i]);
		}
	}

	return 0;
}