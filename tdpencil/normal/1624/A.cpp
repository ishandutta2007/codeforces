#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <stack>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <string>
using namespace std;
int a[50], n, t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a,a+n);
		cout << a[n-1] - a[0] << "\n";
	}
}