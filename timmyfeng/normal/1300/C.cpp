#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> freq(30);
	for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) {
                freq[j].push_back(i);
            }
        }
    }
    for (int i = 29; i >= 0; i--) {
        if (freq[i].size() == 1) {
            swap(a[freq[i].front()], a[0]);
            break;
        }
    }
    for (auto& i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}