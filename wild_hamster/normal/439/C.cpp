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
ll a[100500],oddeven[100500],c[300],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector<ll> evens[100500],odds[100500];
int main()
{
    cin >> n >> k >> p;
    ll cntodd = 0;
    ll cnteven = 0;
    ll cntoe = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]%2 == 1)
        {
         if (cntodd < k-p)
            odds[cntodd++].push_back(a[i]);
         else
            oddeven[cntoe++] = a[i];
        } else
        evens[cnteven++].push_back(a[i]);
    }
    //cout << cntoe << " " << cntodd << " " << cnteven << endl;
    if (cntoe%2 == 1||cntodd < k-p||cntoe/2+cnteven < p)
       cout << "NO" << endl;
    else
    {
        for (i = cnteven; i < cnteven+cntoe/2; i++)
            {
                 j = i-cnteven;
                 evens[i].push_back(oddeven[j*2]);
                 evens[i].push_back(oddeven[j*2+1]);
            }        
        for (i = p; i < n; i++)
            if (evens[i].size() == 0) break;
               else
                   for (j = 0; j < evens[i].size(); j++)
                       if (p == 0) odds[0].push_back(evens[i][j]);
                          else evens[0].push_back(evens[i][j]);
        cout << "YES" << endl;
        for (i = 0; i < k-p; i++)
        {
            cout << odds[i].size() << " ";
            for (j = 0; j < odds[i].size(); j++)
                cout << odds[i][j] << " ";
            cout << endl;
        }
        for (i = 0; i < p; i++)
        {
            cout << evens[i].size() << " ";
            for (j = 0; j < evens[i].size(); j++)
                cout << evens[i][j] << " ";
            cout << endl;
        }
    }
   return 0;
}