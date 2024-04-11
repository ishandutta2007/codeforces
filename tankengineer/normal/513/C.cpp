#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 15;

int n;

int l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", l + i, r + i);
    }
    double ans = 0;
    for (int v = 1; v <= 10000; ++v) {
        for (int win = 0; win < n; ++win) {
            if (v > r[win]) {
                continue;
            }
            for (int sec = 0; sec < n; ++sec) {
                if (win == sec) {
                    continue;
                }
                if (v > r[sec] || v < l[sec]) {
                    continue;
                }
                //winner bigger!
                double p = 1;
                p = p * (v < l[win] ? 1.0 : (double)(r[win] - v) / (r[win] - l[win] + 1));
                p = p * (double)1 / (r[sec] - l[sec] + 1);
                for (int i = 0; i < n; ++i) {
                    if (i == win || i == sec) {
                        continue;
                    }
                    if (v < l[i]) {
                        p *= 0;
                    } else if (v > r[i]) {
                        p *= 1;
                    } else {
                        if (i < sec) {
                            p *= (double)(v - l[i]) / (r[i] - l[i] + 1);
                        } else {
                            p *= (double)(v - l[i] + 1) / (r[i] - l[i] + 1);
                        }
                    }
                }
                ans += p * v;
                //winner same!
                for (int st = 0; st < 1 << n; ++st) {
                    if (~st >> win & 1) {
                        continue;
                    }
                    if (~st >> sec & 1) {
                        continue;
                    }
                    int cnt = 0;
                    double p = 1;
                    for (int j = 0; j < n; ++j) {
                        if (st >> j & 1) {
                            if (j < sec && j != win) {
                                p = 0;
                            }
                            ++cnt;
                            if (v >= l[j] && v <= r[j]) {
                                p = p * (double)1 / (r[j] - l[j] + 1);
                            } else {
                                p = 0;
                            }
                        }  else {
                            if (v < l[j]) {
                                p = 0;
                            } else if (v > r[j]) {
                                p *= 1;
                            } else {
                                p = p * (double)(v - l[j]) / (r[j] - l[j] + 1);
                            }
                        }
                    }
                    ans = ans + p * v / cnt;
                }
            }
        }
    }
    printf("%.12f\n", ans);
    return 0;
}