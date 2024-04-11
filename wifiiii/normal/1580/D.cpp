#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 4e3 + 5;
int stk[maxn], ls[maxn], rs[maxn], tp=0, tot=0;
ll a[maxn];
void insert(int x) {
    int k=tp; a[++tot]=x;
    while(k && a[stk[k]]>a[tot]) --k;
    if(k) rs[stk[k]]=tot;
    if(k<tp) ls[tot]=stk[k+1];
    stk[++k]=tot; tp=k;
}

ll dp[maxn][maxn];
int sz[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insert(x);
    }
    function<void(int)> dfs = [&](int u) {
        sz[u]=1;
        if(!ls[u] || !rs[u]) {
            dp[u][1]=1ll*a[u]*(m-1);
            if(ls[u]) {
                dfs(ls[u]);
                for(int i=0;i<=sz[ls[u]];++i) {
                    dp[u][i]=max(dp[u][i],dp[ls[u]][i]);
                    dp[u][i+1]=max(dp[u][i+1],-2*i*a[u]+dp[ls[u]][i]+1ll*a[u]*(m-1));
                }
                sz[u]+=sz[ls[u]];
            }
            if(rs[u]) {
                dfs(rs[u]);
                for(int i=0;i<=sz[rs[u]];++i) {
                    dp[u][i]=max(dp[u][i],dp[rs[u]][i]);
                    dp[u][i+1]=max(dp[u][i+1],-2*i*a[u]+dp[rs[u]][i]+1ll*a[u]*(m-1));
                }
                sz[u]+=sz[rs[u]];
            }
        } else {
            dfs(ls[u]);
            dfs(rs[u]);
            for(int i=0;i<=sz[ls[u]];++i) {
                for(int j=0;j<=sz[rs[u]];++j) {
                    dp[u][i+j]=max(dp[u][i+j],-2*i*j*a[u]+dp[ls[u]][i]+dp[rs[u]][j]);
                    dp[u][i+j+1]=max(dp[u][i+j+1],-2*i*j*a[u]-2*(i+j)*a[u]+dp[ls[u]][i]+dp[rs[u]][j]+1ll*a[u]*(m-1));
                }
            }
            sz[u]+=sz[ls[u]]+sz[rs[u]];
        }
    };
    int rt = stk[1];
    dfs(rt);
    cout << dp[rt][m] << '\n';;
}