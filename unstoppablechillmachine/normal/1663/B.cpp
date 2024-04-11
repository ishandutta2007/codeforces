    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ld = long double;
    #define all(x) (x).begin(), (x).end()
    #define SZ(x) (int)(x).size()
     
    signed main() {
    #ifdef PC
        freopen("input.txt", "r", stdin);
    #endif
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> roflan = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
        int x;
        cin >> x;
        cout << *upper_bound(all(roflan), x) << '\n';
    }