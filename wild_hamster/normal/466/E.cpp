#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,y,max1,parent[100500],tmp,rank[100500],used[100500],t,timer;
ll in[100500],out[100500],pointer[100500];
vector <ll> backgraph[100500],graph[100500];
vector <ll> f[100500],packs[100500],results[100500];
vector <ll> roots;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
ll find_parent(ll v)
{
 if (v == parent[v]) return v;
 return parent[v] = find_parent(parent[v]); 
}
void union_sets(ll a, ll b)
{
     a = find_parent(a);
     b = find_parent(b);
     if (a == b) return;
     if (rank[a] > rank[b]) swap(a,b);
     parent[b] = a;
     if (rank[a] == rank[b])
        rank[b]++;
}
ll find_root(ll v)
{
 if (used[v]) return -1;
 used[v] = 1;
 if (backgraph[v].size() == 0)
    return v;
 return find_root(backgraph[v][0]);
}
void dfs(int v)
{
    used[v] = 1;
    timer++;
    in[v] = timer;
    for (int i = 0; i < graph[v].size(); i++)
        if (!used[graph[v][i]])
           dfs(graph[v][i]);
    out[v] = timer;
}
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
    for (i = 0; i < m; i++)
    {
     cin >> t;
     if (t == 1 || t == 3)
     {
           cin >> x >> y;
           if (t == 1)
           {
                 backgraph[x].push_back(y);
                 graph[y].push_back(x);
           }
           f[i].push_back(t);
           f[i].push_back(x);
           f[i].push_back(y);
           if (t == 3)
           {
               packs[y].push_back(x);
           }
     } else
     {
           cin >> x;
           f[i].push_back(t);
           f[i].push_back(x);
     }
    }
    for (i = 1; i <= n; i++)
    {
        tmp = find_root(i);
        if (tmp!= -1) roots.push_back(tmp);
    }
    for (i = 1; i <= n; i++)
        used[i] = 0;
    for (i = 0; i < roots.size(); i++)
    {
        timer = 0;
        dfs(roots[i]);
    }
    ll cnt = 0;
    for (i = 0; i < m; i++)
    {
        if (f[i][0] == 1)
           union_sets(f[i][1],f[i][2]);
        
        if (f[i][0] == 2)
        {
         cnt++;
         for (j = 0; j < packs[cnt].size(); j++)
         {
             if (find_parent(packs[cnt][j]) == find_parent(f[i][1])&&
             in[f[i][1]]>=in[packs[cnt][j]]&&out[f[i][1]]<=out[packs[cnt][j]])
             results[cnt].push_back(1);
             else
             results[cnt].push_back(0);
         }
        }     
        if (f[i][0] == 3)
        {
         if (results[f[i][2]][pointer[f[i][2]]] == 1)
            cout << "YES" << endl;
         else
             cout << "NO" << endl;
         pointer[f[i][2]]++;
        }
    }
    return 0;
}