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

void die() {
	cout << ":(\n";
	exit(0);
}

int colMax[1000];
int rowMax[1000];
void solve() {
	int r, c, h;
	cin >> r >> c >> h;
	for(int i = 0; i < c; i++) cin >> colMax[i];
	for(int i = 0; i < r; i++) cin >> rowMax[i];
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int t;
			cin >> t;
			if(t == 0) cout << 0;
			else cout << min(colMax[j], rowMax[i]);
			if(j == c-1) cout << "\n";
			else cout << " ";
		}
	}
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