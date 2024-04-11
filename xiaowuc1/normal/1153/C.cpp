#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

void die() {
	cout << ":(\n";
	exit(0);
}

vector<char> solve(string s) {
	vector<char> c;
	for(int i = 0; i < s.size(); i++) {
		c.push_back(s[i]);
	}
	int d = 0;
	for(int i = 0; i < s.size(); i++) {
		if(c[i] == '?') {
			c[i] = '(';
		}
		if(c[i] == '(') d++;
		else if(--d < 0) die();
	}
	for(int i = s.size()-1; i >= 0 && d > 0; i--) {
		if(s[i] == '?') {
			d -= 2;
			c[i] = ')';
		}
	}
	for(int i = 0; i < s.size(); i++) {
		if(c[i] == '(') d++;
		else if(--d < 0) die();
	}
	if(d != 0) die();
	return c;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	if(n%2) die();
	if(s[0] == ')' || s[n-1] == '(') die();
	vector<char> goal = solve(s.substr(1, n-2));
	cout << "(";
	for(char out: goal) cout << out;
	cout << ")\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	/*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
	*/
	solve();
}