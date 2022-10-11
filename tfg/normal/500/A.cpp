#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for(int i = 0; i + 1 < n; i++) cin >> a[i];
	int st = 0;
	t--;
	while(st < t) st += a[st];
	cout << (st == t ? "YES\n" : "NO\n");
}