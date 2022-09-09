#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
ll A[110];
ll F[110];

int main() {
    int ttt;

    F[0] = F[1] = 1;
    for (M = 2; M <= 100; M++) {
        F[M] = F[M - 1] + F[M - 2];
        if (F[M] >= INF) break;
    }
    M++;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
            sum += A[i];
        }
        ll fsum = 0;
        int id = -1;
        for (int j = 0; j < M; j++) {
            fsum += F[j];
            if (fsum == sum) {
                id = j + 1;
                break;
            }
        }
        if (id == -1) {
            puts("NO");
            continue;
        }
        if (id == 1) {
            puts("YES");
            continue;
        }
        // printf("%d!\n", id);
        vector<ll> mask(N, 0);
        vector<ll> mask2(N, 0);
        for (int i = 0; i < N; i++) {
            ll x = A[i], m = 0;
            for (int j = id - 1; j >= 1; j--) {
                if (x >= F[j]) {
                    x -= F[j];
                    m ^= (1LL << j);
                    j--;
                }
            }
            mask[i] = m;
            x = A[i] - 1, m = 0;
            for (int j = id - 1; j >= 1; j--) {
                if (x >= F[j]) {
                    x -= F[j];
                    m ^= (1LL << j);
                    j--;
                }
            }
            mask2[i] = m;
        }
        bool good = false;
        for (int j = 0; j < N; j++) {
            ll m = 1;
            for (int i = 0; i < N; i++) {
                if (i == j)
                    m ^= mask2[i];
                else
                    m ^= mask[i];
            }
            if (m == (1LL << id) - 1 && (mask2[j] >> 1 & 1) == 0) {
                good = true;
            }
        }
        puts(good ? "YES" : "NO");
    }

    return 0;
}