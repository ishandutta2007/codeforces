#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<pair<int,int>> a(3);
        for(auto &[x, y] : a) {
            cin >> y >> x;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        if(a[0].first == a[1].first) {
            cout << abs(a[0].second - a[1].second) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}