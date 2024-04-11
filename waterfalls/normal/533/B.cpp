#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long ans;
int p[200013];
long long a[200013];
vector<int> adj[200013];

pair<long long,long long> dfs(int x) {
    ans = max(ans,a[x]);
    if (adj[x].size()==0) return make_pair(0,a[x]);
    int parity = 0;
    long long sum = a[x];
    long long sma = 1000000000000000000LL;
    for (int i=0;i<adj[x].size();i++) {
        pair<long long,long long> next = dfs(adj[x][i]);
        if (next.first>next.second) sum+=next.first;
        else {
            parity^=1;
            sum+=next.second;
        }
        sma = min(sma,abs(next.first-next.second));
    }
    long long sum2 = sum-sma;
    if (parity) {
        ans = max(ans,max(sum-a[x],sum2));
        return make_pair(sum2-a[x],max(sum-a[x],sum2));
    } else {
        ans = max(ans,sum);
        return make_pair(sum-a[x],sum);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%I64d",&p[i],&a[i]);
    for (int i=1;i<n;i++) {
        p[i]-=1;
        adj[p[i]].push_back(i);
    }
    ans = 0;
    dfs(0);
    printf("%I64d\n",ans);

    return 0;
}