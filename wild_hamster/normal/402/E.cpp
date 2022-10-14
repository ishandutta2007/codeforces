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
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,t,x,y,k1,k2,k3,k4,k,i,w,rez,used[2005],used1[2005];
vector <ll> graph[2005],graph1[2005];
void dfs(ll v)
{
     if (!used[v])
        rez++;
     else
         return;
     used[v] = 1;
     for (ll i = 0; i < graph[v].size(); i++)
         dfs(graph[v][i]);
}
void dfs1(ll v)
{
     if (!used1[v])
        rez++;
     else
         return;
     used1[v] = 1;
     for (ll i = 0; i < graph1[v].size(); i++)
         dfs1(graph1[v][i]);
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d",&x);
            if (x > 0)
            {
               graph[i].push_back(j);
               graph1[j].push_back(i);
            }
        }
    rez = 0;
    dfs(0);
   // cout << rez << endl;
    dfs1(0);
    //cout << rez << endl;
    if (rez == 2*n)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
   return 0;
}