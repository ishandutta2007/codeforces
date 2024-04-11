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

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        int n0 = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            n0 += 1 - A[i];
        }
        int ans = N;
        int n1 = 0;
        for (int i = 0; i < N; i++) {
            ans = min(ans, max(n0, n1));
            if (A[i] == 0)
                n0--;
            else
                n1++;
        }
        ans = min(ans, max(n0, n1));
        printf("%d\n", ans);
    }

    return 0;
}