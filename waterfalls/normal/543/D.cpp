#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int p[200013];
int which[200013];
vector<int> adj[200013];
int one[200013];
vector<int> child[200013];
const int MOD = 1000000007;

int inverse(int x) {
    int p = MOD-2;
    int cur = x;
    int ans = 1;
    for (int i=0;i<=30;i++) {
        if (p&(1<<i)) ans = ((long long) ans*cur)%MOD;
        cur = ((long long) cur*cur)%MOD;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        scanf("%d",&p[i]), p[i]-=1, adj[p[i]].push_back(i);
        which[i] = adj[p[i]].size()-1;
    }
    for (int i=n-1;i>=0;i--) {
        one[i] = 1;
        for (int j=0;j<adj[i].size();j++) one[i] = ((long long) one[i]*(1+one[adj[i][j]]))%MOD;
    }
    for (int x=0;x<n;x++) {
        int zeros = 0;
        for (int i=0;i<adj[x].size();i++) if (one[adj[x][i]]==MOD-1) zeros+=1;
        if (x!=0 && child[p[x]][which[x]]==MOD-1) zeros+=1;
        if (zeros>1) for (int i=0;i<adj[x].size();i++) child[x].push_back(0);
        if (zeros==1) {
            int prod = 1;
            for (int i=0;i<adj[x].size();i++) if (one[adj[x][i]]!=MOD-1) prod = ((long long) prod*(1+one[adj[x][i]]))%MOD;
            if (x!=0 && child[p[x]][which[x]]!=MOD-1) prod = ((long long) prod*(1+child[p[x]][which[x]]))%MOD;
            for (int i=0;i<adj[x].size();i++) {
                if (one[adj[x][i]]==MOD-1) child[x].push_back(prod);
                else child[x].push_back(0);
            }
        }
        if (zeros==0) {
            int prod = 1;
            for (int i=0;i<adj[x].size();i++) prod = ((long long) prod*(1+one[adj[x][i]]))%MOD;
            if (x!=0) prod = ((long long) prod*(1+child[p[x]][which[x]]))%MOD;
            for (int i=0;i<adj[x].size();i++) child[x].push_back(((long long) prod*inverse(1+one[adj[x][i]]))%MOD);
        }
    }
    printf("%d",one[0]);
    for (int i=1;i<n;i++) printf(" %d",((long long) one[i]*(1+child[p[i]][which[i]]))%MOD);
    printf("\n");

    return 0;
}