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
ll x,y,w,l,r,i,j,n,t,k,k1,k2,d,m,q,dr;
char pushed[2005][2005];
string c[2005];
stack <pair<ll,ll> > dniwe;
bool is_bad(ll x, ll y)
{
 if (x < 0 || y < 0 || x >= n || y >= m) return false;
 if (x > 0 && y > 0)
 {
  if (c[x][y-1] == '.'&&c[x-1][y] == '.'&&c[x-1][y-1] == '.')
     return true;
 }
 
 if (x > 0 && y < m-1)
 {
  if (c[x][y+1] == '.'&&c[x-1][y] == '.'&&c[x-1][y+1] == '.')
     return true;
 }
 
 if (x < n-1 && y > 0)
 {
  if (c[x][y-1] == '.'&&c[x+1][y] == '.'&&c[x+1][y-1] == '.')
     return true;
 }
 
 if (x < n-1 && y < m-1)
 {
  if (c[x][y+1] == '.'&&c[x+1][y] == '.'&&c[x+1][y+1] == '.')
     return true;
 }
 return false;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> c[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (is_bad(i,j) && c[i][j] == '*')
            {
             dniwe.push(mp(i,j));
             pushed[i][j] = 1;
            }
    while (!dniwe.empty())
    {
     pair<ll,ll> tmp = dniwe.top();
     dniwe.pop();
     c[tmp.first][tmp.second] = '.';
     for (i = tmp.first - 1; i <= tmp.first + 1; i++)
         for (j = tmp.second - 1; j <= tmp.second + 1; j++)
             if (i != tmp.first || j != tmp.second)
                if (is_bad(i,j) && c[i][j] == '*' && !pushed[i][j])
                {
                   pushed[i][j] = 1;
                   dniwe.push(mp(i,j));
                }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << c[i][j];
        cout << endl;
    }
    return 0;
}