#include <bits/stdc++.h>

inline int score_id(int a, int b) {
    return a * 4 + b;
}

int dp[233][233][15], prea[233][233][15], preb[233][233][15], pres[233][233][15];

void init() {
    dp[0][0][0] = 1;
    for (int a = 0; a <= 200; ++a) {
        for (int b = 0; b <= 200; ++b) {
            for (int s = 0; s < 15; ++s) {
                if (!dp[a][b][s]) continue;
                int wa = s / 4, wb = s % 4;
                if (wa == 3 || wb == 3) continue;
                int cur = wa + wb;
                int lmt = cur < 4 ? 24 : 14;
                for (int y = 0; y < lmt; ++y) {
                    int da = lmt + 1, db = y, ss = score_id(wa + 1, wb);
                    if (a + da <= 200 && b + db <= 200 && !dp[a + da][b + db][ss]) {
                        dp[a + da][b + db][ss] = 1;
                        prea[a + da][b + db][ss] = a;
                        preb[a + da][b + db][ss] = b;
                        pres[a + da][b + db][ss] = s;
                    }
                    std::swap(da, db), ss = score_id(wa, wb + 1);
                    if (a + da <= 200 && b + db <= 200 && !dp[a + da][b + db][ss]) {
                        dp[a + da][b + db][ss] = 1;
                        prea[a + da][b + db][ss] = a;
                        preb[a + da][b + db][ss] = b;
                        pres[a + da][b + db][ss] = s;
                    }
                }
                for (int y = lmt; y <= 200; ++y) {
                    int da = y + 2, db = y, ss = score_id(wa + 1, wb);
                    if (a + da <= 200 && b + db <= 200 && !dp[a + da][b + db][ss]) {
                        dp[a + da][b + db][ss] = 1;
                        prea[a + da][b + db][ss] = a;
                        preb[a + da][b + db][ss] = b;
                        pres[a + da][b + db][ss] = s;
                    }
                    std::swap(da, db), ss = score_id(wa, wb + 1);
                    if (a + da <= 200 && b + db <= 200 && !dp[a + da][b + db][ss]) {
                        dp[a + da][b + db][ss] = 1;
                        prea[a + da][b + db][ss] = a;
                        preb[a + da][b + db][ss] = b;
                        pres[a + da][b + db][ss] = s;
                    }
                }
            }
        }
    }
}

void display(int a, int b, int s) {
    if (!a && !b && !s) return;
    display(prea[a][b][s], preb[a][b][s], pres[a][b][s]);
    printf("%d:%d ", a - prea[a][b][s], b - preb[a][b][s]);
}

inline void query(int a, int b) {
    int ansa = -1, ansb = -1;
    for (int s = 0; s < 15; ++s) {
        if (!dp[a][b][s]) continue;
        int wa = s / 4, wb = s % 4;
        if (wa < 3 && wb < 3) continue;
        if (ansa == -1 || ansa - ansb < wa - wb) {
            ansa = wa, ansb = wb;
        }
    }
    if (ansa == -1) {
        puts("Impossible");
        return;
    }
    printf("%d:%d\n", ansa, ansb);
    display(a, b, score_id(ansa, ansb));
    puts("");
}

int main() {
    init();
    int m;
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        query(a, b);
    }
    return 0;
}