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

const ll N = 100007;

int n;
int d[N];
int a[N], b[N];
vector < int > g[N];
void dfs (int k){
    if (g[k].size() == 0)
        d[k] = 1;
    for (int i = 0; i < g[k].size(); i++){
        dfs (g[k][i]);
        d[k] += d[g[k][i]];
    }
    a[d[k]]++;
}

int main()
{
    cin>>n;
    for (int i = 2; i <= n; i++){
        int x;
        cin>>x;
        g[x].pb (i);
    }
    dfs (1);
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = n; i >= 1; i--)
        b[a[i]] = i;
    for (int i = n - 1; i >= 1; i--)
        if (b[i] == 0)
            b[i] = b[i + 1];
    for (int i = 1; i <= n; i++)
        cout<<b[i]<<" ";
    return 0;
}