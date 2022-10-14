#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        vector<int> a(4);

        for(auto &i : a) cin >> i;


        int mx1 = max(a[0], a[1]);
        int mx2 = max(a[2], a[3]);

        sort(a.begin(), a.end());
        if((mx1 == a[3] && mx2 == a[2]) || (mx2 == a[3] && mx1 == a[2])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}