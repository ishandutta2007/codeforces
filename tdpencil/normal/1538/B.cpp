#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7, M = (1e9+7), MAXN = 1 * 2e5;
int A[MAXN], C[MAXN];


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    int s = 0;
    for(auto &i : A)
        cin >> i, s += i;

    if(s % N) {
        cout << -1 << "\n";
    } else {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] > s / N) {
                ++cnt;
            }
        }

        cout << cnt << "\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;

    while(T--) {
        solve();
    }
}