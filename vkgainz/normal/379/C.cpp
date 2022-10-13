#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int curr = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(curr < a[i].first) curr = a[i].first;
        ans[a[i].second] = curr;
        ++curr;
    }
    for(int x : ans)
        cout << x << " ";
}