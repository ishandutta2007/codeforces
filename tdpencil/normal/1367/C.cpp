#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        int N, K;
        cin >> N >> K;
        string G;
        cin >> G;
        vector<int> added;
        added.push_back(-K - 1);
        for(int i = 0; i < N; i++)
            if(G[i] == '1')
                added.push_back(i);

        added.push_back(N + K);
        int ans = 0;
        for(int i = 0; i < added.size() - 1; i++) {
            if(added[i + 1] - added[i] - 1 * 2*K <= 0)
                continue;
            int R = (added[i + 1] - added[i] - 1 - 2*K + K) / (K + 1);
            ans += R;
        }

        cout << ans << '\n';

    }
}