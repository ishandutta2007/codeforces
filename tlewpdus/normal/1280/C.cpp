#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll G;
vector<pii> lis[200100];
ll D[200100][2];

int dfs(int here, int p, ll w) {
    int sz = 1;
    D[here][0] = LINF;
    D[here][1] =0;
    ll mini = LINF, sum = 0, cnt = 0;
    for (pii &tmp : lis[here]) {
        if (tmp.second==p) continue;
        sz += dfs(tmp.second,here,tmp.first);
        ll A = D[here][0], B = D[here][1];
        D[here][0] = min({LINF,B+D[tmp.second][1],A+D[tmp.second][0]});
        D[here][1] = min({LINF,B+D[tmp.second][0],A+D[tmp.second][1]});
    }
    G += 1LL*min(sz,n-sz)*w;
    D[here][1] += w;
    //printf("%d : %lld, %lld\n",here+1,D[here][0],D[here][1]);
    return sz;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n); n*=2;
        G=0;
        for (int i=0;i<n-1;i++) {
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c); --a; --b;
            lis[a].push_back({c,b});
            lis[b].push_back({c,a});
        }
        dfs(0,-1,0);
        printf("%lld %lld\n",D[0][0],G);
        for (int i=0;i<n;i++) lis[i].clear();
    }

	return 0;
}