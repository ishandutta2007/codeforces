#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL x[100],y[100];
LL ax,ay,bx,by;
LL sx,sy,t;

LL dis(LL x1,LL y1,LL x2,LL y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
    scanf("%lld%lld%lld",&sx,&sy,&t);
    int N;
    for (N=1;;N++) {
        x[N] = x[N-1] * ax + bx;
        y[N] = y[N-1] * ay + by;
        if (x[N] > 4 * 1e16 || y[N] > 4 * 1e16) {
            break;
        }
    }
    int ans = 0;
    for (int i=0;i<=N;i++) {
        int tmpans = 0;
        LL tmpt = t;
        tmpt -= dis(sx, sy, x[i], y[i]);
        if (tmpt < 0) continue;
        tmpans++;
        for (int j=i+1;j<=N;j++) {
            tmpt -= dis(x[j-1], y[j-1], x[j], y[j]);
            if (tmpt < 0) break;
            tmpans++;
        }
        ans = max(ans, tmpans);
    }

    for (int i=0;i<=N;i++) {
        int tmpans = 0;
        LL tmpt = t;
        tmpt -= dis(sx, sy, x[i], y[i]);
        if (tmpt < 0) continue;
        tmpans++;
        for (int j=i-1;j>=0;j--) {
            tmpt -= dis(x[j+1], y[j+1], x[j], y[j]);
            if (tmpt < 0) break;
            tmpans++;
        }
        ans = max(ans, tmpans);
    }
    printf("%d\n",ans);
}