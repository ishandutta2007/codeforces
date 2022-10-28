#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
//    freopen("tmp.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        long long neg, big, prev, tmp;
        cin >> n >> prev;
        big = prev;
        if (prev <= 0) neg = prev;
        else neg = 1;
//        cout << prev << " ";
        for (int i = 1; i < n; i++) {
            cin >> tmp;
            prev += tmp;
            neg = min(neg, prev);
            if (neg == 1) {
                if (i + 1 < n)
                    big = max(big, prev);
            }
            else
                big = max(big, prev - neg);
//            cout << prev << " ";
        }
        if (big >= prev) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}