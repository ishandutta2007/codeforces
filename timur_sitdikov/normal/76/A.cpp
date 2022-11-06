#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

typedef pair<pair<long long, long long>, pair<int, int> > edge ;
typedef pair<long long, pair<int, int> > g_edge ;
vector<edge> edges;
g_edge bad_edge;
const int maxn=205;
vector<pair<long long, int> > g[maxn];
char col[maxn];
int prv[maxn];
int par[maxn];

int dfs(int s)
{
    col[s]=1;
    for(int i=0; i<(int)g[s].size(); i++)
    {
        if (col[g[s][i].second] && g[s][i].second!=prv[s])
        {
            bad_edge=mp(g[s][i].first, mp(s, g[s][i].second));
            return 1;
        }
        if (!col[g[s][i].second])
        {
            prv[g[s][i].second]=s;
            if (dfs(g[s][i].second))
            {
                if (g[s][i].first>bad_edge.first)
                    bad_edge=mp(g[s][i].first, mp(s, g[s][i].second));
                return 1;
            }
        }
    }
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, k, a, b, col1, col2, f;
    long long gg, s, x, y, c, mx, mx_ans=2000000000000000001, ans;
    vector<pair<long long, int> >::iterator it;
    ans=mx_ans;
    cin >> n >> m >> gg >> s;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> x >> y;
        if (a!=b)
            edges.pb(mp(mp(x, y), mp(a, b)));
    }
    for(i=1; i<=n; i++)
        par[i]=i;
    sort(edges.begin(), edges.end());
    for(i=0; i<(int)edges.size(); i=j)
    {
        for(j=i; j<(int)edges.size() && edges[j].first.first==edges[i].first.first; j++)
        {
            if (par[edges[j].second.first]!=par[edges[j].second.second])
            {
                g[edges[j].second.first].pb(mp(edges[j].first.second, edges[j].second.second));
                g[edges[j].second.second].pb(mp(edges[j].first.second, edges[j].second.first));
                col1=par[edges[j].second.first];
                col2=par[edges[j].second.second];
                for(k=1; k<=n; k++)
                    if (par[k]==col1)
                        par[k]=col2;
            }
            else
            {
                f=0;
                for(it=g[edges[j].second.first].begin(); it!=g[edges[j].second.first].end(); it++)
                    if (it->second==edges[j].second.second)
                    {
                        f=1;
                        break;
                    }
                if (f)
                {
                    if (it->first>edges[j].first.second)
                    {
                        it->first=edges[j].first.second;
                        for(it=g[edges[j].second.second].begin(); it!=g[edges[j].second.second].end(); it++)
                            if (it->second==edges[j].second.first)
                            {
                                it->first=edges[j].first.second;
                                break;
                            }
                    }
                    continue;
                }
                g[edges[j].second.first].pb(mp(edges[j].first.second, edges[j].second.second));
                g[edges[j].second.second].pb(mp(edges[j].first.second, edges[j].second.first));
                for(k=1; k<=n; k++)
                    col[k]=0;
                dfs(edges[j].second.first);
                a=bad_edge.second.first;
                b=bad_edge.second.second;
                c=bad_edge.first;
                for(it=g[a].begin(); it!=g[a].end(); it++)
                    if ((*it)==mp(c, b))
                    {
                        g[a].erase(it);
                        break;
                    }
                swap(a, b);
                for(it=g[a].begin(); it!=g[a].end(); it++)
                    if ((*it)==mp(c, b))
                    {
                        g[a].erase(it);
                        break;
                    }
            }
        }
        f=0;
        for(k=2; k<=n; k++)
            if (par[k]!=par[1])
            {
                f=1;
                break;
            }
        if (f)
            continue;
        mx=0;
        for(k=1; k<=n; k++)
            for(it=g[k].begin(); it!=g[k].end(); it++)
                if (it->first>mx)
                    mx=it->first;
        ans=min(ans, edges[i].first.first*gg+mx*s);
    }
    if (ans==mx_ans)
        cout << "-1";
    else 
        cout << ans;
}