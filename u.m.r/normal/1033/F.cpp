#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 4096 + 10;
const int MM = 1e9 + 7;

int W, n, m;
int a[MAXN];

ll f[16777216];

char s[MAXN];

ll query(int ptr, int idx) {
    if (ptr == W) {
        return f[idx];
    }
    else {
        switch (s[W - 1 - ptr]) {
            case 'A' : return query(ptr + 1, idx + (1 << (2 * ptr)));
            case 'O' : return query(ptr + 1, idx);
            case 'X' : return query(ptr + 1, idx + (3 << (2 * ptr))) - query(ptr + 1, idx + (1 << (2 * ptr)));
            case 'a' : return query(ptr + 1, idx + (2 << (2 * ptr))) - query(ptr + 1, idx + (1 << (2 * ptr)));
            case 'o' : return query(ptr + 1, idx + (2 << (2 * ptr))) - query(ptr + 1, idx);
            case 'x' : return query(ptr + 1, idx + (1 << (2 * ptr))) - query(ptr + 1, idx);
        }
    }
}

void solve(int casi){
    scanf("%d%d%d", &W, &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int www = 1 << W;
    for (int i = 0; i < www; i++) {
        for (int j = 0; j < www; j++) {
            int u = 0;
            for (int k = 0; k < W; k++) {
                int p = (i >> k) & 1;
                int q = (j >> k) & 1;
                if (p && q) u |= (2 << (2 * k));
                else if (p || q) u |= (1 << (2 * k));
            }
            f[u] += a[i] * a[j];
        }
    }
    // for (int i = 0; i < 16; i++) cout << f[i] << ' '; cout << endl;
    int WWW = www * www;
    for (int i = 0; i < WWW; i++) {
        int j = (i & (i >> 1)) & (0x555555);
        j |= (j << 1);
        if (j) {
            f[i] = f[i ^ j];
        }
    }
    // for (int i = 0; i < 16; i++) cout << f[i] << ' '; cout << endl;
    for (int i = 0; i < W; i++) {
        int p = 1 << (2 * i);
        int q = 1 << (2 * (W - 1 - i));
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < q; k++) {
                int msk = (k << (2 * i + 2)) | j;
                f[msk + p] += f[msk];
                f[msk + 2 * p] += f[msk + p];
                f[msk + 3 * p] += f[msk + 2 * p];
            }
        }
    }
    // for (int i = 0; i < 16; i++) cout << f[i] << ' '; cout << endl;
    while (m--) {
        scanf("%s", s);
        ll ans = query(0, 0);
        printf("%lld\n", ans);
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}