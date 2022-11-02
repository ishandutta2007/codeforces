#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

vector<int> E[MAXN];
ll co[MAXN], ce[MAXN], so[MAXN], se[MAXN];
int n;
ll ans;

void dfs(int u, int fa){
    co[u] = so[u] = se[u] = 0;
    //ce[u] = 1;
    for (auto &v : E[u]){
        if (v != fa){
            dfs(v, u);
            co[u] += ce[v];
            ce[u] += co[v];
            so[u] += se[v];
            se[u] += so[v];
        }
    }
    ll ret = 0;
    for (auto &v : E[u]){
        if (v != fa){
            ll Ce = co[u] - ce[v];
            ll Co = ce[u] - co[v];
            ll Se = so[u] - se[v];
            ll So = se[u] - so[v];
            ret += (so[v]*Co+co[v]*So+co[v]*Co*2) / 2;
            ret += (se[v]*Ce+ce[v]*Se+ce[v]*Ce*2) / 2;
            ret += (so[v]*Ce+co[v]*Se+co[v]*Ce*3) / 2;
            ret += (se[v]*Co+ce[v]*So+ce[v]*Co*3) / 2;
            ans += (so[v] + co[v]) / 2;
            ans += (se[v] + ce[v] * 2) / 2;
        }
    }
    ans += ret / 2;
    so[u] += co[u];
    se[u] += ce[u];
    ce[u]++;
    //cout << u << endl;
    //cout << co[u] << ' ' << so[u] << ' ' << ce[u] << ' ' << se[u] << endl;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    ans = 0;
    dfs(1, -1);
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}