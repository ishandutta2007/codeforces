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

const int N = 4123;

int n, m;

vector < int > g[N];

int mas[5];

int k, l;

int D[N][N];
queue < int > q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    cin >> mas[1] >> mas[2] >> k;
    cin >> mas[3] >> mas[4] >> l;
    for (int I = 1; I <= n; I++){
        for (int i = 1; i <= n; i++)
            D[I][i] = 1e8;
        D[I][I] = 0;
        q.push (I);
        while ((int)q.size() > 0){
            int u = q.front();
            q.pop();
            for (int v : g[u]){
                if (D[I][v] > D[I][u] + 1){
                    D[I][v] = D[I][u] + 1;
                    q.push (v);
                }
            }
        }
    }
    if (D[mas[1]][mas[2]] > k || D[mas[3]][mas[4]] > l){
        cout << -1 << endl;
        return 0;
    }
    int ans = D[mas[1]][mas[2]] + D[mas[3]][mas[4]];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (D[mas[1]][i] + D[i][j] + D[j][mas[2]] <= k && D[mas[3]][i] + D[i][j] + D[j][mas[4]] <= l)
                ans = min (ans, D[i][j] + D[i][mas[1]] + D[i][mas[3]] + D[j][mas[2]] + D[j][mas[4]]);
    swap (mas[3], mas[4]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (D[mas[1]][i] + D[i][j] + D[j][mas[2]] <= k && D[mas[3]][i] + D[i][j] + D[j][mas[4]] <= l)
                ans = min (ans, D[i][j] + D[i][mas[1]] + D[i][mas[3]] + D[j][mas[2]] + D[j][mas[4]]);
    cout << m - ans << endl;
    return 0;
}