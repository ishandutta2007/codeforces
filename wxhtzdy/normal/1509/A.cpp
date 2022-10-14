#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

void test_case() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) x.pb(a[i]);
        else y.pb(a[i]);
    }
    for (int i = 0; i < (int) x.size(); i++) cout << x[i] << " ";
    for (int i = 0; i < (int) y.size(); i++) cout << y[i] << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1; cin >> T;
    while (T--)
        test_case();
}