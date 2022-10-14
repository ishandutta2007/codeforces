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
ll i,j,n,l,r,rez,k,m,y,z,q,x,a[100500],b[100500][35],t[500500],queries[100500][3];
string s;
void build(ll v, ll fl, ll fr)
{
     if (fl == fr)
     {
        t[v] = a[fl];
        return;
     }
     ll mid = (fl+fr)/2;
     build(v*2,fl,mid);
     build(v*2+1,mid+1,fr);
     t[v] = t[v*2]&t[v*2+1];
}
ll sum(ll v, ll fl, ll fr, ll l, ll r)
{
     if (l > r)
        return ((1<<31)-1);
     if (fl == l && fr == r)
        return t[v];
     ll mid = (fl+fr)/2;
     return sum(v*2,fl,mid,l,min(r,mid))&sum(v*2+1,mid+1,fr,max(l,mid+1),r);
}
int main()
{
    cin >> n >> m;
    for (j = 0; j < m; j++)
    {
        cin >> l >> r >> q;
        queries[j][0] = l-1;
        queries[j][1] = r-1;
        queries[j][2] = q;
        for (i = 0; i < 30; i++)
            if (q&(1<<i))
            {
             b[l-1][i] ++;
             b[r][i] --;
            }
    }
    for (i = 0; i < 30; i++)
        {
             ll tmp = 0;
             for (j = 0; j < n; j++)
             {
                 tmp += b[j][i];
                 if (tmp > 0)
                    a[j]|=(1<<i);
             }             
        } 
    ll flag = 1;
    build(1,0,n-1);
    for (i = 0; i < m; i++)
    {
       l = queries[i][0];
       r = queries[i][1];
       q = queries[i][2];
       //cout << sum(1,0,n-1,l,r) << endl;
       if (sum(1,0,n-1,l,r)!=q) flag = 0;
    }
    if (!flag)
       cout << "NO" << endl;
     else
        {
            cout << "YES" << endl;
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    return 0;
}