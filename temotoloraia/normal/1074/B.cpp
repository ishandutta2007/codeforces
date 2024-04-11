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
const int N = 3e5 + 7;

int n;
vector < int > g[N];
int m, a[N];
int k, b[N];
bool F1[N], F2[N];
int dfs (int node, int par){
    if (F1[node])
        return node;
    for (int i = 0; i < g[node].size(); i++)
        if (g[node][i] != par){
            int y = dfs (g[node][i], node);
            if (y)
                return y;
        }
    return 0;
}

int main()
{
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        for (int i = 1; i <= n; i++){
            g[i].clear();
            F1[i] = 0;
            F2[i] = 0;
        }
        for (int i = 1; i < n; i++){
            int u, v;
            scanf ("%d %d", &u, &v);
            g[u].pb (v);
            g[v].pb (u);
        }
        cin>>m;
        for (int i = 1; i <= m; i++){
            scanf ("%d", &a[i]);
            F1[a[i]] = 1;
        }
        cin>>k;
        for (int i = 1; i <= k; i++){
            scanf ("%d", &b[i]);
            F2[b[i]] = 1;
        }
        cout<<"B "<<b[1]<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        int y = dfs (x, 0);
        cout<<"A "<<y<<endl;
        fflush(stdout);
        cin>>x;
        if (F2[x] == 0)
            y = -1;
        cout<<"C "<<y<<endl;
        fflush(stdout);
    }
    return 0;
}