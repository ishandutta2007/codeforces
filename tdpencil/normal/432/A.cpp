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
	ll n, k;
	cin >> n >> k;
	vt<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	ll cnt = 0;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n-2; i+=3) {
		if (max(x[i], max(x[i + 1], x[i + 2])) <= 5-k) {
			++cnt;
		}
	}
	cout << cnt;

}