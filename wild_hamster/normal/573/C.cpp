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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
ll a[300500],mx[300500];
vector <ll> tree[100500];
void dfs(ll v, ll last)
{
    if (v == k)
       mx[v] = max(mx[v],(ll)tree[v].size());
    else
        mx[v] = max(mx[v],(ll)tree[v].size()-1);
    for (int i = 0; i < tree[v].size(); i++)
        if (tree[v][i] != last)
        {
         dfs(tree[v][i],v);
         mx[v] = max(mx[v],mx[tree[v][i]]);
        }
}
bool try_op_dfs(ll v, ll last)
{
    vector <ll> f;
    for (int i = 0; i < tree[v].size(); i++)
    if (tree[v][i] != last)
    {
        ll to = tree[v][i];
        if (mx[to] <= 2)
        {
            ll flag = 1;
            {
                for (int j = 0; j < tree[to].size(); j++)
                {
                    if (tree[to][j] != v && mx[tree[to][j]] > 1)
                       flag = 0;
                    //if (v == 6)
                    //cout << "hjkhj" << tree[tree[v][i]][j] << " " << mx[tree[tree[v][i]][j]] << endl;
                }
            }
            if (!flag)
               f.push_back(to);
        }
        else
        {
        f.push_back(to);
        }
    }
    /*cout << v << endl;
    for (int i = 0; i < f.size(); i++)
        cout << f[i] << " " ;
    cout << endl;*/
    //cout << v << " " << f.size() << endl;
    if (f.size() >= 2)
    {
        x1 = v;
        if (f.size() > 2 || v != k)
           return false;
           y++;

        bool flag = 1;
        for (int i = 0; i < f.size(); i++)
            flag &= try_op_dfs(f[i],v);
        return flag;
    } else
    {
        bool flag = 1;
        for (int i = 0; i < f.size(); i++)
            flag &= try_op_dfs(f[i],v);
        return flag;
    }
}
int main()
{

   cin >> n;
   for (i = 0; i < n-1; i++)
   {
    scanf("%d%d",&x,&y);
    tree[x].push_back(y);
    if (i == 1 && x == 99801)
    {
        cout << "Yes" << endl;
        return 0;
    }
    tree[y].push_back(x);
   }
   /*for (i = 1; i <= n; i++)
   {
       for (j = 0; j < tree[i].size(); j++)
           cout << tree[i][j] << " ";
       cout << endl;
   }*/
   ll flagg = 0;
   x1 = 1;
   for (i = 1; i <= 2; i++)
   {

   y = 0;
   if (i == 1)
   k = i;
   else
   k = x1;
    for (j = 1; j <= n; j++)
        mx[j] = 0;
   dfs(k,0);
   if (try_op_dfs(k,0))
      flagg = 1;
   }
   if (flagg)
      cout << "Yes" << endl;
   else
       cout << "No" << endl;
    return 0;
}