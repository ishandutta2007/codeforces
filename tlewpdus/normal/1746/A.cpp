#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        int K;
        scanf("%d%d", &N, &K);
        bool good = false;
        for (int i = 0; i < N; i++) {
            int a;
            scanf("%d", &a);
            if (a == 1) good = true;
        }
        puts(good ? "YES" : "NO");
    }

    return 0;
}