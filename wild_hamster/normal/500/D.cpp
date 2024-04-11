#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll n,i,j,x,y,a[200500],to[200500],c[200500],m,k1,k2,used[100500];
double b[200500];
map <pair <ll,ll>, ll> lalki;
vector <ll> graph[100500];
ll dfs(ll v)
{
     used[v] = 1;
     ll k = 0;
     ll i, sum = 0;
     for (i = 0; i < graph[v].size(); i++)
     if (!used[graph[v][i]])
     {
         k++;
         sum += dfs(graph[v][i]);
         to[graph[v][i]] = v;
     }
     if (k == 0) 
     {
      c[v] = 1;
      return 1;
     } else
     {
      c[v] = sum+1;
      return sum+1;
     }
}
int main()
{
    cin >> n;
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y >> j;
        lalki[mp(x,y)] = i+1;
        lalki[mp(y,x)] = i+1;
        a[i+1] = j;        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    for (i = 2; i <= n; i++)
    {
        ll tmp = lalki[mp(to[i],i)];
        b[tmp] = (double)(c[i]*(n-c[i]));
    }
    double rez = 0;
    for (i = 1; i < n; i++)
    {
       // cout << b[i] << endl;
        rez += b[i]*a[i]*6./(double)(n*(n-1));
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        rez -= (a[x]-y)*b[x]*6./(double)(n*(n-1));
        a[x] = y;
        printf("%.10f\n",rez);
    }
    return 0;
}