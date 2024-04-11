#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

void pts(int x, int y, int z) {
    printf("3 %d %d %d\n", x, y, z);
}

void pts(int w, int x, int y, int z) {
    printf("4 %d %d %d %d\n", w, x, y, z);
}

void gao(int n) {
    if (n == 3) {
        pts(1, 2, 3);
        pts(1, 2, 3);
    }
    else if (n == 4) {
        pts(1, 2, 3, 4);
        pts(1, 2, 4, 3);
        pts(1, 4, 2, 3);
    }
    else if (n == 5) {
        pts(1, 3, 4, 2);
        pts(2, 4, 5, 3);
        pts(3, 5, 1, 4);
        pts(4, 1, 2, 5);
        pts(5, 2, 3, 1);
    }
    else {
        int m = n - 2;
        gao(m);
        pts(n - 1, n, m);
        pts(n - 1, n, m - 1);
        pts(n - 1, m - 1, n, m);
        m -= 2;
        for (int i = 0; i < m; i++) {
            pts(n - 1, i + 1, n, (i + 1) % m + 1);
        }
    }
}

void solve(int casi){
    int n;
    scanf("%d", &n);
    if (n == 3) printf("2\n");
    else {
        int p = (n - 4) / 2 * 2;
        int q;
        if (n % 2 == 0) q = 2 + (n / 2 - 1) * (n - 2) / 2;
        else q = 3 + n / 2 * (n - 3) / 2;
        assert(3 * p + 4 * q == n * (n - 1));
        printf("%d\n", p + q);
    }
    gao(n);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}