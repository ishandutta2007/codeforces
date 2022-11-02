#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 26, L = 100005;

int n;

int cnt[N];

int ans;

char s[L];

int main() {
    scanf("%d", &n);
    int odds = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", cnt + i);
        odds += cnt[i] & 1;
    }
    if (n == 1) {
        ans = cnt[0];
        for (int i = 0; i < cnt[0]; ++i) {
            s[i] = 'a';
        }
    } else if (n > 1) {
        if (odds >= 2) {
            ans = 0;
            int top = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < cnt[i]; ++j) {
                    s[top++] = 'a' + i;
                }
            }
        } else if (odds == 1) {
            int mid = -1, l = 0;
            for (int i = 0; i < n; ++i) {
                l += cnt[i];
                if (cnt[i] & 1) {
                    mid = i;
                }
            }
            int g = 0;
            for (int i = 0; i < n; ++i) {
                if (~cnt[i] & 1) {
                    g = g ? cnt[i] : __gcd(g, cnt[i]);
                }
            }
            g /= 2;
            g = __gcd(g, cnt[mid]);
            ans = g;
            int top = 0;
            for (int i = 0; i < g; ++i) {
                for (int j = 0; j < cnt[mid] / g; ++j) {
                    s[top++] = 'a' + mid;
                }
                for (int j = 0; j < n; ++j) {
                    if (j != mid) {
                        for (int k = 0; k < cnt[j] / g / 2; ++k) {
                            s[top++] = 'a' + j;
                        }
                    }
                }
                for (int j = n - 1; j >= 0; --j) {
                    if (j != mid) {
                        for (int k = 0; k < cnt[j] / g / 2; ++k) {
                            s[top++] = 'a' + j;
                        }
                    }
                }
            }
        } else if (odds == 0) {
            int g = cnt[0];
            for (int i = 0; i < n; ++i) {
                g = __gcd(g, cnt[i]);
            }
            ans = g;
            int top = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < cnt[i] / g; ++j) {
                    s[top++] = 'a' + i;
                }
            }
            int p = top;
            for (int i = 0; i + 1 < g; ++i) {
                int cur = top;
                for (int j = 0; j < p; ++j) {
                    s[top++] = s[cur - 1 - j];
                }
            }
        }
    }
    printf("%d\n", ans);
    puts(s);
    return 0;
}