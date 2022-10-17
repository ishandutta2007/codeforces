#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> a;
    for(int i = 1; i <= 9; ++i) {
        ll cur = i;
        for(int j = 0; j <= 9; ++j) {
            a.push_back(cur);
            cur = cur * 10 + i;
        }
    }
    sort(a.begin(), a.end());
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << upper_bound(a.begin(), a.end(), n) - a.begin() << '\n';
    }
}