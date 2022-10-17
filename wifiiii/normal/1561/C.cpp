#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            int need = 0;
            for(int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                need = max(need, x - j + 1);
            }
            a[i] = {need, m};
        }
        sort(a.begin(), a.end());
        int lo = 0, hi = 1e9 + 5;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int ok = 1, cur = mid;
            for(auto p : a) {
                if(cur < p.first) {
                    ok = 0;
                    break;
                }
                cur += p.second;
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
}