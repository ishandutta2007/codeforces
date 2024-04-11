#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, K;
ll S[200100];
vector<int> lis[200100];
ll D[2][200100];
void dfs(int here, int k) {
    if (lis[here].empty()) {
        D[0][here] = k * S[here];
        D[1][here] = (k + 1) * S[here];
        return;
    }
    int c = lis[here].size();
    vector<ll> diff;
    D[0][here] = k * S[here];
    for (int &there : lis[here]) {
        dfs(there, k / c);
        diff.push_back(D[1][there] - D[0][there]);
        D[0][here] += D[0][there];
    }
    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());
    for (int i = 0; i < k % c; i++) {
        D[0][here] += diff[i];
    }
    D[1][here] = D[0][here] + diff[k % c] + S[here];
}

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N - 1; i++) {
            int p;
            scanf("%d", &p);
            p--;
            lis[p].push_back(i + 1);
        }
        for (int i = 0; i < N; i++) scanf("%lld", &S[i]);
        dfs(0, K);
        printf("%lld\n", D[0][0]);
        for (int i = 0; i < N; i++) lis[i].clear();
    }

    return 0;
}