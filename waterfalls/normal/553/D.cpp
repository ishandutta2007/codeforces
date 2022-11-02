#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,k;
vector<int> adj[100013];
bool fortress[100013];
int num[100013];
queue<int> frontier;
bool left[100013];

bool check(double K) {
    while (frontier.size()>0) frontier.pop();
    for (int i=1;i<=n;i++) {
        num[i] = adj[i].size();
        left[i] = 1;
        if (fortress[i]) {
            frontier.push(i);
            left[i] = 0;
        }
    }
    int gone = 0;
    while (frontier.size()>0) {
        int cur = frontier.front();
        frontier.pop();
        gone+=1;
        for (int j=0;j<adj[cur].size();j++) {
            int i = adj[cur][j];
            num[i]-=1;
            if (1.*num[i]/adj[i].size()+1e-12<K && left[i]) {
                left[i] = 0;
                frontier.push(i);
            }
        }
    }
    return gone<n;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;i++) {
        int x;
        scanf("%d",&x);
        fortress[x] = 1;
    }
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    double low = 0;
    double high = 1;
    for (int i=0;i<100;i++) {
        if (check((low+high)/2)) low = (low+high)/2;
        else high = (low+high)/2;
    }
    check(low);
    int cnt = 0;
    for (int i=1;i<=n;i++) if (left[i]) cnt+=1;
    printf("%d\n",cnt);
    for (int i=1;i<=n;i++) if (left[i]) printf("%d ",i);
    printf("\n");

    return 0;
}