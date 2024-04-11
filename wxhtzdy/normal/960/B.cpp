#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<long long> s;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert((long long)abs(a[i] - b[i]));
    }
    while (k1 >= 1 || k2 >= 1){
        auto c = *s.rbegin();
        //cout << c << endl;
        bool ok = 1;
        if (c == 0) c = 2, ok = 0;
        //cout << c << endl << endl << endl;
        s.insert(c - 1);
        auto it = s.end();
        --it;
        if (!ok) --it;
        s.erase(it);
        if (k1 >= 1) k1--;
        else {
            if (k2 >= 1) k2--;
            else break;
        }
        //cout << k1 << " " << k2 << endl;
    }
    long long ans = 0;
    for (long long c : s) {
        ans += (long long) (c * c);
    }
    cout << ans << '\n';
    return 0;
}