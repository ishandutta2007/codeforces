#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,source,sink,cur;
int a[100];
int good[100][2];
int gcds[100][100];
int res[202][202];
vector<vector<int> > adj;
int dist[202];
int tree[202];
queue<int> frontier;
int primes[100000];

void sieve(int x) {
    for (int i=2;i<x;i++) primes[i] = 1;
    for (int i=2;i<x;i++) if (primes[i]) for (int j=i+i;j<x;j+=i) primes[j] = 0;
}

int gcd(int a, int b) {
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}

void augment(int x, int minEdge) {
    if (x==source) cur = minEdge;
    else if (tree[x]!=-1) {
        augment(tree[x],min(minEdge,res[tree[x]][x]));
        res[tree[x]][x]-=cur;
        res[x][tree[x]]+=cur;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<m;i++) scanf("%d%d",&good[i][0],&good[i][1]);
    for (int i=0;i<m;i++) { good[i][0]-=1; good[i][1]-=1; }
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) gcds[i][j] = gcd(a[i],a[j]);
    sieve(100000);
    int ans = 0;
    for (int p=2;p<100000;p++) {
        if (!primes[p]) continue;
        for (int j=0;j<2*n+2;j++) for (int k=0;k<2*n+2;k++) res[j][k] = 0;
        adj.clear();
        for (int i=0;i<2*n+2;i++) adj.push_back(vector<int>());
        for (int i=2;i<2+n;i++) adj[0].push_back(i);
        for (int i=2+n;i<2+2*n;i++) adj[i].push_back(1);
        for (int j=0;j<m;j++) {
            while (gcds[good[j][0]][good[j][1]]%p==0) {
                gcds[good[j][0]][good[j][1]]/=p;
                res[good[j][0]+2][good[j][1]+2+n]+=1;
                res[good[j][1]+2][good[j][0]+2+n]+=1;
                adj[good[j][0]+2].push_back(good[j][1]+2+n);
                adj[good[j][1]+2].push_back(good[j][0]+2+n);
                adj[good[j][0]+2+n].push_back(good[j][1]+2);
                adj[good[j][1]+2+n].push_back(good[j][0]+2);
            }
        }
        for (int i=0;i<n;i++) {
            while (a[i]%p==0) {
                a[i]/=p;
                res[0][i+2]+=1;
                res[i+2+n][1]+=1;
            }
        }
        source = 0;
        sink = 1;
        while (true) {
            for (int i=0;i<2*n+2;i++) {
                dist[i] = 1000000000;
                tree[i] = -1;
            }
            dist[source] = 0;
            while (!frontier.empty()) frontier.pop();
            frontier.push(source);
            while (!frontier.empty()) {
                int next = frontier.front();
                frontier.pop();
                if (next==sink) break;
                for (int j=0;j<adj[next].size();j++) {
                    int i = adj[next][j];
                    if (res[next][i]>0 && dist[i]==1000000000) {
                        dist[i] = dist[next]+1;
                        frontier.push(i);
                        tree[i] = next;
                    }
                }
            }
            cur = 0;
            augment(sink,1000000000);
            if (cur==0) break;
            ans+=cur;
        }
    }
    while (true) {
        int where = -1;
        for (int i=0;i<m;i++) if (a[good[i][0]]==a[good[i][1]] && a[good[i][0]]!=1) where = good[i][0];
        if (where==-1) break;
        int p = a[where];
        for (int j=0;j<2*n+2;j++) for (int k=0;k<2*n+2;k++) res[j][k] = 0;
        adj.clear();
        for (int i=0;i<2*n+2;i++) adj.push_back(vector<int>());
        for (int i=2;i<2+n;i++) adj[0].push_back(i);
        for (int i=2+n;i<2+2*n;i++) adj[i].push_back(1);
        for (int j=0;j<m;j++) {
            while (gcds[good[j][0]][good[j][1]]%p==0) {
                gcds[good[j][0]][good[j][1]]/=p;
                res[good[j][0]+2][good[j][1]+2+n]+=1;
                res[good[j][1]+2][good[j][0]+2+n]+=1;
                adj[good[j][0]+2].push_back(good[j][1]+2+n);
                adj[good[j][1]+2].push_back(good[j][0]+2+n);
                adj[good[j][0]+2+n].push_back(good[j][1]+2);
                adj[good[j][1]+2+n].push_back(good[j][0]+2);
            }
        }
        for (int i=0;i<n;i++) {
            while (a[i]%p==0) {
                a[i]/=p;
                res[0][i+2]+=1;
                res[i+2+n][1]+=1;
            }
        }
        source = 0;
        sink = 1;
        while (true) {
            for (int i=0;i<2*n+2;i++) {
                dist[i] = 1000000000;
                tree[i] = -1;
            }
            dist[source] = 0;
            while (!frontier.empty()) frontier.pop();
            frontier.push(source);
            while (!frontier.empty()) {
                int next = frontier.front();
                frontier.pop();
                if (next==sink) break;
                for (int j=0;j<adj[next].size();j++) {
                    int i = adj[next][j];
                    if (res[next][i]>0 && dist[i]==1000000000) {
                        dist[i] = dist[next]+1;
                        frontier.push(i);
                        tree[i] = next;
                    }
                }
            }
            cur = 0;
            augment(sink,1000000000);
            if (cur==0) break;
            ans+=cur;
        }
    }
    printf("%d\n",ans/2);

    return 0;
}