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
ll x1,y1,x2,y2,x,y,n,m,q,i,j,k,k1,k2,l,a[100500],mt[50000],used[50000];
ll rez;
set <ll> f;
set<ll>::iterator itr;
vector <ll> new_graph[3500];
vector <pair<ll,ll> > queries;
vector <ll> new_vertices[105];
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          return gcd(b,a%b);
}
bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<new_graph[v].size(); ++i) {
        int to = new_graph[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--; y--;
        if (x%2 == 1)
           swap(x,y);
        queries.push_back(mp(x,y));
    }
    for (i = 0; i < n; i++)
    {
        ll tmp = a[i];
        for (j = 2; j*j <= tmp; j++)
            while (tmp%j == 0)
            {
                  f.insert(j);
                  tmp /= j;
            }
        if (tmp > 1) f.insert(tmp);
    }
    for (itr = f.begin(); itr!=f.end(); itr++)
    {
        ll tmp = 0;
        ll numb = (*itr);
       // cout << numb << endl;
        for (i = 0; i < n; i++)
            new_vertices[i].clear();
        for (i = 0; i < n; i++)
            while (a[i]%numb == 0)
            {
                  new_vertices[i].push_back(tmp++);
                  a[i]/=numb;
            }
        for (i = 0; i < tmp; i++)
            new_graph[i].clear();
        for (i = 0; i < tmp; i++)
            mt[i] = -1;
        for (i = 0; i < m; i++)
        {
            x = queries[i].first; y = queries[i].second;
            for (j = 0; j < new_vertices[x].size(); j++)
                for (k = 0; k < new_vertices[y].size(); k++)
                {
                    new_graph[new_vertices[x][j]].push_back(new_vertices[y][k]);
                    new_graph[new_vertices[y][k]].push_back(new_vertices[x][j]);
                }            
        }
        /*for (i = 0; i < tmp; i++)
        {
            for (j = 0; j < new_graph[i].size(); j++)
                cout << new_graph[i][j] << " ";
            cout << endl;
        }*/
        for (i = 0; i < tmp; i++)
        {
            for (j = 0; j < tmp; j++)
                used[j] = 0;
            if (try_kuhn(i)) rez++;
        }
       // for (i = 0; i < tmp; i++)
       //     cout << mt[i] << " ";
       // cout << endl;
    }
    cout << rez/2 << endl;
    return 0;
}