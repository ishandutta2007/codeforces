#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int m,k;
map<int,vector<int> > adj;
vector<int> ids;
vector<int> cur;

int main() {
    scanf("%d%d",&m,&k);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (!adj.count(a)) ids.push_back(a);
        if (!adj.count(b)) ids.push_back(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(ids.begin(),ids.end());
    for (int i=0;i<ids.size();i++) {
        printf("%d: ",ids[i]);
        cur.clear();
        for (int j=0;j<ids.size();j++) {
            if (j==i) continue;
            int ok = 1;
            for (int k=0;k<adj[ids[i]].size();k++) if (adj[ids[i]][k]==ids[j]) ok = 0;
            if (!ok) continue;
            int cnt = 0;
            for (int k=0;k<adj[ids[i]].size();k++) {
                for (int l=0;l<adj[adj[ids[i]][k]].size();l++) if (adj[adj[ids[i]][k]][l]==ids[j]) cnt+=1;
            }
            if (100*cnt>=k*adj[ids[i]].size()) cur.push_back(ids[j]);
        }
        printf("%d",cur.size());
        for (int j=0;j<cur.size();j++) printf(" %d",cur[j]);
        printf("\n");
    }

    return 0;
}