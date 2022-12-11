#include <cstdio>

using namespace std;

const int MAX_A = 1e5 + 3;
const long long INF = 1e18;
bool is_prime[MAX_A + 1];
int nextt[MAX_A + 1];

void init() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= MAX_A; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= MAX_A; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= MAX_A; j += i) {
                is_prime[j] = 0;
            }
            nextt[i] = i;
            for (int j = i - 1; (j >= 0 && !is_prime[j]); j--) {
                nextt[j] = i;
            }
        }
    }
}

int main() {
    init();
    int n, m;
    scanf("%d %d\n", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    long long minimum = INF, cnt;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += nextt[a[i][j]] - a[i][j];
        }
        if (cnt < minimum) minimum = cnt;
    }
    for (int j = 0; j < m; j++) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            //cout << nextt[a[i][j]] << ' ' << a[i][j] << endl;
            cnt += nextt[a[i][j]] - a[i][j];
        }
        if (cnt < minimum) minimum = cnt;
    }
    printf("%d\n", minimum);
    return 0;
}