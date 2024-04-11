#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
pii P[200100];
ll fac[200100];
pii ran[200100];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i].first);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i].second);
    }
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    sort(P, P + N);
    int p = -1, mini = 1, maxi = INF;
    for (int i = 0; i < N; i++) {
        if (i == N - 1 || P[i].first != P[i + 1].first) {
            for (int j = p + 1; j <= i; j++) {
                if (P[j].second == 0) {
                    mini = max(mini, P[j].first);
                    maxi = min(maxi, P[j].first + p + 1);
                    ran[j] = {0, p + 1};
                } else {
                    mini = max(mini, P[j].first + N - i - 1);
                    maxi = min(maxi, P[j].first + N - 1);
                    ran[j] = {N - i - 1, N - 1};
                }
            }
            p = i;
        }
    }
    if (mini > maxi) {
        puts("0");
        return 0;
    }
    ll ans = 0;

    ll t = 1;
    p = -1;
    for (int i = 0; i < N; i++) {
        if (i == N - 1 || P[i].first != P[i + 1].first) {
            int cnt0 = 0, cnt1 = 0;
            for (int j = p + 1; j <= i; j++) {
                if (P[j].second == 0) {
                    cnt0++;
                } else {
                    cnt1++;
                }
            }
            if (cnt1 > 1) {
                t = 0;
                break;
            }
            t = t * fac[cnt0] % MOD;
            p = i;
        }
    }
    ans += t * (maxi - max(mini, P[N - 1].first + 1) + 1) % MOD;
    if (mini == P[N - 1].first) {
        p = -1;
        t = 1;
        for (int i = 0; i < N; i++) {
            if (i == N - 1 || P[i].first != P[i + 1].first) {
                if (P[i].first != P[N - 1].first) {
                    int cnt0 = 0, cnt1 = 0;
                    for (int j = p + 1; j <= i; j++) {
                        if (P[j].second == 0) {
                            cnt0++;
                        } else {
                            cnt1++;
                        }
                    }
                    if (cnt1 > 1) {
                        t = 0;
                        break;
                    }
                    t = t * fac[cnt0] % MOD;
                } else {
                    int cnt0 = 0, cnt1 = 0;
                    for (int j = p + 1; j <= i; j++) {
                        if (P[j].second == 0) {
                            cnt0++;
                        } else {
                            cnt1++;
                        }
                    }
                    t = t * fac[cnt0] % MOD;
                    for (int j = 0; j < cnt1; j++) {
                        t = t * (N - j) % MOD;
                    }
                }
                p = i;
            }
        }
        ans += t;
    }
    printf("%lld\n", ans % MOD);

    return 0;
}

/*
1 2 19 19 19 19 19 19 19 19 19 21 21 21 21 21 21 21 21 21 21
1 1  0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  1

*/