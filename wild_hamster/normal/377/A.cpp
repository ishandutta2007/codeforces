#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 5000
#define NN 25000000
vector <ll> lal;
ll z,i,j,m,n,k,a[505][505],b[15],x,y,x1,x2,y1,y2;
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}
void dfs(int x, int y)
{
     if (z == n*m-x1-k) return;
     if (a[x][y] == 0)
     {
      a[x][y] = 2;
      z++;
     } else return;
     dfs(x+1,y);
     dfs(x-1,y);
     dfs(x,y-1);
     dfs(x,y+1);
}
int main()
{
string s;
ll rez = 0;
cin >> n >> m >> k;
for (i = 0; i <= n+1; i++)
    for (j = 0; j <= m+1; j++)
        a[i][j] = 1;
char c;
for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    {
        cin >> c;
        if (c == '.') 
        {
           a[i][j] = 0;
           x = i;
           y = j;
        } else x1++;
    }      
z = 0;
dfs(x,y);
for (i = 1; i <= n; i++)
{
    for (j = 1; j <= m; j++)
        if (a[i][j] == 2) cout << '.';
        else
        if (a[i][j] == 1) cout << '#';
        else cout << 'X';
    cout << endl;
}
return 0;
}