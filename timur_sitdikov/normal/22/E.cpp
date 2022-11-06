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
using namespace std;
#define mp make_pair
#define pb push_back

const int nmax=100005;
int g[nmax], col[nmax], out[nmax], in_st[nmax], good[nmax];
set<int> in[nmax];
vector<pair<int, int> > ans;
vector<int> cycle;

int dfs(int s, int cl)
{
    if (col[s])
    {
        if (col[s]==cl)
            out[cl]=s;
        return col[s];
    }
    col[s]=cl;
    int tmp=dfs(g[s], cl);
    col[s]=tmp;
    return tmp;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, tmp, cl, top;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> g[i];
        in_st[g[i]]++;
    }
    cl=0;
    for(i=1; i<=n; i++)
        if (in_st[i]==0)
        {
            tmp=dfs(i, ++cl);
            if (tmp!=cl) cl--;
            in[tmp].insert(i);
            good[i]=1;
        }
    for(i=1; i<=n; i++)
        if (!col[i])
        {
            dfs(i, ++cl);
            in[cl].insert(i);
        }
    top=cl;
    for(i=1; i<top; i++)
    {
        ans.pb(mp(out[i], *in[i+1].begin()));
        in[i+1].erase(in[i+1].begin());
    }
    if (out[top]!=(*in[1].begin()))
    {
        ans.pb(mp(out[top], *in[1].begin()));
        in[1].erase(in[1].begin());
    }
    set<int>::iterator it;
    for(i=1; i<=top; i++)
        for(it=in[i].begin(); it!=in[i].end(); it++)
            cycle.pb(*it);
    for(i=0; i<(int)cycle.size(); i++)
        if (good[cycle[i]])
            ans.pb(mp(out[1], cycle[i]));
    printf("%d\n", (int)ans.size());
    for(i=0; i<(int)ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

}