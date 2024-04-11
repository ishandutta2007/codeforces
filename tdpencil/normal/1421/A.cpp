#include<iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define ll long long
#define vt vector
struct edge {
	ll node;
	ll next;
	ll cost;
};

int main() {
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		ll ans = (x ^ (x & y)) + (y ^ (x & y));
		cout << ans << '\n';
	}

}