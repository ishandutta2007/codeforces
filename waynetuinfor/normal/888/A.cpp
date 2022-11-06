#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int c = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) ++c;
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) ++c;
    }
    cout << c << endl;
}