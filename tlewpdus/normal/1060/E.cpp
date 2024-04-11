#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
vector<int> lis[200100];

ll ans = 0;
int cnt[2];
int sz[200100], dep[200100];
void dfs(int here, int p) {
    sz[here] = 1;
    dep[here] = (~p?dep[p]+1:0);
    cnt[dep[here]%2]++;
    for (int &there :lis[here]) {
        if (there==p) continue;
        dfs(there,here);
        sz[here] += sz[there];
    }
    ans += 1LL*sz[here]*(n-sz[here]);
}

int main() {
    int i;
    scanf("%d",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    dfs(0,-1);
    ans += 1LL*cnt[0]*cnt[1];
    printf("%lld\n",ans/2);

    return 0;
}