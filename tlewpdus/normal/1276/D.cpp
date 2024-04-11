#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<pii> lis[200100];
ll D[200100][4];

ll pre[200100], suf[200100];
void dfs(int here, int p, int tim) {
    int ti = -1;
    for (int i=0;i<lis[here].size();i++){
        if (lis[here][i].second==p) {
            ti = i;
            continue;
        }
        dfs(lis[here][i].second,here,lis[here][i].first);
    }
    if (~ti) lis[here].erase(lis[here].begin()+ti);
    if (lis[here].empty()) {
        D[here][0] = 1;
        D[here][1] = 1;
        D[here][2] = 1;
        D[here][3] = 0;
        return;
    }
    sort(lis[here].begin(),lis[here].end());
    pre[0] = 1;
    suf[(int)lis[here].size()+1]=1;
    for (int i=1;i<=lis[here].size();i++) {
        int there = lis[here][i-1].second;
        pre[i]=pre[i-1]*(D[there][1]+D[there][3])%MOD;
    }
    for (int i=lis[here].size();i>0;i--) {
        int there = lis[here][i-1].second;
        suf[i]=suf[i+1]*D[there][0]%MOD;
    }
    int done = 0;
    for (int i=1;i<=1+(int)lis[here].size();i++) {
        int there = lis[here][i-1].second;
        ll val = (i<=lis[here].size()?D[there][2]*pre[i-1]%MOD*suf[i+1]%MOD:pre[i-1]);
        D[here][0]=(D[here][0]+val)%MOD;
        if (i-1==lis[here].size()||tim<lis[here][i-1].first) D[here][2]=(D[here][2]+val)%MOD;
        if (i-1 <lis[here].size()&&tim>lis[here][i-1].first) D[here][3]=(D[here][3]+val)%MOD;
        if ((i-1==lis[here].size()||tim<lis[here][i-1].first)&&!done) {
            D[here][1]=pre[i-1]*suf[i]%MOD;
            done = 1;
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back({i,b});
        lis[b].push_back({i,a});
    }
    dfs(0,-1,-1);
    printf("%lld\n",D[0][0]);

	return 0;
}