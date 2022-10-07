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
using namespace std;

const int N = 1e6 + 5;

int n, m;
vector < int > g[N];

int a[N];

int T;
int in[N], out[N];

vector < int > v[N], vv[N];

void dfs (int k, int d){
    v[d].pb (k);
    vv[d].pb (a[k]);
    in[k] = ++T;
    for (int u : g[k]){
        dfs (u, d + 1);
    }
    out[k] = ++T;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 2; i <= n; i++){
        int u;
        scanf ("%d", &u);
        //cin >> u;
        g[u].pb (i);
    }
    for (int i = 1; i <= n; i++){
        char ch;
        //cin >> ch;
        ch = getchar();
        while (ch < 'a' || 'z' < ch)
            ch = getchar();
        int x = ch - 'a';
        a[i] = (1 << x);
    }
    for (int i = 1; i <= n; i++){
        v[i].pb (0);
        vv[i].pb (0);
    }
    dfs (1, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < (int)v[i].size(); j++)
            vv[i][j] ^= vv[i][j - 1];
    while (m--){
        int u, h;
        //cin >> u >> h;
        scanf ("%d %d", &u, &h);
        int l = 0, r = 0;
        for (int i = 19; i >= 0; i--){
            if (l + (1 << i) >= (int)v[h].size())
                continue;
            if (in[v[h][l + (1 << i)]] < in[u])
                l += (1 << i);
        }
        for (int i = 19; i >= 0; i--){
            if (r + (1 << i) >= (int)v[h].size())
                continue;
            if (out[v[h][r + (1 << i)]] <= out[u])
                r += (1 << i);
        }
        //cout << l << " " << r << " ";
        int x = (vv[h][l] ^ vv[h][r]);
        //x = 2;
        int y = (x & (x - 1));
        //cout << x << " " << x - 1 << " " << (x & (x - 1)) << " ";
        if (y == 0)
            //cout << "Yes" << "\n";
            printf ("Yes\n");
        else
            //cout << "No" << "\n";
            printf ("No\n");
    }
    return 0;
}