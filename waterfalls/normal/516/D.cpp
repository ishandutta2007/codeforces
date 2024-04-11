#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Hole { int index; long long dist; };
bool comp(Hole a, Hole b) { return a.dist>b.dist; }

int n,q;
vector<pair<int,int> > adj[100013];
vector<long long> best[100013];
vector<Hole> holes;
long long d[100013];
int p[100013];
int h[100013];
int s[100013];
int visited[100013];

int findSet(int a) { return p[a]==a ? a : p[a] = findSet(p[a]); }
void mergeSets(int a, int b) {
    int r1 = findSet(a), r2 = findSet(b);
    if (r1!=r2) {
        if (h[r2]<h[r1]) swap(r1,r2);
        p[r1] = r2;
        s[r2]+=s[r1];
        if (h[r1]==h[r2]) h[r2]+=1;
    }
}
bool sameSet(int a, int b) { return findSet(a)==findSet(b); }

void dfsUp(int x) {
    visited[x] = 1;
    for (int i=0;i<adj[x].size();i++) {
        best[x].push_back(0);
        if (visited[adj[x][i].first]) continue;
        dfsUp(adj[x][i].first);
        best[x][i] = adj[x][i].second+d[adj[x][i].first];
        d[x] = max(d[x],best[x][i]);
    }
}

void dfsDown(int x) {
    visited[x] = 1;
    if (adj[x].size()==1) return;
    int first = 0, second = 1;
    if (best[x][first]<best[x][second]) swap(first,second);
    for (int i=2;i<best[x].size();i++) {
        if (best[x][i]>best[x][first]) second = first, first = i;
        else if (best[x][i]>best[x][second]) second = i;
    }
    for (int i=0;i<adj[x].size();i++) {
        int next = adj[x][i].first;
        if (visited[next]) continue;
        long long giving = best[x][first];
        if (i==first) giving = best[x][second];
        for (int j=0;j<adj[next].size();j++) if (adj[next][j].first==x) best[next][j] = adj[x][i].second+giving;
        d[next] = max(d[next],adj[x][i].second+giving);
        dfsDown(next);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        adj[x-1].push_back(make_pair(y-1,v));
        adj[y-1].push_back(make_pair(x-1,v));
    }
    if (n>2) {
        for (int i=0;i<n;i++) {
            if (adj[i].size()!=1) {
                dfsUp(i);
                for (int j=0;j<n;j++) visited[j] = 0;
                dfsDown(i);
                break;
            }
        }
    } else d[0] = d[1] = adj[0][0].second;
    for (int i=0;i<n;i++) {
        Hole next;
        next.index = i; next.dist = d[i];
        holes.push_back(next);
    }
    sort(holes.begin(),holes.end(),comp);
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        long long l;
        scanf("%I64d",&l);
        int ans = 0;
        for (int j=0;j<n;j++) p[j] = j, h[j] = 0, s[j] = 1, visited[j] = 0;
        int where = 0;
        for (int j=0;j<n;j++) {
            int which = holes[j].index;
            long long dist = holes[j].dist;
            for (int k=0;k<adj[which].size();k++) if (visited[adj[which][k].first]) mergeSets(which,adj[which][k].first);
            while (holes[where].dist-dist>l) s[findSet(holes[where].index)]-=1, where+=1;
            ans = max(ans,s[findSet(which)]);
            visited[which] = 1;
        }
        printf("%d\n",ans);
    }

    return 0;
}