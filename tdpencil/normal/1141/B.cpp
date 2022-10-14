#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	vector<int> a(n);

	for(auto &num: a)
		cin >> num;

	for(int i=0; i < n; i++) a.push_back(a[i]);
	if(*max_element(a.begin(), a.end()) != 1) {
		cout << 0 << '\n';
		return 0;
	}
	int mx = 1;

	int last = a[0];
	int temp = 1;
	for(int i = 1; i < int(a.size()); i++) {
		if(last == 1 && a[i] == last) {
			temp++;
		} else {
			temp = 1;
			last = a[i];
		}
		mx = max(temp, mx);
	}

	cout << mx << '\n';
}