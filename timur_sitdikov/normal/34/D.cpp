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

const int maxn = 50005;
vector<int> g[maxn];
char col[maxn];
int prv[maxn];

void dfs(int s)
{
    col[s]=1;
    for(int i=0; i<(int)g[s].size(); i++)
        if (!col[g[s][i]])
        {
            prv[g[s][i]]=s;
            dfs(g[s][i]);
        }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, a, i, s1, s2;
    cin >> n >> s1 >> s2;
    for(i=1; i<s1; i++)
    {
        cin >> a;
        g[i].pb(a);
        g[a].pb(i);
    }
    for(i=s1+1; i<=n; i++)
    {
        cin >> a;
        g[i].pb(a);
        g[a].pb(i);
    }
    dfs(s2);
    for(i=1; i<=n; i++)
        if (prv[i])
            cout << prv[i] << " ";
}