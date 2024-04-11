#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it : a) {
        cin >> it;
    }
    for (auto &it : b) {
        cin >> it;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cnt1++;
        }
        if (a[i] < b[i]) {
            cnt2++;
        }
    }
    if (cnt1 == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << (cnt2 + cnt1) / cnt1 << '\n';
    }
}