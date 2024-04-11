#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7, M = (1e9+7), MAXN = 1 * 2e5;
int A[MAXN], C[MAXN];



int64_t modpow(int64_t a, int64_t b) {
    int64_t res = 1;
    for(; b; b >>= 1) {
        if(b&1)
            res=res*a%M;
        a=a*a%M;
    }
    return res;
}
void solve() {
    const int MOD = M;
    int N, M;
    cin >> N >> M;
    vector<string> G(N);
    for(int i = 0; i < N; i++)
        cin >> G[i];

    int cnt = 0;
    for(int i = 0; i < N; i++)
        cnt += count(G[i].begin(), G[i].end(), '#');
    cerr << "Count: " << cnt << endl;
    int64_t x = modpow(2, cnt);
    if(cnt == N * M) {
        cout << (x - 1 + MOD) % MOD << endl;
    } else {
        cout << modpow(2, cnt) << endl;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;

    while(T--) {
        solve();
    }
}