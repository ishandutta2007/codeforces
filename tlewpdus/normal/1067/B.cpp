#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k;
int vis[100100];
int deg[100100];
int cnt[100100];
int dis[100100];
vector<int> lis[100100];

int main() {
    int i;
    scanf("%d%d",&n,&k);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    for (i=0;i<n;i++){
        if (deg[i]==1) {
            q.push(i);
            vis[i] = 1;
            dis[i] = 0;
        }
    }
    bool fl = 1;
    while(!q.empty()) {
        int here = q.front();
        if ((dis[here]&&dis[here]!=k&&cnt[here]<3)||(dis[here]==k&&cnt[here]<2)) {
            fl = 0;
        }
        q.pop();
        for (int &there :lis[here]) {
            if (vis[there]) continue;
            if (~dis[there]&&dis[there]!=dis[here]+1){
                fl = 0;
            }
            dis[there] = dis[here]+1;
            deg[there]--;
            if (deg[there]==1) {
                q.push(there);
                vis[there] = 1;
            }
            cnt[there]++;
        }
    }
    int c = 0, d = 0;
    for (i=0;i<n;i++) {
        if (dis[i]==k) c++;
        if (dis[i]>k) d++;
    }
    if (c!=1||d>0) fl = 0;
    puts(fl?"Yes":"No");

    return 0;
}