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
#define point complex<double>
#define xx first
#define yy second

const int maxn=100005;
set<int> g[maxn], tmp;
//vector<int> g1[maxn];
set<int>::iterator it;
int deg[maxn];
int v1[maxn], v2[maxn], used[maxn];
vector<int> heads, tails;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m, i, j, a, b, h, t, top, f, num, vv;
    scanf("%d %d %d %d", &n, &m, &h, &t);
    top=0;
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        v1[top]=a;
        v2[top++]=b;
        g[a].insert(b);
        g[b].insert(a);
        /*g1[a].pb(b);
        g1[b].pb(a);*/
        deg[a]++;
        deg[b]++;
    }
    if (h<t)
    {
        swap(h, t);
        f=1;
    }
    else
    {
        f=0;
    }
    for(i=0; i<top; i++)
    {
        if (deg[v1[i]]<deg[v2[i]])
            swap(v1[i], v2[i]);
        if (deg[v1[i]]<h+1 || deg[v2[i]]<t+1)
            continue;
        if (deg[v1[i]]>=h+t+1 && deg[v2[i]]>=h+t+1)
        {
            used[v1[i]]=used[v2[i]]=1;
            for(it=g[v1[i]].begin(), j=0; j<h; it++)
                if (!used[*it])
                {
                    used[*it]=1;
                    heads.pb(*it);
                    j++;
                }
            for(it=g[v2[i]].begin(), j=0; j<t; it++)
                if (!used[*it])
                {
                    used[*it]=1;
                    tails.pb(*it);
                    j++;
                }
            if (f)
            {
                swap(heads, tails);
                swap(h, t);
                swap(v1[i], v2[i]);
            }
            printf("YES\n%d %d\n", v1[i], v2[i]);
            for(j=0; j<h; j++)
                printf("%d ", heads[j]);
            putchar('\n');
            for(j=0; j<t; j++)
                printf("%d ", tails[j]);
            putchar('\n');
            return 0;
        }
        num=0;
        /*for(j=0; j<(int)g1[v2[i]].size(); j++)
        {
            vv=g1[v2[i]][j];
            if (vv==v1[i])
                continue;
            
        }*/
        for(it=g[v2[i]].begin(); it!=g[v2[i]].end(); it++)
        {
            if ((*it)==v1[i])
                continue;
            if (g[v1[i]].find(*it)!=g[v1[i]].end())
            {
                num++;
            }
        }
        if ((deg[v1[i]]-1)+(deg[v2[i]]-1)-num<h+t)
            continue;
        for(it=g[v2[i]].begin(); it!=g[v2[i]].end(); it++)
        {
            if ((*it)==v1[i])
                continue;
            if (g[v1[i]].find(*it)!=g[v1[i]].end())
            {
                tmp.insert(*it);
            }
        }
        for(it=g[v2[i]].begin(); it!=g[v2[i]].end(); it++)
        {
            if ((*it)==v1[i])
                continue;
            if (g[v1[i]].find(*it)==g[v1[i]].end())
                tails.pb(*it);
            if ((int)tails.size()==t)
                break;
        }
        if ((int)tails.size()<t)
        {
            for(it=g[v2[i]].begin(); it!=g[v2[i]].end(); it++)
            {
                if ((*it)==v1[i])
                    continue;
                if (tmp.find(*it)!=tmp.end())
                {
                    tails.pb(*it);
                    g[v1[i]].erase(*it);
                    if ((int)tails.size()==t)
                        break;
                }
            }
        }
        for(it=g[v1[i]].begin(); it!=g[v1[i]].end(); it++)
        {
            if ((*it)==v2[i])
                continue;
            heads.pb(*it);
            if (heads.size()==h)
                break;
        }
        if (f)
        {
            swap(heads, tails);
            swap(h, t);
            swap(v1[i], v2[i]);
        }
        printf("YES\n%d %d\n", v1[i], v2[i]);
        for(j=0; j<h; j++)
            printf("%d ", heads[j]);
        putchar('\n');
        for(j=0; j<t; j++)
            printf("%d ", tails[j]);
        putchar('\n');
        return 0;
    }
    printf("NO");
}