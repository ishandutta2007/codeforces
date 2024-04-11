#include <algorithm>
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

void solve() {
	int n, t;
	cin >> n >> t;
	int arrive = 1e9;
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		int s, d;
		cin >> s >> d;
		while(s < t) s += d;
		if(s < arrive) {
			arrive = s;
			ret = i;
		}
	}
	cout << ret << endl;
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