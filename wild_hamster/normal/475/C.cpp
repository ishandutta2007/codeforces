#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[1005][1005],n,m,j,totsum,p,k1,l,r,k2,k3,k,i,x,y,li,lj,ri,rj,cur,rez;
ll sumsi[1005],sumsj[1005];
string s1,s2;
vector <ll> graph[1000];
pair<ll,ll> hor[1005],hor1[1005],ver[1005];
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'X') 
            {
             a[i][j] = 1;
             if (!k)
                li = i, lj = j;
             k = 1;
             ri = i; rj = j;
             totsum++;
            }
             else a[i][j] = 0;
        }
    ll sum = 0;
    for (i = li; i <= ri; i++)
        for (j = lj; j <= rj; j++)
            sum += a[i][j];
           ll z = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if ((i > ri || i < li || j > rj || j < lj)&&a[i][j] == 1)
               z = 0;
    if (!z)
    {
       cout << -1 << endl;
       return 0;
    }
    for (i = 0; i <= ri-li; i++)
        for (j = 0; j <= rj-lj; j++)
            a[i][j] = a[i+li][j+lj];
    n = ri-li+1;
    m = rj-lj+1; 
    if (sum == (ri-li+1)*(rj-lj+1) && sum == totsum)
       cout << min(ri-li+1,rj-lj+1) << endl;
    else
    {
        ll z = 1;
        for (i = 0; i < n; i++)
        {
            k = 0; ll tmp = 0;
            ll left1 = n; ll right1 = 0;
            ll tmpsum = 0;
            for (j = 0; j < m; j++)
                tmpsum += a[i][j];
            if (tmpsum == 0) z = 0;
            for (j = 0; j < m; j++)
            {                
                if (a[i][j] == 1)
                {
                 if (k == 0 || tmp == 1)
                 {
                 tmp = 1;
                 if (!k) left1 = j;
                 k = 1;
                 right1 = j;
                 } else
                 z = 0;
                } else
                tmp = 0;
            }
            if (i > 0 && (left1 < hor[i-1].first||right1 < hor[i-1].second)) z = 0;            
            hor[i] = mp(left1,right1);
        }
        for (i = 0; i < n-1; i++)
                if (hor[i].second < hor[i+1].first) 
                {
                z = 0;
                }
        if (!z) 
        {
            cout << -1 << endl;
            return 0;
        }
        rez = 1;
        
        
        z = 1;
        for (j = 0; j < m; j++)
        {
            k = 0; ll tmp = 0;
            ll left1 = m; ll right1 = 0;
            ll tmpsum = 0;
            for (i = 0; i < n; i++)
               tmpsum+=a[i][j];
            if (tmpsum == 0) z = 0;
            for (i = 0; i < n; i++)
            {                
                if (a[i][j] == 1)
                {
                 if (k == 0 || tmp == 1)
                 {
                 tmp = 1;
                 if (!k) left1 = i;
                 k = 1;
                 right1 = i;
                 } else
                 z = 0;
                } else
                tmp = 0;
            }
            if (j > 0 && (left1 < hor1[j-1].first||right1 < hor1[j-1].second)) z = 0;            
            hor1[j] = mp(left1,right1);
        }
        for (i = 0; i < m-1; i++)
                if (hor1[i].second < hor1[i+1].first) 
                {
                z = 0;
                }
        if (!z) 
        {
            cout << -1 << endl;
            return 0;
        }
        rez = n*m;
       /* for (int i1 = 0; i1 < m; i1++)
             cout << hor1[i1].first << " " << hor1[i1].second << endl;
             cout << endl;
        for (int i1 = 0; i1 < n; i1++)
            cout << hor[i1].first << " " << hor[i1].second << endl;
                         cout << endl;*/
        for (i = 1; i < n; i++)
            {
                 j = (totsum - m*i)/(n-i);
//                 cout << i << " " << j << endl;
                 if (j >= 1 && j <= m && j*(n-i) == (totsum-m*i))
                 {
                  z = 1;
                     for (int i1 = 0; i1 < m-1; i1++)
                         if (hor1[i1].second - i+1 < hor1[i1+1].first) z = 0;  
                     for (int i1 = 0; i1 < n-1; i1++)
                         if (hor[i1].second - j+1 < hor[i1+1].first) z = 0; 
                  if (z) rez = min(rez,i*j);
                 }
             }
                    
    if (rez < n*m)
    cout << rez << endl;
         else
         cout << -1 << endl;
    }
    
   return 0;
}