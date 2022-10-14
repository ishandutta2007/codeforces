#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum < 0) sum = abs(sum);

    cout << (sum + x - 1) / x << '\n';
}