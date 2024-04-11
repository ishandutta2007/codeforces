#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n,m;
multiset<int> adj[100013];
vector<int> odds;
vector<int> tour;

void dfs(int x) {
    while (adj[x].size()>0) {
        int where = *adj[x].begin();
        adj[x].erase(adj[x].begin());
        adj[where].erase(adj[where].find(x));
        dfs(where);
    }
    tour.push_back(x+1);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i=0;i<n;i++) if (adj[i].size()%2==1) odds.push_back(i);
    if (odds.size()%2==1) {
        adj[odds[0]].insert(odds[0]);
        adj[odds[0]].insert(odds[0]);
        odds.erase(odds.begin());
        m+=1;
    }
    for (int i=0;i<odds.size()/2;i++) {
        adj[odds[2*i]].insert(odds[2*i+1]);
        adj[odds[2*i+1]].insert(odds[2*i]);
        m+=1;
    }
    if (m%2==1) {
        adj[0].insert(0);
        adj[0].insert(0);
        m+=1;
    }
    dfs(0);
    printf("%d\n",m);
    for (int i=0;i<m;i++) {
        if (i%2==0) printf("%d %d\n",tour[i],tour[i+1]);
        else        printf("%d %d\n",tour[i+1],tour[i]);
    }

    return 0;
}