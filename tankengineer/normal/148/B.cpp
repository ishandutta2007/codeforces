#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int vp, vd, t, f, c;

int main() {
    scanf("%d%d%d%d%d", &vp, &vd, &t, &f, &c);
    if (vp >= vd) {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    double pos = vp * t;
    while (pos + 1e-9 < c) {
        double dt = pos / (vd - vp);
        pos += dt * vp;
        if (pos + 1e-9 > c) {
            break;
        }
        ++ans;
        pos += (pos / vd + f) * vp;
    }
    printf("%d\n", ans);
    return 0;
}