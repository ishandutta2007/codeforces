#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const int N = 1e5 + 5;

int n, K;
vector < int > g[N];
int d[N], D;
bool F[N];
int node = 1, NODE = 1;
void dfs (int k, int p){
    d[k] = d[p] + 1;
    for (int i = 0; i < g[k].size(); i++)
        if (g[k][i] != p)
            dfs (g[k][i], k);
}

int main()
{
    cin>>n>>K;
    for (int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    for (int i = 2; i <= n; i++)
        if (d[i] > d[node])
            node = i;
    dfs (node, 0);
    for (int i = 2; i <= n; i++)
        if (d[i] > d[NODE])
            NODE = i;
    D = d[NODE] - 1;
    if (D % 2 == 1){
        cout<<"No\n";
        return 0;
    }
    D /= 2;
    if (D != K){
        cout<<"No\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] - 1 == D)
            F[i] = 1;
    dfs (NODE, 0);
    for (int i = 1; i <= n; i++)
        if (d[i] - 1 == D && F[i] == 1)
            node = i;
    dfs (node, 0);
    if (g[node].size() < 3){
        cout<<"No\n";
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (i == node)
            continue;
        if (d[i] == D + 1 && g[i].size() > 1){
            cout<<"No\n";
            return 0;
        }
        if (d[i] <= D && g[i].size() <= 3){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}