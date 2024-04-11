#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    int limak = -1;
    multiset<int> oth;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i == 0) {
            limak = a;
        } else {
            oth.insert(a);
        }
    }

    int ans = 0;
    while (*--oth.end() >= limak) {
        int u = *--oth.end();
        oth.erase(--oth.end());
        oth.insert(u - 1);
        ++limak;
        ++ans;
    }

    cout << ans << "\n";
}