#include <bits/stdc++.h>

using namespace std;

int main() {
 	int n;
 	cin >> n;
 	vector<bool> was(n + 1, false);
 	int p;
 	cin >> p;
 	for (int i = 0; i < p; i++) {
 		int a;
 		cin >> a;
 		was[a] = true;
 	}
 	int q;
 	cin >> q;
 	for (int i = 0; i < q; i++) {
 	 	int a;
 	 	cin >> a;
 	 	was[a] = true;
 	}
 	for (int i = 1; i <= n; i++) {
 	 	if (was[i] == false) {
 	 	 	cout << "Oh, my keyboard!";
 	 	 	return 0;
 	 	}
 	}
 	cout << "I become the guy.";
}