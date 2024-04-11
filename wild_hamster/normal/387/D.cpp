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
ll n,i,j,d,m,x,y,p,k,max1,a[1005][1005],used[1005],mt[1600],e,l,rez;
string s1,s2,s;
vector <ll> graph[1500],backgraph[1500];
ll rows[1500],cols[1500],lal[1500];
bool try_kuhn(ll v)
{
     if (used[v]) return false;
     used[v] = 1;
     for (int i = 0; i < graph[v].size(); i++)
     {
         ll to = graph[v][i];
         if ((mt[to] == -1||try_kuhn(mt[to]))&&to!=j)
         {
          mt[to] = v;
          return true;
         }
     }
     return false;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        rows[x]++;
        cols[y]++;
        if (x == y) lal[x] = 1;       
    }
    
    rez = 100000000;
    for (j = 1; j <= n; j++)
    {
    x = j;
    ll cnt = 2*n-1-(rows[x]+cols[x]-lal[x]);
    //cout << cnt << " ";
    for (i = 1; i <= n; i++)
        mt[i] = -1;
    for (i = 1; i <= n; i++)
    {
        for (k = 1; k <= n; k++)
            used[k] = 0;
        used[j] = 1;
        try_kuhn(i);
    }
    ll tmp = 0;
    for (i = 1; i <= n; i++)
        if (mt[i]!=-1)
           tmp++;
    cnt += (n - 1 - tmp) + m - (rows[x]+cols[x]-lal[x]) - tmp;
    rez = min(rez,cnt);
    //cout << cnt << endl;
    //cout << tmp << endl;
    }
    cout << rez << endl;
    return 0;
}