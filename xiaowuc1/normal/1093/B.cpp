#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void realsolve() {
	string s;
	cin >> s;
	vector<char> v;
	for(int i = 0; i < s.size(); i++) v.push_back(s[i]);
	sort(v.begin(), v.end());
	bool good = false;
	for(int i = 0; i < s.size(); i++) good |= v[i] != v[s.size()-1-i];
	if(!good) cout << "-1\n";
	else {
		for(char out: v) cout << out;
		cout << "\n";
	}
}

void solve() {
	int t;
	cin >> t;
	while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}