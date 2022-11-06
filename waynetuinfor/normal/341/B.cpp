#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> lis = { a[1] };
    for (int i = 2; i <= n; ++i) {
        if (a[i] > lis.back()) lis.push_back(a[i]);
        else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
    }
    cout << lis.size() << endl;
}