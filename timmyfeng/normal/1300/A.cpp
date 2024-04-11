#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0, sol = 0;
        for (auto& i : a) {
            cin >> i;
            if (i == 0) {
                sol++;
                i++;
            }
            sum += i;
        }
        if (sum == 0) {
            sol++;
        }
        cout << sol << '\n';
    }
}