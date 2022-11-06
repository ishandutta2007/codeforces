#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
LL a[100010];

LL calc(LL x, LL d) {
    LL dv = x / d, md = x % d;
    return (d - md) * dv * dv + md * (dv + 1) * (dv + 1);
}

struct cost {
    LL delta;
    LL v, d;
    friend bool operator < (cost c1, cost c2){
        return c1.delta < c2.delta;
    }
    cost(LL _v, LL _d) {
        v = _v;
        d = _d;
        delta = calc(v, d) - calc(v, d + 1);
    }
};
priority_queue<cost>heap;

int main() {
    scanf("%d%d",&N,&K);
    LL ans = 0;
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
        ans += 1LL * a[i] * a[i];
    }
    for (int i=1;i<=N;i++) {
        heap.push(cost(a[i], 1));
    }
    for (int fuck=1;fuck<=K-N;fuck++) {
        cost tmp = heap.top();
        ans -= tmp.delta;
        heap.pop();
        heap.push(cost(tmp.v, tmp.d + 1));
    }
    printf("%lld\n",ans);
}