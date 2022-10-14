#include <bits/stdc++.h>
using namespace std;

const int N = 200050;
int n, m, p;
long long a[N];
char s[65];
char ans[65];
int cnt[1 << 20];

int main() 
{
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 0; i < n; i++) {
                scanf("%s", s);
                for (int j = 0; j < m; j++)
                        if (s[j] == '1') a[i] += (1ll << j);
        }
        mt19937 rng(time(0));
        int mx = 0;
        for (int i = 0; i < m; i++) ans[i] = '0';
        for (int rr = 0; rr < 100; rr++) {
                int i = rng() % n;
                vector<int> bits;
                for (int j = 0; j < m; j++) {
                        if (a[i] >> j & 1) {
                                bits.push_back(j);
                        }
                }
                for (int j = 0; j < (1 << p); j++) cnt[j] = 0;
                for (int j = 0; j < n; j++) {
                        int mask = 0;
                        for (int b = 0; b < bits.size(); b++) {
                                if (a[j] >> bits[b] & 1) mask += (1 << b);
                        }
                        cnt[mask]++;
                }
                for (int b = 0; b < p; b++) {
                        for (int i = 0; i < (1 << p); i++) {
                                if (i >> b & 1) cnt[i ^ (1 << b)] += cnt[i];
                        }
                }
                int sz = bits.size();
                for (int j = 1; j < (1 << sz); j++) {
                        if (cnt[j] * 2 >= n && mx < __builtin_popcount(j)) {
                                mx = __builtin_popcount(j);
                                for (int k = 0; k < m; k++) ans[k] = '0';
                                for (int k = 0; k < sz; k++) {
                                        if (j >> k & 1) ans[bits[k]] = '1';
                                }
                        }
                }
        }
        printf("%s", ans);
        return 0;
}