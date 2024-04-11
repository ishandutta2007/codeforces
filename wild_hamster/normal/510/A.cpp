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
ll n,i,j,d,x,y,m,len,l,r,sum,a[100][105],used[300],flag,k1,k2,k;

void lalka(int x, int y)
{
    int i;
   if (x >= n) return; 
   for (i = 0; i < m; i++)
      a[x][i] = 1;
   if (y == 0)  
  { 
          a[x+1][m-1] = 1;
         a[x+2][m-1] = 1;
        lalka(x+2,m-1);  
  }  else
  { 
          a[x+1][0] = 1;
         a[x+2][0] = 1;
        lalka(x+2,0);  
  } 
}
int main()
{
    cin >> n >> m;
    lalka(0,0);
   for (i = 0; i< n; i++)
  { 
      for (j = 0; j < m; j++)  
     if (a[i][j] == 1) cout << "#";
        else cout << ".";  
       cout << endl; 
    } 
     return 0;
}