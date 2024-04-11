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

void solve() {
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		if(n%2==0) n/=2;
		if(n%5==0) n/=5;
	}
	cout << n;
	while(k--) cout << 0;
	cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}