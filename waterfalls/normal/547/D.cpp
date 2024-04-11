#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define PII pair<int,int>
#define MP make_pair
#define A first
#define B second

int n;
set<PII> adj[400013];
int color[200013];
const int HIGH = 200000;

void dfs(int x, int i) {
    while (adj[x].size()>0) {
        PII go = *adj[x].begin();
        adj[x].erase(go);
        adj[go.A].erase(MP(x,go.B));
        dfs(go.A,go.B);
    }
    if (x>=HIGH) color[i] = 1;
    else color[i] = 0;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x-=1; y-=1;
        adj[x].insert(MP(y+HIGH,i));
        adj[y+HIGH].insert(MP(x,i));
    } 
    int prev = -1;
    for (int i=0;i<2*HIGH;i++) {
        if (adj[i].size()%2==1) {
            if (prev==-1) prev = i;
            else {
                adj[i].insert(MP(prev,n));
                adj[prev].insert(MP(i,n));
                prev = -1;
            }
        }
    }
    for (int i=0;i<HIGH;i++) dfs(i,n);
    for (int i=0;i<n;i++) printf("%c",color[i] ? 'r' : 'b');
    printf("\n");

    return 0;
}