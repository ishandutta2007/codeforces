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

int gcd(int a, int b) {
	while(b) {
		int c = a%b;
		a=b;
		b=c;
	}
	return a;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int gg = 0;
	for(int out: v) gg = gcd(out, gg);
	cout << "YES\n";
	if(gg > 1) {
		cout << "0\n";
		return;
	}
	int ret = 0;
	for(int i = 0; i < n;) {
		if(v[i]%2 == 0) {
			i++;
			continue;
		}
		int j = i+1;
		while(j < n && v[j]%2) j++;
		int sz = j-i;
		ret += sz/2;
		if(sz%2) ret += 2;
		i = j;
	}
	cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}