#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <ctime>
#include <map>
#define ld double
#define ll long long
#define mp make_pair

using namespace std;

const int maxn = 1010;
ld eps = 1e-9;

ld ed[maxn][maxn];
ld ans[maxn];
ld ver[maxn];
ld sums[maxn];
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ld x;

			scanf("%lf", &x);

            ed[i][j] = x / 100;
        }
    }

    queue <int> q;

    ans[n - 1] = 0.0;

    for (int i = 0; i < n - 1; i++) {
        ans[i] = 1e9;
        ver[i] = 1.0;
    }

    set <pair <ld, int> > s;

    for (int i = 0; i < n; i++) {
        s.insert(make_pair(ans[i], i));
    }

    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());

        for (int i = 0; i < n; i++) {
            if (v == i) {
                continue;
            }
            if (ed[i][v] != 0) {
                ld d = ed[i][v];

                if (ans[i] == 1e9) {
                    s.erase(make_pair(ans[i], i));
                    ans[i] = ans[v] + 1.0 / d;
                    ver[i] = 1 - d;
                    s.insert(make_pair(ans[i], i));
                } else {
                    ld nsum = ans[i] - ver[i] * ans[i] + ver[i] * d * ans[v];
                    ld nans = nsum / (1 - ver[i] * (1 - d));
                    
                    if (nans + eps < ans[i]) {
                        s.erase(make_pair(ans[i], i));
                        ans[i] = nans;
                        ver[i] *= 1 - d;
                        s.insert(make_pair(ans[i], i));
                    }
                }
            }
        }
    }

    printf("%.10lf", ans[0]);

    return 0;
}