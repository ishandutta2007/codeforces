#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin >> n;
	long long ans = 0;
	int odd = 2e9;
	while (n--) {
		cin >> x;
		ans+=x;
		if (x%2) odd = min(odd,x);
	}
	cout << (ans-(ans%2)*odd);
}