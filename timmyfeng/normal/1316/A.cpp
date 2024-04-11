#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    int sum = 0;
	    while (n--) {
	        int a;
	        cin >> a;
	        sum += a;
	    }
	    cout << min(sum, m) << '\n';
	}
}