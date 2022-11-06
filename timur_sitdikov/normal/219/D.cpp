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
#pragma comment(linker, "/STACK:100000000")

const int nmax=200005;
vector<pair<int , int > > g[nmax];
vector<int> goods;
int ans, cur;
char col[nmax], col1[nmax];

void dfs1(int s)
{
    col1[s]=1;
    for(int i=0; i<(int)g[s].size(); i++)
        if (!col1[g[s][i].first])
        {
            cur+=(g[s][i].second==-1);
            dfs1(g[s][i].first);
        }
}

void dfs(int s)
{
    col[s]=1;
    if (cur<ans)
    {
        goods.clear();
        ans=cur;
    }
    if (cur==ans)
        goods.pb(s);
    for(int i=0; i<(int)g[s].size(); i++)
        if (!col[g[s][i].first])
        {
            cur+=g[s][i].second;
            dfs(g[s][i].first);
            cur-=g[s][i].second;
        }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, a, b;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> a >> b;
        g[a].pb(mp(b, 1));
        g[b].pb(mp(a, -1));
    }
    dfs1(1);
    ans=cur;
    dfs(1);
    cout << ans << endl;
    sort(goods.begin(), goods.end());
    for(i=0; i<(int)goods.size(); i++)
        cout << goods[i] << " ";
}