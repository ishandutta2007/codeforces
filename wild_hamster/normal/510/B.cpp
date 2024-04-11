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
ll n,i,j,d,x,y,m,len,l,r,sum,used[1005][1005],flag,k1,k2,k;
char a[1005][1005];
void dfs(int x, int y, char c, int nap)
{
if (used[x][y])
{
    flag = 0;
   return; 
}
used[x][y] = 1;
if (a[x+1][y] == c && nap != 1) dfs(x+1,y,c,3);
if (a[x][y+1] == c && nap != 2) dfs(x,y+1,c,4);
if (a[x-1][y] == c && nap != 3) dfs(x-1,y,c,1);
if (a[x][y-1] == c && nap != 4) dfs(x,y-1,c,2);
}
int main()
{
    cin >> n >> m;
   flag = 1; 
   for (i = 0; i< n; i++)
  { 
      for (j = 0; j < m; j++)  
     cin >> a[i][j];
    } 
   for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
  
         if (!used[i][j])
        { 
        dfs(i,j,a[i][j],-1);    
       if (flag == 0)
          {
             cout << "Yes" << endl;
            return 0;  
         }   
       } 
      cout << "No" << endl; 
     return 0;
}