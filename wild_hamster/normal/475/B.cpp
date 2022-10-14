#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],used[1000],n,m,j,p,k1,k2,k3,k,i,cur;
string s1,s2;
vector <ll> graph[1000];
void dfs(int v)
{
     used[v] = 1;
     for (int i = 0; i < graph[v].size(); i++)
         if (!used[graph[v][i]])
            dfs(graph[v][i]);
}
int main()
{
    cin >> n >> m;
    cin >> s1 >> s2;
    for (i = 0; i < n; i++)
    {
        if (s1[i] == '>')
        {
        for (j = 0; j < m; j++)
            for (k = j+1; k < m; k++)
                graph[j+i*m].push_back(k+i*m);
        }
        else
        for (j = m-1; j >= 0; j--)
            for (k = j-1; k >= 0; k--)
                graph[j+i*m].push_back(k+i*m);
    }
    for (i = 0; i < m; i++)
    {
        if (s2[i] == 'v')
        {
        for (j = 0; j < n; j++)
            for (k = j+1; k < n; k++)
                graph[m*j+i].push_back(m*k+i);
        }
        else
        for (j = n-1; j >= 0; j--)
            for (k = j-1; k >= 0; k--)
                graph[m*j+i].push_back(m*k+i);
    }
    /*for (i = 0; i < n*m; i++)
    {
        for (j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }*/
    ll z = 1;
    for (j = 0; j < n*m; j++)
    {
    for (i = 0; i < n*m; i++)
        used[i] = 0;
    dfs(j);
    for (i = 0; i < n*m; i++)
    {
        //cout << used[i] << " ";
        if (!used[i]) z = 0;
    }
    }
    if (z) cout << "YES" << endl;
       else cout << "NO" << endl;   
   return 0;
}