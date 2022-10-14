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

ll n,i,j,k,x,y,a[200][200],locked[200],cells[200],used[200],m,k1,k2;
string s;
int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            //cout << j << " " << i << endl;
           // cout << locked[j] << endl;
        if (a[j][i] == 0)
           continue;
        if (locked[j] == 0)
        {
         if (cells[a[j][i]] > 0 || cells[a[j][i]] == -1)
         {
            locked[j] = i+1;
            if (cells[a[j][i]] != -1) locked[cells[a[j][i]]-1] = i+1;
            cells[a[j][i]] = -1;
         } else
         {
           cells[a[j][i]] = j+1;
         }
        }
        }
        for (j = 1; j <= k; j++)
        {
            if (cells[j] != -1)
               cells[j] = 0;
           // cout << cells[j] << " ";
        }
        //cout << endl;
    }
    for (j = 0; j < n; j++)
        cout << locked[j] << endl;
    return 0;
}