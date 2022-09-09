#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100], D[100100];
map<int, int> last;

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        last.clear();
        last[0] = 0;
        D[0] = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            A[i] ^= A[i - 1];
            D[i] = D[i - 1];
            if (last.find(A[i]) != last.end()) {
                D[i] = max(D[i], D[last[A[i]]] + 1);
            }
            last[A[i]] = i;
        }
        printf("%d\n", N - D[N]);
    }

    return 0;
}