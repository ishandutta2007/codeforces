#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    deque<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<array<int, 2>> ans(N);
    for (int i = 0; i < N; ++i) {
        ans[i] = {a[0], a[1]};
        auto [A, B] = minmax({a[0], a[1]});
        a.pop_front();
        a.pop_front();
        a.push_front(B);
        a.push_back(A);
    }
    for (int q = 0; q < Q; ++q) {
        long long m;
        cin >> m;
        --m;
        if (m < N) {
            cout << ans[m][0] << ' ' << ans[m][1] << '\n';
        } else {
            cout << a[0] << ' ' << a[1 + (m - N) % (N - 1)] << '\n';
        }
    }
    exit(0);
}