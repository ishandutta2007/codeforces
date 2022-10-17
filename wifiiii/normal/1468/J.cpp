#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tp=0;
const int maxn = 200005;
struct edge
{
    int u,v,w;
    bool operator < (const edge & e) const
    {
        return w < e.w;
    }
}es[maxn];
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i) par[i]=i;
        int mx=0,mn=2e9;
        tp=0;
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            // if w < k, choose it.
            if(w <= k)
            {
                par[find(u)] = find(v);
                mx = max(mx, w);
            }
            else
            {
                es[++tp] = {u, v, w};
                mn = min(mn, w);
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;++i) if(find(i) == i) ++cnt;
        if(cnt == 1)
        {
            cout << min(k - mx, mn - k) << endl;
        }
        else
        {
            // choose more
            sort(es+1, es+1+tp);
            long long ans = 0;
            for(int i=1;i<=tp;++i)
            {
                if(find(es[i].u) != find(es[i].v))
                {
                    ans += es[i].w - k;
                    par[find(es[i].u)] = find(es[i].v);
                    --cnt;
                    if(cnt == 1) break;
                }
            }
            cout << ans << endl;
        }
    }
}