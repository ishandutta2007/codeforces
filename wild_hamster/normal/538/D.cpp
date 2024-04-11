#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef int ll;
ll i,n,j,k,xo[100500],yo[100500],xx[100500],yx[100500],z,m,l,r,a[228][228];
char res[228][228];
string s;
ll f[2502][102][102];
set <pair<ll,ll> > cool_set, fin;
set <pair<ll,ll> >::iterator itr;
ll b[228][228];
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n;
    ll cnt_x = 0, cnt_o = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == 'o')
            {
               a[i][j] = 2;
               xo[cnt_o] = i;
               yo[cnt_o] = j;
               cnt_o++;
               
               xx[cnt_x] = i;
               yx[cnt_x] = j;
               cnt_x++;
            }
            if (c == 'x')
            {
               a[i][j] = 1;
               xx[cnt_x] = i;
               yx[cnt_x] = j;
               cnt_x++;
            }
        }
    for (i = 0; i < cnt_o; i++)
    {
        ll x_o = xo[i], y_o = yo[i];
        for (j = 0; j < cnt_x; j++)
        {
            ll x_x = xx[j], y_x = yx[j];
            f[i][x_x-x_o+51][y_x-y_o+51] = 1;
            cool_set.insert(mp(x_x-x_o,y_x-y_o));
        }
    }
    /*for (i = 0; i < cnt_o; i++)
    {
        for (itr = f[i].begin(); itr!= f[i].end(); itr++)
        {
        pair <ll,ll> tmp = *itr;
        //cout << i << " " << tmp.first << " " << tmp.second << endl;
        }
    }*/
    for (itr = cool_set.begin(); itr != cool_set.end(); itr++)
    {
        ll flag = 1;
        ll xx = (*itr).first, yy = (*itr).second;
        for (i = 0; i < cnt_o; i++)
            if (f[i][xx+51][yy+51] == 0 && xo[i] + xx >= 0 &&
            xo[i] + xx < n && yo[i] + yy>= 0 && 
            yo[i] + yy < n)
               flag = 0;
        if (flag)
           fin.insert(*itr);
    }
    for (i = 0; i < 2*n-1; i++)
        for (j = 0; j < 2*n - 1; j++)
            res[i][j] = '.';
    res[n-1][n-1] = 'o';
    for (itr = fin.begin(); itr!= fin.end(); itr++)
    {
        pair <ll,ll> tmp = *itr;
        ll xxx = tmp.first, yyy = tmp.second;
        for (i = 0; i < cnt_o; i++)
        {
            if (xo[i] + xxx >= 0 && xo[i] + xxx < n && yo[i] + yyy >= 0 &&
            yo[i] + yyy < n)
            b[xo[i]+xxx][yo[i]+yyy] = 1;
        }
        res[n-1+xxx][n-1+yyy] = 'x';
    }
    ll flag = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if ((a[i][j] == 1 && b[i][j] != 1)|| (a[i][j] < 1 && b[i][j] == 1))   
               flag = 0;
    }
    if (!flag)
    {
     cout << "NO" << endl;
     return 0;
    }
    cout << "YES" << endl;
    res[n-1][n-1] = 'o';
    for (i = 0; i < 2*n-1; i++)
    {
        for (j = 0; j < 2*n - 1; j++)
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}