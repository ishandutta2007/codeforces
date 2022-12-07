#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int t, n;
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		set<int> s;
		while (n--) {
			int x;
			cin >> x;
			s.insert(x);
		}
		cout << s.size() << "\n";
	}
	return 0;
}