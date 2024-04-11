#include <bits/stdc++.h>
using namespace std;

const string F[] = {
    "", "", "2", "3", "223", "5", "35", "7", "2227", "2337"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string ans;
    for (auto i : s) {
        ans += F[i - '0'];
    }

    sort(ans.rbegin(), ans.rend());

    cout << ans << "\n";
}