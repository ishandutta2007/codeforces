#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100];
int ans[100100];

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            ans[A[i]] = (i + 1 == N ? 1 : i + 2);
        }
        for (int i = 1; i <= N; i++) {
            printf("%d ", ans[i]);
        }
        puts("");
    }

    return 0;
}