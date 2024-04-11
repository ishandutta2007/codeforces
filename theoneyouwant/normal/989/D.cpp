#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, wmax;
    cin >> n >> l >> wmax;
    vector<int> plus, minus;
    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        if (v == 1)
            plus.push_back(x);
        else
            minus.push_back(x);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    long long cnt = 0;
    auto it = minus.begin();
    for (int x : plus) {
        while (it != minus.end() && (*it < x || wmax * (long long)(*it - x + l) <= abs(*it + x + l)))
            ++it;
        cnt += minus.end() - it;
    }
    cout << cnt << '\n';
}