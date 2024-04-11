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
template<typename T>
ll max3(vector<T>& n) {
	return max(n[0], max(n[1], n[2]));
}
int main() {
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		ll x, y;
		cin >> x >> y;
		ll temp = 24 * 60;
		ll temp1 = x * 60 + y;
		cout << temp - temp1 << '\n';
	}

}