#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n,m;
vector<pair<int,long long> > adj[100000];
long long shortest[100000];
int from[100000];
priority_queue<pair<long long,int> > frontier;
set<pair<int,int> > roadBroke;
set<pair<int,int> > roadWorks;

int main() {
    scanf("%d%d",&n,&m);
    int broken = 0;
    for (int i=0;i<m;i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x-=1; y-=1;
        if (z==0) {
            broken+=1;
            roadBroke.insert(make_pair(min(x,y),max(x,y)));
        } else roadWorks.insert(make_pair(min(x,y),max(x,y)));
        z = 1-z;
        adj[x].push_back(make_pair(y,z+1000000));
        adj[y].push_back(make_pair(x,z+1000000));
    }
    shortest[0] = 0;
    for (int i=0;i<n;i++) shortest[i] = 1000000000000000L;
    frontier.push(make_pair(0,0));
    while (frontier.size()>0) {
        int next = frontier.top().second;
        long long dist = -frontier.top().first;
        frontier.pop();
        if (dist>shortest[next]) continue;
        if (next==n-1) break;
        for (int i=0;i<adj[next].size();i++) {
            if (dist+adj[next][i].second<shortest[adj[next][i].first]) {
                frontier.push(make_pair(-dist-adj[next][i].second,adj[next][i].first));
                shortest[adj[next][i].first] = dist+adj[next][i].second;
                from[adj[next][i].first] = next;
            }
        }
    }
    int length = shortest[n-1]/1000000;
    int brokeOnPath = shortest[n-1]%1000000;
    printf("%d\n",brokeOnPath+m-broken-(length-brokeOnPath));
    int where = n-1;
    while (where!=0) {
        int next = from[where];
        if (roadBroke.count(make_pair(min(where,next),max(where,next)))) printf("%d %d %d\n",where+1,next+1,1);
        else roadWorks.erase(make_pair(min(where,next),max(where,next)));
        where = next;
    }
    for (set<pair<int,int> >::iterator it=roadWorks.begin();it!=roadWorks.end();it++) printf("%d %d %d\n",it->first+1,it->second+1,0);

    return 0;
}