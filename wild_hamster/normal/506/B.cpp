#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll rez,h,q,n,i,j,k1,k2,k3,d,x,k,y,xx,yy,m,l,r,c,t,sum,used[100500];
vector <ll> graph[100500],gr[100500],grb[100500];
vector <ll> comps[100500];
vector <ll> order;
void dfs(int v)
{
     if (used[v]) return;
     used[v] = 1;
     comps[j].push_back(v);
     for (int i = 0; i < graph[v].size(); i++)
         dfs(graph[v][i]);         
}
void dfs1(int v)
{
     if (used[v]) return;
     used[v] = 1;
     for (int i = 0; i < gr[v].size(); i++)
         dfs1(gr[v][i]);  
     order.push_back(v);   
}

void dfs2(int v)
{
     if (used[v]) return;
     used[v] = 1;
     for (int i = 0; i < grb[v].size(); i++)
         dfs2(grb[v][i]);  
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        gr[x].push_back(y);
        grb[y].push_back(x);
    }
    for (i = 0; i < n; i++)
        if (!used[i])
        {
           dfs(i);
           j++;
        }
    k = j;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < comps[i].size(); j++)
            used[comps[i][j]] = 0;
            
        l = 0; r = 0;
        order.clear();
        
        for (j = 0; j < comps[i].size(); j++)
        if (!used[comps[i][j]])
        {
            dfs1(comps[i][j]);
            l++;
        }
        
        for (j = 0; j < comps[i].size(); j++)
            used[comps[i][j]] = 0;
            
        for (j = 0; j < order.size(); j++)
        {
         //cout << order[order.size()-1-j] << endl;
         if (!used[ order[order.size()-1-j] ])
         {
             dfs2(order[order.size()-1-j]);
             r++;
         }
        }
        //cout << l << " " << r << endl;
        if (comps[i].size()!=r) rez += comps[i].size();
           else rez += comps[i].size() - 1;
    }
    cout << rez << endl;
    return 0;
}