#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
typedef long long ll;
using namespace std;
    ll n,a[1005][1005],i,j,x,y,maxs[1005],k,x1,x2,y1,y2,rez;
    vector<vector<ll> > graph(10000);
int dfs(int v)
{
    int i;
    if (maxs[v] > 0) return maxs[v];
    if (graph[v].size() == 0) return 1;
    int max1 = 0;
    for (i = 0; i < graph[v].size(); i++)
        max1 = max(max1,dfs(graph[v][i]));
    maxs[v] = max1 + 1;
    return max1 + 1;
}
int main()
{
    cin >> n >> k;
    for (i = 0; i < k; i++)
    {
        int b[1005];
        for (j = 0; j < n; j++)
            cin >> b[j];
        for (j = 0; j < n; j++)
            for (x = j+1; x < n; x++)
                a[b[j]][b[x]]++;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == k) graph[i].push_back(j);
    rez = 0;
    for (i = 1; i <= n; i++)
        rez = max(rez,(ll)dfs(i));
    cout << rez << endl;
    return 0;
}