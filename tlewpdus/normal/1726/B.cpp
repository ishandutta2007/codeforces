#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d%d", &N, &M);
        if (N > M) {
            puts("No");
            continue;
        }
        if (N % 2 == 0 && M % 2 == 1) {
            puts("No");
            continue;
        }
        puts("Yes");
        if (N % 2 == 0) {
            for (int i = 0; i < N - 2; i++) {
                printf("1 ");
            }
            printf("%d %d\n", (M - N) / 2 + 1, (M - N) / 2 + 1);
        } else {
            for (int i = 0; i < N - 1; i++) {
                printf("1 ");
            }
            printf("%d\n", M - N + 1);
        }
    }

    return 0;
}