#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100001;
vector<int> g[N];
vector<int> bg[N];
int w[N];
int s[N];
int d[N];
int low[N];

int n;
ll ans;

void dfs(int v, int prev)
{
    low[v] = d[v] = d[prev] + 1;
    s[v] = 1;
    w[v] = 1;
    for(int u: g[v])
        if(u != prev)
        {
            if(!d[u])
            {
                dfs(u, v);
                low[v] = min(low[v], low[u]);
                s[v] += s[u];
            }
            else if(d[u] < d[v])
            {
                low[v] = min(low[v], d[u]);
                bg[v].push_back(u);
                bg[u].push_back(v);
            }
        }
    if(prev)
        if(low[v] == d[v])
        {
            w[v] += n - s[v];
            w[prev] += s[v];
            ans += 2LL * s[v] * (n - s[v]);
        }
        else
        {
            bg[v].push_back(prev);
            bg[prev].push_back(v);
        }
}

bool vis[N];
int cnr[N];
int snr[N];
bool onp[N];
vector<int> com;
vector<int> sp;
vector<vector<int>> dist;
int cn, sn;

void dfs1(int v, int prev)
{
    //printf("dfs1(%d %d)\n", v, prev);
    vis[v] = true;
    cnr[v] = com.size();
    com.push_back(v);
    bool special = prev == 0 || bg[v].size() > 2;
    for(int u: bg[v])
        if(u != prev)
            if(!vis[u])
                dfs1(u, v);
            else special = true;
    if(special)
    {
        snr[v] = sp.size();
        sp.push_back(v);
    }
    else snr[v] = -1;
}

void bfs(int k)
{
    int s = sp[k];
    queue<int> q;
    q.push(s);
    dist[k][cnr[s]] = 0;
    while(!q.empty())
    {
        int v = q.front(), d = dist[k][cnr[v]];
        q.pop();
        ans += 1LL * w[sp[k]] * w[v] * d;
        for(int u: bg[v])
        {
            auto &du = dist[k][cnr[u]];
            if(du == -1)
            {
                du = d + 1;
                q.push(u);
            }
        }
    }
}

pair<int, vector<int>> path(int v, int prev)
{
    vector<int> vec;
    while(snr[v] == -1)
    {
        vis[v] = true;
        vec.push_back(v);
        int u = bg[v][0] ^ bg[v][1] ^ prev;
        prev = v;
        v = u;
    }
    return { v, vec };
}

void dfs2(int v)
{
    vis[v] = true;
    for(int u: bg[v])
        if(!vis[u])
        {
            auto p = path(u, v);
            auto &vec = p.second;
            u = p.first;
            if(!vec.empty())
            {
                for(int i: vec)
                    onp[i] = true;
                int a = snr[v], b = snr[u];
                vector<pair<int, int>> diff;
                ll dsum = 0, asum = 0, bsum = 0, psum = 0, pstep = 0;
                for(int i = 0; i < cn; i++)
                    if(!onp[com[i]])
                    {
                        diff.emplace_back(dist[b][i] - dist[a][i], i);
                        dsum += 1LL * dist[a][i] * w[com[i]];
                        asum += w[com[i]];
                    }
                sort(diff.begin(), diff.end());
                //printf("%lld\n", ans);
                for(int i = 0, j = 0; i < vec.size(); i++)
                {
                    while(j < diff.size())
                    {
                        int k = diff[j].second;
                        if(dist[b][k] + vec.size() - i < dist[a][k] + i + 1)
                        {
                            dsum += 1LL * diff[j].first * w[com[k]];
                            asum -= w[com[k]];
                            bsum += w[com[k]];
                            j++;
                        }
                        else break;
                    }
                    ans += 1LL * w[vec[i]] * (dsum + 1LL * (vec.size() - i) * bsum + 1LL * (i + 1) * asum);
                    //printf("%lld\n", ans);
                    //printf("%d %lld %lld %lld\n", w[vec[i]], dsum, asum, bsum);
                }
                int c = vec.size() + 1 + dist[snr[u]][cnr[v]];
                for(int h: { 0, 1 })
                {
                    psum = pstep = 0;
                    int vh = (vec.size() + h) / 2;
                    for(int i = 0; i < vh; i++)
                    {
                        psum += 1LL * i * w[vec[i]];
                        pstep -= w[vec[i]];
                    }
                    for(int i = vh; i < vec.size(); i++)
                    {
                        psum += 1LL * (c - i) * w[vec[i]];
                        pstep += w[vec[i]];
                    }
                    for(int i = 0, j = vh; i < vh; i++)
                    {
                        while(j < vec.size() && c - 2 * (j - i) > 0)
                        {
                            psum -= 1LL * w[vec[j]] * (c - 2 * (j - i));
                            pstep -= 2 * w[vec[j]];
                            j++;
                        }
                        ans += psum * w[vec[i]];
                        pstep += 2 * w[vec[i]];
                        psum += pstep;
                    }
                    reverse(vec.begin(), vec.end());
                }
                for(int i: vec)
                    onp[i] = false;
            }
            dfs2(u);
        }
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
        {
            com.clear();
            sp.clear();
            dfs1(i, 0);
            
            cn = com.size();
            sn = sp.size();
            if(cn == 1) continue;
            
            dist.clear();
            dist.resize(sn, vector<int>(cn, -1));
            
            for(int j = 0; j < sn; j++)
                bfs(j);
            
            for(int j: com)
                vis[j] = false;
                
            dfs2(i);
        }
    printf("%lld\n", ans / 2);
}