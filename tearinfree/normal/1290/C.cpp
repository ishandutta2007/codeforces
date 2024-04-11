#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,pa[300001],r[300001],f[300001],sz[300001];
vector<int> con[300001];
pii val[300001];
char str[300010];

int find(int cur) {
    if(cur==pa[cur]) return cur;
    else return find(pa[cur]);
}
int get(int cur) {
    if(f[cur]==-1) return max(val[cur].first, val[cur].second);
    else if(f[cur]==0) return val[cur].fi;
    else return val[cur].se;
}
int find_r(int cur) {
    if(cur==pa[cur]) return 0;
    else return r[cur] ^ find_r(pa[cur]);
}
int merge(int u,int v,int t) {
    int ur=find_r(u), vr=find_r(v);
    u = find(u); v = find(v);
    if(u==v) return 0;

    int ret = -get(u)-get(v);
    
    if(sz[u] < sz[v]) swap(u, v);

    if(!(t^ur^vr)) {
        val[u].first += val[v].first;
        val[u].second += val[v].second;
        pa[v] = u;
        sz[u]+=sz[v];
    } else {
        val[u].first += val[v].second;
        val[u].second += val[v].first;
        pa[v] = u;
        sz[u]+=sz[v];
        r[v] = 1;
    }
    if(f[v] != -1) {
        f[u] = f[v] ^ r[v];
    }
    return ret + get(u);
}

int one(int cur,int t) {
    int p = find(cur);
    int ret = -get(p);
    int tr = find_r(cur);
    f[p] = tr^t;
    return ret + get(p);
}

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) str[i] -= '0';
    
    for(int i=1;i<=m;i++) {
        int s;
        scanf("%d",&s);
        for(int j=0,v;j<s;j++) {
            scanf("%d",&v);
            con[v].push_back(i);
        }
    }

    int ans = m;
    for(int i=1;i<=m;i++) {
        pa[i] = i; f[i] = -1; sz[i] = 1;
        val[i].fi = 1;
    }

    for(int i=1;i<=n;i++) {
        if(con[i].size() == 1) {
            ans += one(con[i][0], str[i]==0);
        } else if(con[i].size()==2) {
            int u = con[i][0], v=con[i][1];
            ans += merge(u, v, str[i]==0);
        }
        printf("%d\n",m-ans);
    }

    return 0;
}