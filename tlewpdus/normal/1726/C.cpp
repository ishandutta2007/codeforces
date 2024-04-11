#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
char S[200100];

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        scanf(" %s", S);
        int ans = N;
        for (int i = 0; i + 1 < 2 * N; i++) {
            if (S[i] == ')' && S[i + 1] == '(') ans--;
        }
        printf("%d\n", ans);
    }

    return 0;
}