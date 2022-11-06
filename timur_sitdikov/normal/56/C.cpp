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

struct vertex
{
    string name;
    vector<int> ch;
    int prv;
};

int ans;
vector<vertex> g;

void dfs(int s, string &name)
{
    if (g[s].name==name)
        ans++;
    for(int i=0; i<g[s].ch.size(); i++)
        dfs(g[s].ch[i], name);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s, tmp;
    vertex vv;
    vv.prv=0;
    int i, cur, top;
    cin >> s;
    cur=0;
    top=1;
    g.pb(vv);
    for(i=0; i<(int)s.length(); i++)
    {
        if (s[i]==':' || s[i]==',')
        {
            if (s[i]==':')
            {
                g[cur].name=tmp;
                tmp.clear();
            }
            g[cur].ch.pb(top);
            g.pb(vv);
            g[top].prv=cur;
            cur=top;
            top++;
        }
        else if (s[i]=='.')
        {
            if (!tmp.empty())
            {
                g[cur].name=tmp;
                tmp.clear();
            }
            cur=g[cur].prv;
        }
        else
            tmp.pb(s[i]);
    }
    for(i=0; i<top; i++)
        dfs(i, g[i].name);
    cout << ans-top;
}