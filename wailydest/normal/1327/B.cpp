#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve()
{
    int n, sz;
    cin >> n;
    
    vector<vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> sz;
        v[i].resize(sz);
        for (int j = 0; j < sz; ++j) cin >> v[i][j];
    }
    
    int failed = -1;
    unordered_set<int> ppl;
    for (int i = 1; i <= n; ++i) ppl.insert(i);
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < v[i].size() && !ppl.count(v[i][j])) {
            ++j;
        }
        if (failed == -1 && j == v[i].size() && v[i].size() != n) failed = i;
        if (j != v[i].size()) ppl.erase(v[i][j]);
    }
    
    if (failed != -1) {
        cout << "IMPROVE\n";
        cout << failed + 1 << ' ';
        cout << *ppl.begin() << '\n';
    }
    else cout << "OPTIMAL\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}