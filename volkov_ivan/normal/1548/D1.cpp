#include <bits/stdc++.h>

using namespace std;

long long cnk(long long n, long long k) {
    if (k == 2) {
        return n * (n - 1) / 2;
    }
    if (k == 3) {
        return n * (n - 1) * (n - 2) / 6;
    }
    assert(0);
}

int get(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first && a.second == b.second)
        return 3;
    return 1;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map <pair <int, int>, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        bool f1 = (x & 3), f2 = (y & 3);
        cnt[{f1, f2}]++;
    }
    for (auto uk1 = cnt.begin(); uk1 != cnt.end(); uk1++) {
        for (auto uk2 = uk1; uk2 != cnt.end(); uk2++) {
            for (auto uk3 = uk2; uk3 != cnt.end(); uk3++) {
                auto e1 = (*uk1).first, e2 = (*uk2).first, e3 = (*uk3).first;
                auto s = get(e1, e2) + get(e2, e3) + get(e3, e1);
                if ((s & 3) == 1) {
                    if (uk1 == uk2 && uk2 == uk3) {
                        ans += cnk((*uk1).second, 3);
                        continue;
                    }
                    if (uk1 == uk2) {
                        ans += cnk((*uk1).second, 2) * (*uk3).second;
                        continue;
                    }
                    if (uk2 == uk3) {
                        ans += cnk((*uk2).second, 2) * (*uk1).second;
                        continue;
                    }
                    ans += (*uk1).second * (*uk2).second * (*uk3).second;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}