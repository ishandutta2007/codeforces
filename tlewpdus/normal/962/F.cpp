#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, m;
pii edg[100100];
vector<int> lis[100100];
bool visit[100100];
bool tre[100100];
int dep[100100];
int val[100100];
int par[100100];
int pi[100100];
int sps[100100][20];
int pps[100100][20];

int dfs(int here, int p) {
    dep[here] = ((~p)?dep[p]+1:0);
    visit[here] = 1; par[here] = p;
    for (int &vi : lis[here]) {
        int there = edg[vi].first+edg[vi].second-here;
        if (!visit[there]) {
            tre[vi] = 1; pi[there] = vi;
            val[here] += dfs(there,here);
        }
        else {
            if (there==p);
            else if (dep[there]>dep[here]) {
                val[here]--;
            }
            else val[here]++;
        }
    }
    sps[here][0] = val[here];
    pps[here][0] = p;
    return val[here];
}

vector<int> vec;
int main() {
    int i;
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b);a--;b--;
        lis[a].push_back(i);
        lis[b].push_back(i);
        edg[i] = pii(a,b);
    }
    for (i=0;i<n;i++) {
        if (!visit[i]) dfs(i,-1);
    }
    int j;
    for (j=1;j<20;j++) {
        for (i=0;i<n;i++) {
            pps[i][j] = ((~pps[i][j-1])?pps[pps[i][j-1]][j-1]:-1);
        }
        for (i=0;i<n;i++) {
            sps[i][j] = max(sps[i][j-1],((~pps[i][j-1])?sps[pps[i][j-1]][j-1]:0));
        }
    }
    for (i=0;i<m;i++) {
        if (tre[i]) continue;
        int a = edg[i].first, b = edg[i].second;
        if (dep[a]>dep[b]) swap(a,b);
        int t = dep[b]-dep[a], maxi = 0, cur = b;
        for (j=0;j<20;j++) {
            if ((t>>j)&1) {
                maxi = max(maxi,sps[cur][j]);
                cur = pps[cur][j];
            }
        }
        if (maxi==1) {
            cur = b;
            while(cur!=a) {
                vec.push_back(pi[cur]);
                cur = par[cur];
            }
            vec.push_back(i);
        }
    }
    sort(vec.begin(),vec.end());
    printf("%d\n",vec.size());
    for (int &v: vec) {
        printf("%d ",v+1);
    }

    return 0;
}