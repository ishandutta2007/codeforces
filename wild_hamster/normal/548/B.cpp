#include <omp.h>
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
typedef long long ll;
using namespace std;
ll a[505][505], d[505], x,y,q,globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, r, md;
string s;
bool isp(ll x)
{
    for (int i = 2; i < x; i++)
        if (x%i == 0)
           return false;
    return true;
}
bool pal(string s)
{
    ll n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n-i-1])
           return false;
    return true;
}
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> n >> m >> q;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d",&a[i][j]);
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (j < m)
        {
            ll tmp = 0;
            while (a[i][j] && j < m)
                  j++, tmp++;
            if (tmp > 0)
               d[tmp]++;
            while (!a[i][j] && j < m)
                  j++;
        }
    }
    for (i = 0; i < q; i++)
    {
        scanf("%d%d",&x,&y);
        x--; y--;
        if (a[x][y] == 1)
        {
            a[x][y] = 0;
            r = y+1;
            l = y-1;
            while (a[x][r] && r < m)
                  r++;
            while (a[x][l] && l >= 0)
                  l--;
            r = r-y-1;
            l = y-l-1;
            if (r == 0 && l == 0)
               d[1]--;
            else
            if (r == 0)
               d[l+1]--,d[l]++;
            else
            if (l == 0)
               d[r+1]--,d[r]++;
            else
                d[l+r+1]--,d[l]++,d[r]++;
        } else
        {
            a[x][y] = 1;
            r = y+1;
            l = y-1;
            while (a[x][r] && r < m)
                  r++;
            while (a[x][l] && l >= 0)
                  l--;
            r = r-y-1;
            l = y-l-1;
            if (r == 0 && l == 0)
               d[1]++;
            else
            if (r == 0)
               d[l+1]++,d[l]--;
            else
            if (l == 0)
               d[r+1]++,d[r]--;
            else
                d[l+r+1]++,d[l]--,d[r]--;
        }
        for (j = m; j >= 1; j--)
        {
            if (d[j] > 0)
            {
                break;
            }
        }
        printf("%d\n",j);
    }
    return 0;
}