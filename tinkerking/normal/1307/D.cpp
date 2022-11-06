#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,M,K;
bool spe[200010];
int a[200010], b[200010];
vector<int>e[200010];
int d1[200010],d2[200010];
int mx[200010];

const int INF = 1e9;
queue<int>q;
void bfs(int ST,int *d) {
    for (int i=1;i<=N;i++) {
        d[i] = INF;
    }
    d[ST] = 0;
    q.push(ST);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto t:e[now]) {
            if (d[t] == INF) {
                d[t] = d[now] + 1;
                q.push(t);
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=K;i++) {
        scanf("%d",&a[i]);
        spe[a[i]] = true;
    }
    for (int i=1;i<=M;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(1, d1);
    bfs(N, d2);
    vector<pii> dd;
    for (int i=1;i<=K;i++) {
        dd.push_back(pii(d1[a[i]], d2[a[i]]));
    }
    sort(dd.begin(), dd.end());
    for (int i=K-1;i>=0;i--) {
        mx[i] = max(dd[i].second, mx[i + 1]);
    }
    int L = 0, R = N + 1;
    while(L < R - 1) {
        int mid = (L + R) / 2;
        bool find = false;
        for (int i=0;i<K-1;i++) {
            int idx = lower_bound(dd.begin(), dd.end(), pii(mid - dd[i].second, 0)) - dd.begin();
            idx = max(idx, i + 1);
            if (dd[i].first + mx[idx] >= mid) {
                find = true;
                break;
            }
        }
        if (find) {
            L = mid;
        } else {
            R = mid;
        }
    }
    printf("%d\n", min(d1[N], L + 1));
}