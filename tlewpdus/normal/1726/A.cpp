#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[2010];

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        if (N == 1) {
            puts("0");
            continue;
        }
        int ans = -INF;
        for (int i = 1; i < N; i++) {
            ans = max(ans, A[i] - A[0]);
        }
        for (int i = 0; i + 1 < N; i++) {
            ans = max(ans, A[N - 1] - A[i]);
        }
        ans = max(ans, A[N - 1] - A[0]);
        for (int i = 0; i + 1 < N; i++) {
            ans = max(ans, A[i] - A[i + 1]);
        }
        printf("%d\n", ans);
    }

    return 0;
}