#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,source,sink,flow,cur;
vector<pair<int,int> > odd;
vector<pair<int,int> > even;
int res[202][202];
int tree[202];
int dist[202];
vector<int> adj[202];
queue<int> frontier;
vector<int> to[200];
vector<vector<int> > toPrint;

bool isPrime(int x) {
    for (int i=2;i*i<=x;i++) if (x%i==0) return false;
    return true;
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
    scanf("%d",&n);
    if (n%2==1) {
        printf("Impossible\n");
        return 0;
    }
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if (a%2==0) even.push_back(make_pair(a,i));
        else odd.push_back(make_pair(a,i));
    }
    if (even.size()!=n/2 || odd.size()!=n/2) {
        printf("Impossible\n");
        return 0;
    }
    for (int i=0;i<n/2;i++) {
        adj[0].push_back(2+i);
        adj[2+i].push_back(0);
        res[0][2+i] = 2;
        adj[2+n/2+i].push_back(1);
        adj[1].push_back(2+n/2+i);
        res[2+n/2+i][1] = 2;
        for (int j=0;j<n/2;j++) {
            if (isPrime(even[i].first+odd[j].first)) {
                    adj[2+i].push_back(2+n/2+j);
                    adj[2+n/2+j].push_back(2+i);
                    res[2+i][2+n/2+j] = 1;
            }
        }
    }
    source = 0;
    sink = 1;
    flow = 0;
    while (true) {
        for (int i=0;i<n+2;i++) {
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
        flow+=cur;
    }
    if (flow!=n) {
        printf("Impossible\n");
        return 0;
    }
    for (int i=2;i<2+n/2;i++) {
        for (int j=2+n/2;j<2+n;j++) {
            if (res[j][i]) {
                to[even[i-2].second].push_back(odd[j-2-n/2].second);
                to[odd[j-2-n/2].second].push_back(even[i-2].second);
            }
        }
    }
    for (int i=0;i<n;i++) dist[i] = 0;
    for (int i=0;i<n;i++) {
        if (!dist[i]) {
            vector<int> table;
            table.push_back(i+1);
            int where = to[i][0];
            dist[i] = 1;
            while (true) {
                table.push_back(where+1);
                dist[where] = 1;
                if (!dist[to[where][0]]) where = to[where][0];
                else if (!dist[to[where][1]]) where = to[where][1];
                else break;
            }
            toPrint.push_back(table);
        }
    }
    printf("%d\n",toPrint.size());
    for (int i=0;i<toPrint.size();i++) {
        printf("%d",toPrint[i].size());
        for (int j=0;j<toPrint[i].size();j++) printf(" %d",toPrint[i][j]);
        printf("\n");
    }

    return 0;
}