#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int a[maxn * maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n * n; ++i) cin >> a[i];
    multiset<int> s;
    for (int i = 0; i < n * n; ++i) s.insert(a[i]);
    vector<int> ans;
    while (s.size()) {
        int now = *prev(s.end());
        for (int j : ans) s.erase(s.find(__gcd(j, now))), s.erase(s.find(__gcd(j, now)));
        ans.push_back(now);
        s.erase(s.find(now));
    }
    for (int i : ans) cout << i << ' '; cout << endl;
}