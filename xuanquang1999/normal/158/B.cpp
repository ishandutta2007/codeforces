using namespace std;
#include <cstdio>
int n, c[5], ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++c[x];
    }

    int ans = c[4];
    while (c[3] > 0 && c[1] > 0) {
        ++ans; --c[3]; --c[1];
    }
    while (c[2] > 1) {
        ++ans; c[2]-=2;
    }
    while (c[1] > 1 && c[2] > 0) {
        ++ans; c[1]-=2; --c[2];
    }
    while (c[1] > 3) {
        ++ans; c[1]-=4;
    }

    if (c[1] > 0 && c[2] > 0) {
        ++ans; --c[1]; --c[2];
    }
    if (c[1] > 0) ++ans;

    printf("%d", ans+c[2]+c[3]);
}