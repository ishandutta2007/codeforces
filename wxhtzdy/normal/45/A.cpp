#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> m = {{"January", 1}, {"February", 2}, {"March", 3}, {"April", 4} , {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};
	vector<string> v = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string s;
	cin >> s;
	int k;
	cin >> k;
	int indeks = m[s];
	cout << v[(indeks + k - 1) % 12];
	return 0;
}