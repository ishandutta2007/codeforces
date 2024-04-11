#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n;
vector<pii> adj[200001];
namespace minn {
    pair<lli,int> dfs(int cur,int p,int c) {
        lli cs=0;
        int ss=1;
        for(auto &it:adj[cur]) if(it.se!=p) {
            auto tmp = dfs(it.se, cur, it.fi);
            cs += tmp.fi;
            ss += tmp.se;
        }
        ss %= 2;
        cs += c * ss;
        return {cs, ss};
    }
    lli solve() {
        return dfs(1,0,0).fi;
    }
}
namespace maxx {
    int sz[200001];
    void get_sz(int cur,int p) {
        sz[cur] = 1;
        for(auto &it:adj[cur]) if(it.se != p) {
            get_sz(it.se, cur);
            sz[cur] += sz[it.se];
        }
    }
    int cent(int cur,int p,int s) {
        int ch = 0;
        for(auto &it:adj[cur]) if(it.se != p && sz[it.se] >= s) {
            ch = it.se;
            break;
        }
        if(!ch) return cur;
        else return cent(ch, cur, s);
    }
    pair<lli,int> dfs(int cur,int p,int c) {
        lli cs=0;
        int ss = 1;
        for(auto &it:adj[cur]) if(it.se!=p) {
            auto tmp = dfs(it.se, cur, it.fi);
            cs += tmp.fi;
            ss += tmp.se;
        }
        return {cs + 1ll*ss*c, ss};
    }
    lli solve() {
        get_sz(1, 0);
        
        int root = cent(1, 0, (sz[1]+1)/2);
        lli sum = 0;
        for(auto &it:adj[root]) sum += dfs(it.se, root, it.fi).fi;
        return sum;
    }
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        n *= 2;
        for(int i=1,u,v,w;i<n;i++) {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        printf("%lld %lld\n",minn::solve(), maxx::solve());
        for(int i=1;i<=n;i++) adj[i].clear();
    }
    return 0;
}