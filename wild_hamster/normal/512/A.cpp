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
ll n,i,j,d,x,y,m,len,l,r,sum,a[105005],used[300],flag,k1,k2,k;
string s[150];
ll graph[300][300],grb[300][300];
vector <ll> order,component,ska;
void add_edges(string x, string y)
{
     int i;
     for (i = 0; i < x.size(); i++)
     {
         if (i >= y.size())
         {
               flag = 0;
               return;
         }
         if (x[i]!=y[i])
         {
           graph[x[i]][y[i]] = 1;
           grb[y[i]][x[i]] = 1;
           break;
         }
     }
}
void dfs1 (int v) {
    used[v] = true;
    for (int i='a'; i<='z'; ++i)
    if (graph[v][i] == 1)
        if (!used[i])
            dfs1 (i);
    order.push_back (v);
}
 
void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (int i='a'; i<='z'; ++i)
    if (grb[v][i] == 1)
        if (!used[i])
            dfs2 (i);
}

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = 0; i < 256; i++)
        a[i] = 50;
    flag = 1;
    for (i = 0; i < n-1; i++)
    {
        add_edges(s[i],s[i+1]);
        if (flag == 0)
        {
                 cout << "Impossible" << endl;
                 return 0;
        }
    }
    for (i = 'a'; i <= 'z'; i++)
        used[i] = 0;
    for (int i='a'; i<='z'; ++i)
        if (!used[i])
        {
            dfs1 (i);
            k1++;
        }
    for (i = 'a'; i <= 'z'; i++)
        used[i] = 0;
    for (int i=0; i<=25; ++i) {
        int v = order[25-i];
        if (!used[v]) {
            dfs2 (v);
            k2++;
            component.clear();
        }
    }
    if (k2 != 26)
    {
           //system("pause");
          cout << "Impossible" << endl;
          return 0; 
    }
    for (i = 'a'; i <= 'z'; i++)
    {
        ll tmp = 0;
        for (j = 'a'; j <= 'z'; j++)
            tmp += graph[i][j];
        if (tmp == 0)
        {
                a[i] = 26;
                ska.clear();
                ska.push_back(i);
                j = 0;
                while (j < ska.size())
                {
                      ll v = ska[j];
                      for (k = 'a'; k <= 'z'; k++)
                          if (grb[v][k]&&a[k] >= a[v])
                          {
                           a[k] = a[v] - 1;
                           ska.push_back(k);
                          }
                          j++;
                }
        }
    }
    
        for (j = 0; j <= 26; j++)
    for (i = 'a'; i <= 'z'; i++)
            if (a[i] == j)
               cout << (char)i;
    cout << endl;
    return 0;
}