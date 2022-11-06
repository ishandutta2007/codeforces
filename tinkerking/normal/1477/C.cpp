#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N, x[5010], y[5010];
bool vis[5010];

LL sqr(LL x) {
    return x * x;
}
LL dis(int u, int v) {
    return sqr(x[u] - x[v]) + sqr(y[u] - y[v]);
}
int find_far(int u) {
    LL mx = -1, ret = -1;
    for (int i=1;i<=N;i++) {
        if (!vis[i] && dis(u, i) > mx) {
            mx = dis(u, i);
            ret = i;
        }
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    vector<int>ans;
    ans.push_back(1);
    vis[1] = true;
    for (int i=1;i<=N-1;i++) {
        int u = ans.back();
        int v = find_far(u);
        vis[v] = true;
        ans.push_back(v);
    }
    for (int i=0;i<N;i++) {
        printf("%d%c",ans[i]," \n"[i==N-1]);
    }
}